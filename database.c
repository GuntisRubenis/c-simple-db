#include <stdio.h>
#include <stdlib.h>
#include "part.h"



int main (void){

struct part *inventory = NULL;
char opp;

for (;;){

    printf("Enter operation (i,u,s,d,p,q): ");
    scanf(" %c", &opp);

    switch (opp){

        case 'i':
            add_part(&inventory);
            printf("\n");
            break;
        case 'p':
            print_parts(inventory);
            printf("\n");
            break;
        case 'u':
            update_part(inventory);
            printf("\n");
            break;
        case 'd':
            delete_part(&inventory);
            printf("\n");
            break;
        case 's':
            int number;

            printf("Enter part number: ");
            scanf("%d", &number);
            flush_buffer();
            struct part *part;
            part = find_part(inventory, number);

            if(part != NULL){
                printf("Number\tName\tQuantity\n");
                printf("%d\t%s\t%d\n", part->number, part->name, part->quantity);
            }
            else{
                printf("Part %d not found\n", number);
            }
            
            
            printf("\n");
            break;
        case 'q':
            while (inventory != NULL) {
                struct part *temp = inventory;
                inventory = inventory->next;
                free(temp);
            }
            return 0;
        default:
            printf("Invalid operation %c\n", opp);
            break;

    }

   }

}
