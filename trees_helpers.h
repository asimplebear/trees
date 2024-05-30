#ifndef TREES_HELPERS_H
#define TREES_HELPERS_H

struct NODE typedef Node;
void append(Node** ppt, int cargo);
void release(Node* pt);
void display_tree(Node* pt, int indent);
void display_sorted(Node* pt);

int max(int a, int b);
//void (Node* pt);


Node* get_from_file(char* file_name);
void rot_right(Node** ppt);
void rot_left(Node** ppt);
void get_imbalances(Node* pt);
void walk(Node** ppt);


#endif
