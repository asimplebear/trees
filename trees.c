#include"trees_helpers.h"
#include<stdlib.h>
#include<stdio.h>



int main() {

	Node* pt = NULL;

	append(&pt, 42);
	append(&pt, 7);
	append(&pt, 99);
	append(&pt, 10);
	append(&pt, 3);
	append(&pt, 1);
	append(&pt, 100);

	display_tree(pt, 0);
	printf("------------\n");
	display_sorted(pt);

	release(pt);

	return 0;
}
