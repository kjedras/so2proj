#include "Draw.h"
#include <ncurses.h>

using namespace std;

Draw::Draw(int number, Philosopher **philo, Fork **fork)
{

    this->number=number;
    this->philo=philo;
    this->fork=fork;

    initscr();
    noecho();

}

Draw::~Draw()
{
    endwin();
}

void Draw::start(){
    int x;
    nodelay(stdscr, TRUE);
    clear();

    while((x = getch())!='q'){
        for(int i=0; i<number; i++){

            mvprintw(i+1,0,philo[i]->getName().c_str());
            mvprintw(i+1,10,"ate");
            mvprintw(i+1,14,to_string(philo[i]->getEatCount()).c_str());
            mvprintw(i+1,17,"times, slept");
            mvprintw(i+1,30,to_string(philo[i]->getThinkCount()).c_str());
            mvprintw(i+1,33,"times, currently:");
            
            switch(philo[i]->getState())
            {
                case State::eating:
                    mvprintw(i+1,51,"eating");
                    break;
                case State::thinking:
                    mvprintw(i+1,51,"sleeps");
                    break;
            }
            
        }
        refresh();

        usleep(10000);
    }
}