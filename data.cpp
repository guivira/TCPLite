#include "data.h"

Data::Data(char * name_file, char * ip, int puerto)
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
}
