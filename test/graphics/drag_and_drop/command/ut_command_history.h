#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/macro_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"
#include "./mock_command.h"

TEST(CommandHistoryTest, getHistoryShouldBeCorrect)
{
    CommandHistory commandHistory;
    MockDragAndDrop mockDragAndDrop;
    Command *command;

    commandHistory.addCommand(new DropCommand(&mockDragAndDrop, &commandHistory));
    commandHistory.beginMacroCommand();
    commandHistory.addCommand(new GrabCommand(&mockDragAndDrop, &commandHistory));
    commandHistory.addCommand(new MoveCommand(&mockDragAndDrop, &commandHistory));
    commandHistory.addCommand(new DropCommand(&mockDragAndDrop, &commandHistory));
    commandHistory.endMacroCommand();
    commandHistory.addCommand(new MoveCommand(&mockDragAndDrop, &commandHistory));

    std::stack<Command *> history = commandHistory.getHistory();

    ASSERT_TRUE(dynamic_cast<MoveCommand *>(history.top()) != nullptr);
    history.pop();
    ASSERT_TRUE(dynamic_cast<MacroCommand *>(history.top()) != nullptr);
    history.pop();
    ASSERT_TRUE(dynamic_cast<DropCommand *>(history.top()) != nullptr);
}

TEST(CommandHistoryTest, getHistoryShouldBeCorrectAfterGrabAndDropCommandExecute)
{
    CommandHistory commandHistory;
    MockDragAndDrop mockDragAndDrop;

    GrabCommand *grabCommand = new GrabCommand(&mockDragAndDrop, &commandHistory);
    DropCommand *dropCommand = new DropCommand(&mockDragAndDrop, &commandHistory);
    grabCommand->execute();
    dropCommand->execute();

    std::stack<Command *> history = commandHistory.getHistory();
    std::vector<Command *> commands = history.top()->getCommands();

    ASSERT_TRUE(dynamic_cast<MacroCommand *>(history.top()) != nullptr);
    ASSERT_TRUE(dynamic_cast<GrabCommand *>(commands.at(0)) != nullptr);
    ASSERT_TRUE(dynamic_cast<DropCommand *>(commands.at(1)) != nullptr);

    delete grabCommand;
    delete dropCommand;
}

TEST(CommandHistoryTest, undoShouldBeCorrect)
{
    CommandHistory commandHistory;
    MockCommand *mock1 = new MockCommand();
    MockCommand *mock2 = new MockCommand();
    MockCommand *mock3 = new MockCommand();
    MockCommand *mock4 = new MockCommand();

    commandHistory.addCommand(mock1);
    commandHistory.addCommand(mock2);
    commandHistory.addCommand(mock3);
    commandHistory.addCommand(mock4);

    commandHistory.undo();
    commandHistory.undo();
    commandHistory.undo();

    ASSERT_TRUE(mock4->isUndoCalled());
    ASSERT_TRUE(mock3->isUndoCalled());
    ASSERT_TRUE(mock2->isUndoCalled());
    ASSERT_FALSE(mock1->isUndoCalled());
}