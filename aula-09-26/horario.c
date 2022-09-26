/****************************************************
 * this program presents a given quantity in seconds 
 * on a timetable for: hh:mm:ss
 *
 * written by: JM
 * creation date: 26/09/2022
 ***************************************************/

#include <stdio.h>


int main() {
    
    int nseconds; // the seconds quantity to process
    
    int h, m, s;
    
    int SECS_PER_HOUR = 3600, SECS_PER_MIN = 60;
    
    // read seconds quantity
    printf("indique a quantidade de segundos: ");
    scanf("%d", &nseconds);
    
    // convert seconds quantity to a triple on h, m and s variables
    
    h = nseconds / SECS_PER_HOUR;
    
    //int remaining_secs = nseconds - h* SECS_PER_HOUR;
    // below is the equivalent code of the above line using the remainder operator
    int remaining_secs = nseconds % SECS_PER_HOUR;
    
    m = remaining_secs / SECS_PER_MIN;
    
    //s = remaining_secs - m  * SECS_PER_MIN;
    s = remaining_secs % SECS_PER_MIN;
    
    // present the final day hour formatting the our on traditional digital format
    printf("%02d:%02d:%02d\n", h, m, s);
    
    return 0;

}




