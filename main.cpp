#include "send.h"

int main(int argc, char const *argv[]) {
    char * a = const_cast<char*>(argv[1]);
    char * b = const_cast<char*>(argv[2]);
    char * c = const_cast<char*>(argv[3]);
    printf("%s\t%s\n%s\t%s\n%s\t%s\n",
           "ARCHIVO A ENVIAR:",a,"IP:",b,"PUERTO:",c);
    send(a,b,argc);
    return 0;
}
