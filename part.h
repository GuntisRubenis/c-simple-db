#ifndef PART_H
#define PART_H

#define NAME_L 20

struct part {

    struct part *next;
    //struct part *prev;

    int number;
    char name[NAME_L + 1];
    int quantity;


};

void flush_buffer(void);
void add_part(struct part **list);
void delete_part(struct part **list);
void update_part(struct part *list);
void print_parts(struct part *list);

struct part *find_part(struct part *list, int number);



#endif 
