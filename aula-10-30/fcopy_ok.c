/**
 * Programa que copia um ficheiro fonte para um ficheiro destino
 * recolhendo do input standard os nomes do ficheiro origem e do
 * ficheiro destino
 * 
 * utiliza a função readline, definida abaixo, para ler uma linha do
 * input
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
 

/*********************************************************
 * recolhe a linha lida do input standard +ara
 * o array line
 * O caracter '\n' não é colocado em line
 * 
 * No caso da capacidade do array não ser suficiente,
 * o resto da linha é ignorado
 * 
 * Retorno: retorna o total de caracteres recolhido
 ********************************************************/
int readline(char line[], int capacity) {
    int i=0;
    int c;
    
    while(i < capacity - 1 && (c = getchar()) != '\n') {
        line[i] = c;
        i++;  
    }
    line[i] = 0;
    
    // recolher eventuais caracteres até à mudança de linha
    while ( c != '\n') c = getchar();
    
    return i;
}


 
int main() {
    char filename_src[MAX_NAME];
    char filename_dst[MAX_NAME];
    
    printf("ficheiro origem: ");
    readline(filename_src, MAX_NAME);
    
    printf("ficheiro destino: ");
    readline(filename_dst, MAX_NAME);
    
    // "abrir" (obter acesso) ao ficheiro "fcopy.c" para leitura
    FILE *fin = fopen(filename_src, "r");
    if (fin == NULL) {
        printf("erro ao abrir %s\n", filename_src);
        return 1;
    }
    
    // "criar" (e obter acesso) ao ficheiro destino "fcopy_copy.c"
    FILE *fout = fopen(filename_dst, "w+");
    if (fout == NULL) {
        printf("erro ao criar %s\n", filename_dst);
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
    
    
    
    
