#include <stdio.h>
#include <ctype.h> 

typedef enum {INICIO, Q1, FINAL} Estado;

Estado reconocerNumero(const char *inputString );
char tabla[3][3] = {
//  Digito  Coma  Otro 
     { 0,     0,    2     }, //inicio
     { 1,     0,    2     }, //Q1
     { 1,     0,    2     }, //Fin
};


int main(){
    printf("Programa qeu reonoce si un string es un numero decimal");
    FILE* texto;
    texto = fopen("LIBROS.DAT", "rb");
    int caracter;
    while(caracter=(fgetc(texto))!=EOF){
        if(texto){
            
        }
    }

    fclose(texto);
    return 0;
}