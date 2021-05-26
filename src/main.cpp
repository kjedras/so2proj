#include <iostream>
#include "Fork.h"
#include "Philosopher.h"
#include "Draw.h"
#include <thread>
#include <mutex>
#include <unistd.h>
#include <atomic>
#include <chrono>
#include <ctime>
#include <ncurses.h>

using namespace std;

void LifeCycle(Philosopher* philo, std::atomic<bool>& run){

    while(run){

        philo->Think();
        philo->Eat();

    }
}


int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);
	int time = atoi(argv[2]);
	chrono::milliseconds timer(time);
	timer = timer + (chrono::milliseconds)(rand() % 41 - 20) * time / 100;
    thread *threads = new thread[number];
    Fork *fork[number];
    Philosopher *philo[number];
    std::atomic<bool> run(true);
    for (int i=0; i<number; i++){

        fork[i] = new Fork(i);

    }

    for (int i=0; i<number; i++){

        philo[i] = new Philosopher(i, "Filozof " + to_string(i+1), timer);

        philo[i]->Right(fork[i]);
		if (i == 0)
			philo[i]->Left(fork[number-1]);
		else
			philo[i]->Left(fork[i-1]);

        threads[i] = thread(LifeCycle, philo[i], std::ref(run));

    }

	Draw draw = Draw(number, philo, fork);
	draw.start();

    run = false;

    for(int i=0; i<number; i++){

        threads[i].join();

    }
    
    return 0;
}