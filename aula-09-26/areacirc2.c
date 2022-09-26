/*************************************
 * this program evaluates the area of a circle given its radius
 * 
 * written by: Jorge Martins
 * creation date: 26/09/2022
 * 
 *************************************/
 
 

#include <stdio.h>
 

int main() {
    float radius, pi = 3.1415, area;
    
    printf("raio do círculo? ");
    
    scanf("%f", &radius);
    
    area = pi * radius * radius;
    
    printf("área do círculo de raio %f = %f\n", radius, area);
    
    return 0;
    
}
