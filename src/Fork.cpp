#include "Fork.h"

Fork::Fork(int ID)
{
    this->ID = ID;
}

Fork::~Fork()
{
    //dtor
}

bool Fork::Take(){

    return lock.try_lock();

}


void Fork::Release(){

    lock.unlock();

}

int Fork::getID(){

    return ID;

}