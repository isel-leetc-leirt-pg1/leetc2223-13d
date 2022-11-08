#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define NAME_SIZE 32
#define NLETTERS ( 'Z' - 'A' + 1)


/**
 * função respescada de exercícios anteriores para ler uma linha 
 * do input, descartando carateres a mais
 * (que não caibam no array "line")
 */
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
 


/*
 * Esta função produz no array "histo" uma contagem de todas as letras 
 * presentes no ficheiro de nome "filename"
 * Assume-se que todos os elementos do array "histo" estão a zero
 * no início da função
 */
bool histo_generator(const char filename[], int histo[NLETTERS]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return false;
    
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            c = toupper(c); // conversão para maiuscula
            histo[c - 'A' ]++;
        }
    }
    
    fclose(file);
    return true;
}


/*
 * Apresenta para cada letra uma sequência de asteriscos da dimensão
 * do número de ocorrências da letra no array "histo"
 * Esta apresentação não é interessante se as letra tiverem um número de 
 * ocorrências elevedo. Experimentem com o ficheiro dud_en.txt presente
 * nesta pasta
 */
void histo_show(int histo[NLETTERS]) {
    for (int lpos=0; lpos < NLETTERS; lpos++) {
        
        // mostrar a contagem da letra associada à posição "lpos"
        printf("%c: ", lpos + 'A');
        
        for(int i=0; i < histo[lpos]; ++i) 
            putchar('*');
        putchar('\n');
    }
}



int main() {
    int counters[NLETTERS] = { 0 }; // counters iniciado com zeros
    
    
    
    char filename[NAME_SIZE];
    
    printf("file? ");
    readline(filename, NAME_SIZE);
    
    // processar o ficheiro de texto
    if (!histo_generator(filename, counters)) {
        printf("erro ao abrir o ficheiro %s\n", filename);
        return 1;
    }
    
    // mostra o histograma
    
    histo_show(counters);
    
    return 0;
}
