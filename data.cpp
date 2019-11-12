#include "data.h"

Data::Data(char * name_file, char * ip, int puerto, int frame_len, int w_len)
{
    for(int i = 0; i<15; i++){
        this->ip[i] = ip[i];
    }
    fd = fopen(name_file,"rb");
    if(fd==nullptr){
        printf("%s\t%s\n", "ERROR AL ABRIR EL ARCHIVO:",name_file);
        exit(EXIT_FAILURE);
    }
    printf("%s\t%s\n", "SE ABRIÓ CON ÉXITO EL ARCHIVO:",name_file);
    this->puerto = puerto;
    wndw = new Window(w_len, frame_len, 0);
    printf("%s\n", "MEMORIA COMPARTIDA CREADA");
}

Data::~Data(){
    delete wndw;
    printf("%s\n","MEMORIA COMPARTIDA DESTRUIDA");
}
