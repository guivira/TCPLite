#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <semaphore.h>
#include <cstdlib>

class Data{
private:
    char ip[15];
    int puerto;
    FILE * fd;
    bool int_in_use = true;
    bool int_fill = false;
    sem_t hl_semaphore;
    sem_t int_semaphore;
public:
    Data(char * name_file, char * ip, int puerto);
};

#endif // DATA_H
