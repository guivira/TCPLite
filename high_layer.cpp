#include "high_layer.h"

High_layer::High_layer(Data * shm_data){
    this->shm_data = shm_data;
    num_package = 0;
}

void High_layer::run(){
    printf("%s\n","ARRANCA LA CAPA SUPERIOR");
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    int f_len = shm_data->f_len;
    unsigned long len_read = 0;
    len_read = fread(shm_data->dat,sizeof(char),static_cast<size_t>(f_len),shm_data->fd);
    while (len_read) {
        sem_wait(&shm_data->hl_semaphore);

        usleep(1);
        if (!shm_data->int_fill) {
            put_int_HL(shm_data->dat);
            shm_data->int_fill = true;
            len_read = fread(shm_data->dat,sizeof(char),static_cast<size_t>(f_len),shm_data->fd);
            truncate(shm_data->dat, len_read);
        }
        usleep(1);

        sem_post(&shm_data->int_semaphore);
    }
    printf("%s\n", "YA SE LEYÓ EL ARCHIVO");
    shm_data->int_in_use = false;
}

int High_layer::put_int_HL(char * dat){
    // se tiene que comprobar que se pudo meter
    if (shm_data->wndw->put(num_package,dat)) {
        num_package++;
        return 1;
    }
    return 0;
}

void High_layer::trucate(char * source, unsigned long len_read){
    unsigned long f_l = static_cast<unsigned long>(shm_data->f_len);
    if (len_read!=f_l) {
        source[len_read] = '\0';
        for (unsigned long i = len_read + 1; i < f_l; i++) {
            source[i] = '\0';
        }
    }
}
