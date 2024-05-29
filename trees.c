#include"trees_helpers.h"
#include<stdlib.h>
#include<stdio.h>

/*
void walk(Node** ppt) {

	Node* pt = *ppt;
	if (pt == NULL) {
		return;
	}

	walk(&(pt->left));
	walk(&(pt->right));

	if (pt->imbalance > 2) {
		rot_left(&pt);
	} else if (pt->imbalance < -2) {
		rot_right(&pt);
	}
}
*/




int main(int argc, char** argv) {

	Node* pt = NULL;
	/*
	append(&pt, 42);
	append(&pt, 7);
	append(&pt, 99);
	append(&pt, 10);
	append(&pt, 3);
	append(&pt, 1);
	append(&pt, 100);
	*/
	if (argc == 2) {
		pt = get_from_file(argv[1]);
	} else {
		pt = get_from_file("in.txt");
	}
	get_imbalances(pt);
	display_tree(pt, 0);
	printf("------------\n");
	//rot_right(&pt);
	get_imbalances(pt);
//walk(&pt);
	display_tree(pt, 0);
	printf("+++++++++++++++\n");
	display_sorted(pt);

	release(pt);



	return 0;
}
