#ifndef TREES_HELPERS_H
#define TREES_HELPERS_H

struct NODE typedef Node;
void append(Node**, int);
void release(Node*);
void display_tree(Node*, intt);
void display_sorted(Node*);
int max(int, int);
Node* get_from_file(char*);
void rot_right(Node**);
void rot_left(Node**);
void get_imbalances(Node*);
void walk(Node*);

#endif
