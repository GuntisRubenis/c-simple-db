#ifndef PART_H
#define PART_H


struct part;

void add_part(struct part **list);
void delete_part(struct part *list, int number);
void update_part(struct part *list, int number, int quantity);
void print_parts(struct part *list);

struct part *find_part(struct part *list, int number);



#endif 
