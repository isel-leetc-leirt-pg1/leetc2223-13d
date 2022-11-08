#include <stdio.h>
#include <string.h>
#include <stdbool.h>


/*
 * embora uma função equivalente exista na biblioteca de funções da 
 * linguagem C (strstr)
 * estamos a usar a versão reaçlizada em aula cuja implementação está 
 * presente no ficheiro strings.c
 * Daí a necessidade de colocar aqui a assinatura da função para o 
 * compilador não se queixar
 * 
 * Para produzir o programa executável temos de escrever o comando:
 * 
 * gcc -o mygrep -Wall mygrep.c strings.c
 * 
 */
int mstrstr(const char line[], const char pattern[]);

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



#define MAX_FILE_NAME 128
#define MAX_WORD 20
#define MAX_LINE 256


/**
 * lê e processa as linhas do ficheiro de texto de nome "name"
 */
bool grep_file(const char name[], const char pattern[]) {
    FILE *fin = fopen(name, "r");
    if (fin == NULL) return false;
    char line[MAX_LINE];
    int lnum = 1;
    
    while (fgets(line, MAX_LINE, fin) != NULL) {
        if (mstrstr(line, pattern) != -1) { // pattern encontrado na linha
            printf("%d: %s", lnum, line);
        }
        lnum++;
    }
    fclose(fin);
    
    return true;
}

int main() {
    char word[MAX_WORD];
    char filename[MAX_LINE];
    
    printf("indique a palavra a procurar: ");
    readline(word, MAX_WORD);
    
    printf("indique o nome do ficheiro: ");
    readline(filename, MAX_FILE_NAME);
    
    if (!grep_file(filename, word)) {
        printf("erro ao processar o ficheiro %s\n", filename);
        return 1;
    }
    
    return 0;
    
}








