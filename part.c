#include "part.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>



void flush_buffer(void){
    
    while(getchar()!='\n');
}

void read_line(char arr[], int len){
    char ch;
    int i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < len)
            arr[i++] = ch;
    }
    arr[i] = '\0';
}




void add_part(struct part **list){
    
    struct part *curr = *list, *prev = NULL;

    int quantity, number;
    char name[NAME_L+1];
    struct part *new_part;
    
    printf("Enter part number: ");
    scanf("%d", &number);
    flush_buffer();
    
    if(find_part(*list, number) != NULL){

        printf("Part with number %d already exists\n", number);
        return;
    }

    printf("Enter part name: ");
    read_line(name, NAME_L);

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    flush_buffer();

    new_part = malloc(sizeof(struct part));
    
    if (new_part == NULL){
        printf("Error allocating space in add_part\n");
        exit(EXIT_FAILURE);

    }


    new_part->number = number;
    new_part->quantity = quantity;
    strcpy(new_part->name, name);
    new_part->next = NULL;

    for (; curr != NULL && curr->number < number; prev = curr, curr = curr->next)
        ;
    
    if (prev == NULL){
        new_part->next = *list;
        *list = new_part;
    }
    else {

        new_part->next = curr;
        prev->next = new_part;
    }

}

void delete_part(struct part **list){
    
    int number;
    printf("Enter part number: ");
    scanf("%d", &number);
    flush_buffer();

    struct part *curr = *list, *prev = NULL;

    for ( ;curr != NULL && curr->number != number; prev = curr, curr = curr->next)
        ;
   
    if (curr == NULL){
        printf("Part with number %d is not found\n", number);
        return;
    }
    else if (curr != NULL && prev == NULL && curr->next == NULL){
        free(*list);
        *list = NULL;    
    }
    else if( curr != NULL && prev == NULL && curr->next != NULL){
        *list = curr->next;
        free(curr);

    }
    else {
        prev->next = curr->next;
        free(curr);
        
    }
}

void update_part(struct part *list){
    int number;
    char ch;

    printf("Enter part number: ");
    scanf("%d", &number);
    flush_buffer();
    struct part *part = find_part(list, number);
    
    if (part == NULL){
        printf("Part with number %d not found\n", number);
        return;
    }
    else{
        printf("Update part name?(y/n):");
        ch = getchar();
        flush_buffer();
        switch(ch){
            case 'y':
                char name[NAME_L+1];
                printf("Enter new part name: ");
                read_line(name, NAME_L+1);
                flush_buffer();
                strcpy(part->name, name);
                break;
            case 'n':
                break;
            default:
               printf("Invallid operation");
                break;

        }
        
        printf("Update part quantity?(y/n):");
        ch = getchar();
        flush_buffer();
        switch(ch){
            case 'y':
                int quantity;
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                flush_buffer();
                part->quantity = quantity;
                break;
            case 'n':
                break;
            default:
                printf("Invallid operation");
                break;

        }


    } 
}

void print_parts(struct part *list){
    printf("Number\tName\tQuatity\n");
    while (list != NULL){
        printf("%d\t%s\t%d\n", list->number, list->name, list->quantity);
        list = list->next;
   }
   flush_buffer();
}

struct part *find_part(struct part *list, int number){

    while (list != NULL){
        
        if(list->number == number){
            return list;
        }

        list = list->next;
    }

    return NULL;
}
