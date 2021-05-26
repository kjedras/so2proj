#pragma once

#include "Philosopher.h"

class Draw
{
public:
    int number;
    Philosopher **philo;
    Fork **fork;

    Draw(int number, Philosopher **philo, Fork **fork);
    ~Draw();
    void start();
};