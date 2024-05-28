#ifndef TREES_HELPERS_H
#define TREES_HELPERS_H

struct NODE typedef Node;
void append(Node** ppt, int cargo);
void release(Node* pt);
void display_tree(Node* pt, int indent);
void display_sorted(Node* pt);

Node* get_from_file(char* file_name);

void get_imbalances(Node* pt);
#endif
