#ifndef HIGH_LAYER_H
#define HIGH_LAYER_H
#include "data.h"
#include <unistd.h>

class High_layer{
private:
    Data * shm_data;
    int num_package;

public:
    High_layer(Data * shm_data);
    void run();
    int put_int_HL(char * dat);
    void trucate(char * source, unsigned long len_read);
};

#endif // HIGH_LAYER_H
