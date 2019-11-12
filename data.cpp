#include "data.h"

Data::Data(char * name_file, char * ip, int puerto, int frame_len, int w_len){
    fd = fopen(name_file,"rb");
    if(fd==nullptr){
        printf("%s\t%s\n", "ERROR AL ABRIR EL ARCHIVO:",name_file);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i<15; i++){
        this->ip[i] = ip[i];
    }
    for(int i = 0; i<40; i++){
        this->nama_file[i] = name_file[i];
    }
    printf("%s\t%s\n", "SE ABRIÓ CON ÉXITO EL ARCHIVO:",name_file);
    this->puerto = puerto;
    wndw = new Window(w_len, frame_len);
    dat = new char[frame_len];
    f_len = frame_len;
    printf("%s\n", "MEMORIA COMPARTIDA CREADA");
    printf("\n\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
}

Data::~Data(){
    delete wndw;
    printf("%s\n","MEMORIA COMPARTIDA DESTRUIDA");
}
