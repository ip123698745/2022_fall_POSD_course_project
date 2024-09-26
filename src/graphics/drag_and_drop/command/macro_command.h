#pragma once

#include "command.h"
#include <vector>
#include <stack>

class MacroCommand : public Command
{
private:
    std::vector<Command *> _commands;
    std::stack<Command *> _history;

public:
    MacroCommand() {}
    ~MacroCommand() {
        for(Command *c : _commands){
            delete c;
        }
    }

    void execute() override {
        for(Command *c : _commands){
            c->execute();
        }
    }

    void addCommand(Command *command) override {
        _commands.push_back(command);
        _history.push(command);
    }

    void undo() override {
        while(!_history.empty()){
            _history.top()->undo();
            _history.pop();
        }
    }

    std::vector<Command *> getCommands() override {
        return _commands;
    }
};