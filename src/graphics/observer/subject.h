#pragma once

#include "observer.h"
#include <vector>

using namespace std;

class Subject
{
private:
    std::vector<Observer *> _observers;

public:
    virtual ~Subject() {}

    void attach(Observer *observer) {
        _observers.push_back(observer);
    }

    void detach(Observer *observer) {
        vector<Observer *> newObservers;
        bool isfound = false;

        for(Observer *o : _observers){
            if(o == observer){
                isfound = true;
                continue;
            }
            else{
                newObservers.push_back(o);
            }
        }

        if(!isfound){
            throw "observer passed-in is not found";
        }

        _observers = newObservers;
    }

    void notify() {
        for(Observer *o : _observers)
        {
            o->update();
        }
    }

    std::vector<Observer *> getObservers() {
        return _observers;
    }
};
