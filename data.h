#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <semaphore.h>
#include <cstdlib>
#include "window.h"

class Data{
public:
    /*VARIABLES PÚBLICAS*/
    char ip[15];
    char nama_file[40];
    char * dat;
    int f_len;
    int puerto;
    FILE * fd;
    bool int_in_use = true;
    bool int_fill = false;
    sem_t hl_semaphore;
    sem_t int_semaphore;
    Window * wndw;

    /*MÉTODOS PÚBLICOS*/
    Data(char * name_file, char * ip, int puerto, int frame_len, int w_len);
    ~Data();
};

#endif // DATA_H
