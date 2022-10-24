/**
 * Programa que copia um ficheiro pré-determinado (fcopy.c)
 * para um destino pré-determinado (fcopy_copy.c)
 * 
 * Ilustra a utilização das funções básicas para acesso ficheiros:
 * 
 * fopen, fgetc, fputc, fclose
 * 
 * Jorge Martins, outubro de 2022
 */

#include <stdio.h>



int main() {
    // "abrir" (obter acesso) ao ficheiro "fcopy.c" para leitura
    FILE *fin = fopen("fcopy.c", "r");
    if (fin == NULL) {
        printf("erro ao abrir fcopy.c");
        return 1;
    }
    
    // "criar" (e obter acesso) ao ficheiro destino "fcopy_copy.c"
    FILE *fout = fopen("fcopy_copy.c", "w+");
    if (fout == NULL) {
        printf("erro ao criar fcopy_copy.c");
        return 1;
    }
    
    
    // copiar de "fin" para "fout"
    
    int c;
    
    while((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}
    
    
    
    
