/**
 * Programa que copia o input standard para o output standard
 * Ilustra a utilização dos DILE* pré-definidos para o input standard (stdin-8 e output standard (stdout)
 * 
 * Jorge Martins, outubro de 2022
 */

#include <stdio.h>



int main() {
   
    FILE *fin = stdin;
    
    FILE *fout = stdout;
    
    
    // copiar de "stdin" para "stdout"
    
    int c;
    
    while((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
    }
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}
    
    
    
    
