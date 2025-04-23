#include <stdio.h>
#include <stdlib.h>
#include "part.h"



int main (void){

struct part *inventory = NULL;
char opp;

for (;;){

    printf("Enter operation (i,u,s,d,p,q): ");
    scanf("%c", &opp);

    switch (opp){

        case 'i':
            add_part(&inventory);    
            break;
        case 'p':
            print_parts(inventory);
            break;
        case 'q':
            return 0;
        default:
            printf("Invalid operation %c\n", opp);
            break;

    }

}

}
