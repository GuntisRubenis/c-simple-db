#include "part.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_L 20

struct part {

    struct part *next;
    //struct part *prev;

    int number;
    char name[NAME_L + 1];
    int quantity;


};

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
    
    while(getchar()!='\n');

    printf("Enter part name: ");
    read_line(name, NAME_L);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    while(getchar()!='\n');

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

void delete_part(struct part *list, int number){

}
void update_part(struct part *list, int number, int quantity){

}
void print_parts(struct part *list){

}

struct part *find_part(struct part *list, int number){

return list;
}

