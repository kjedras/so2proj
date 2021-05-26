#ifndef FORK_H
#define FORK_H

#include <mutex>
#include <unistd.h>

class Fork
{
    public:

        int ID;

        Fork(int ID);
        virtual ~Fork();

        bool Take();
        void Release();
        int getID();
    protected:

    private:
        std::mutex lock;
};

#endif // FORK_H