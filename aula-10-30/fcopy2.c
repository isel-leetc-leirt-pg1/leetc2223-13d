/**
 * Programa que copia um ficheiro fonte para um ficheiro destino
 * recolhendo do input standard os nomes do ficheiro origem e do
 * ficheiro destino
 * Esta solução é fraca pois repete o código de recolha para cada um dos ficheiros.
 * 
 * 
 * Ilustra a utilização das funções básicas para acesso ficheiros:
 * 
 * fopen, fgetc, fputc, fclose
 * 
 * Jorge Martins, outubro de 2022
 */

#include <stdio.h>

#define MAX_NAME 128



int main() {
    char filename_src[MAX_NAME];
    char filename_dst[MAX_NAME];
    int i;
    
    // recolher o nome do ficheiro origem
    printf("ficheiro origem: ");
    i=0;
    int c;
    while(i < MAX_NAME - 1 && (c = fgetc(stdin)) != '\n') {
        filename_src[i] = c;
        i++; //i = i + 1; ++i
    }
    
 
    filename_src[i] = 0; //    // as string têm de terminar com caracter de código 0 
    // recolher eventuais caracteres até à mudança de linha
    while ( c != '\n') c = fgetc(stdin);
    
    // recolher o nome do ficheiro destino
    printf("ficheiro destino: ");
    
    i=0;
    
    while(i < MAX_NAME - 1 && (c = fgetc(stdin)) != '\n') {
        filename_dst[i] = c;
        i++; //i = i + 1; ++i
    }
    filename_dst[i] = 0;
    // recolher eventuais caracteres até à mudança de linha
    while ( c != '\n') c = fgetc(stdin);
    
    
    // "abrir" (obter acesso) ao ficheiro origem para leitura
    FILE *fin = fopen(filename_src, "r");
    if (fin == NULL) {
        printf("erro ao abrir %s\n", filename_src);
        return 1;
    }
    
    // "criar" (e obter acesso) ao ficheiro destino 
    FILE *fout = fopen(filename_dst, "w+");
    if (fout == NULL) {
        printf("erro ao criar %s\n", filename_dst);
        return 1;
    }
    
    
    // copiar de "fin" para "fout"

    while((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}
    
    
    
    
