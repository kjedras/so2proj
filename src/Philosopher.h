#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "Fork.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>
#include <thread>

enum State
{
    eating,
    thinking
};

class Philosopher
{
    public:


        void UnlockForks();
        bool TryLock();
        std::string name;

        int progress;
        int ID;
        State state;
        Fork *forkR;
        Fork *forkL;
        int ecount = 0;
        int tcount = 0;
        std::chrono::milliseconds timer;

        std::string getName();
        void Eat();
        void Think();
        State getState();
        int getProgress();
        void Right(Fork *forkR);
        void Left(Fork *forkL);
        int getEatCount();
        int getThinkCount();
        Philosopher(int ID, std::string name, std::chrono::milliseconds timer);
        virtual ~Philosopher();
    protected:

    private:

};

#endif // PHILOSOPHER_H