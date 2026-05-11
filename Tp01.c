#include <stdio.h>
#include <ctype.h> 


#define CENTINELA ','
typedef enum {INICIO, Q1, ERROR} Estado;

Estado reconocerNumero(const char *inputString );
Estado tablaTransiciones[3][3] = { //tabla[estadoActual][Columna]
//  Digito  Coma  Otro 
     { 1,     2,    2     }, //inicio
     { 1,     0,    2     }, //Q1
     { 2,     0,    2     }, //ERROR o palabra no valida
};

void finDeCadena(Estado estado, FILE *salida){
    if (estado == ERROR) {
        fprintf(salida, " Aceptada\n");
    } else {
        fprintf(salida, " Rechazada\n");
    }
}


int verifColumna(int c){ //le asigna el estado que corresponda
    if (isdigit(c)) return 0;
    if (c==',') return 1;
    return 2;
}



void scanner(FILE *entrada, FILE *salida){ //revisa el archivo y envia la salida a la terminal
    int caracter;
    Estado estadoActual = INICIO;
    while((caracter = fgetc(entrada)) != EOF){
        if(caracter != CENTINELA){
            fputc(caracter, salida);
            estadoActual = tablaTransiciones[estadoActual][(verifColumna(caracter))]; //transicion a tabla de transiciones
    } 

    else {
        finDeCadena(estadoActual, salida);
        estadoActual = INICIO;
         }
    }
    finDeCadena(estadoActual, salida)
}




int main(){

    printf("Programa qeu reonoce si un string es un numero decimal");
      int caracter;
      Estado estadoActual = INICIO; //declaro los estados donde se va a mover la palabra
    FILE* texto;
    texto = fopen("prueba.txt", "rb"); 
    
    scanner(texto, stdout); //el scanner revisa el archivo y realiza la salida solicitada por terminal

    fclose(texto);
    return 0;
}