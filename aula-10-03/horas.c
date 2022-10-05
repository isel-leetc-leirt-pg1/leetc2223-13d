#include <stdio.h>

int main() {
    // variáveis
    int hi, mi;     // representa a hora inicial;
    int hd, md;     // duração do evento
    int hf, mf;     // hora final
    
    printf("hora inicial (h m)? ");
    int res = scanf("%d%d", &hi, &mi);
    
    // Em primeiro lugar, validar o input
    if ( res != 2 || hi < 0 || hi > 23 || mi < 0 || mi > 59) {
        printf("hora de início inválida!\n");
        return 1;
    }
    
    printf("duração (h m)? ");
    res = scanf("%d%d", &hd, &md);
    
    // Em primeiro lugar, validar o input
    if ( res != 2 || hd < 0 || hd > 23 || md < 0 || md > 59) {
        printf("duração inválida!\n");
        return 1;
    }
    
    int carry = 0;
    
    mf = mi + md;
    if (mf >= 60) {
        carry = 1;
        mf = mf - 60;
    }
    
    hf = hi + hd + carry;
    
    // notem a noralização n aapresetnação da hora na linha seguinte (h % 24)
    printf("%02d:%02d", hf % 24, mf);
    if (hf >= 24) {
        printf(" do dia seguinte\n");
    }
    printf("\n");
    
    return 0;
}
