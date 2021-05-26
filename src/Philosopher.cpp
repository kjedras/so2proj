#include "Philosopher.h"

#include <cstdlib>
#include <unistd.h>


Philosopher::Philosopher(int ID, std::string name, std::chrono::milliseconds timer)
{
    this->ID = ID;
    this->name = name;
    this->timer = timer;
}

Philosopher::~Philosopher()
{
    //dtor
}

void Philosopher::Right(Fork *forkR){

    this->forkR = forkR;

}

void Philosopher::Left(Fork *forkL){

    this->forkL = forkL;

}

void Philosopher::Eat(){

    do
    if(TryLock()){

    state = eating;
    ecount++;
    std::this_thread::sleep_for(timer);
    UnlockForks();
    
    } while (state != eating);

}

void Philosopher::Think(){

    state = thinking;
    tcount++;
    std::this_thread::sleep_for(timer);

}

void Philosopher::UnlockForks(){

    if (forkL->getID() > forkR->getID()){

		forkL->Release();
		forkR->Release();
        
    } else {

        forkR->Release();
		forkL->Release();

    }

}

bool Philosopher::TryLock(){

    if(forkL->Take()){

        if(forkR->Take()) {return true;}
        else {

            forkL->Release();
            return false;

        }

    } else return false;

}

State Philosopher::getState(){

    return state;

}

std::string Philosopher::getName() {

    return name;

}

int Philosopher::getProgress(){

    return progress;

}

int Philosopher::getEatCount(){

    return ecount;

}

int Philosopher::getThinkCount(){

    return tcount;

}