#ifndef SEND_H
#define SEND_H
#include <stdio.h>
#include "data.h"
#include <signal.h>
#include <cstdlib>
#include <unistd.h> //para poder usar sleep
static Data * shm_data;

void sing_handler(int sing){
  if (sing == SIGINT){
    if (shm_data) {
        delete  shm_data;
        printf("%s\n", "Se cerró el archivo fuente");
    }
    exit(EXIT_FAILURE);
  }
}

/******************************************************************************/
/**
  @brief blind_signal: enlaza la señal SIGINT, con la función sing_handler.

*/
void blind_signal(){
    if (signal(SIGINT, sing_handler) == SIG_ERR){
        printf("\nNo se puede enlazar SIGINT\n");
    }
}

/******************************************************************************/
/**
  @brief send: envía el archivo hacia la ip y el puerto deseado.

  @param name_file: buffer con el nombre de archivo enviar.
  @param ip: buffer con el ip destino.
  @param puerto: buffer con el puerto detino.

  @returns Retorna el si se logró (1) hacer todas las operaciones o no (0)

*/
int send(char * name_file, char * ip, int puerto){
    shm_data = new Data(name_file,ip,puerto);

    delete shm_data;
    return 1;
}


#endif // SEND_H
