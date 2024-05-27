#include<stdlib.h>
#include<stdio.h>

struct NODE {
        struct NODE* left;
        struct NODE* right;
        int cargo;
} typedef Node;


void append(Node** ppt, int cargo) {

	Node* pt = *ppt;

	if (pt == NULL) {
		pt = malloc(sizeof(Node));
		pt->cargo = cargo;
		pt->left = NULL;
		pt->right = NULL;
		*ppt = pt;
		return;
	}

	if (cargo < pt->cargo) {
		append(&(pt->left), cargo);
	} else {
		append(&(pt->right), cargo);
	}
}


void release(Node* pt) {

	if (pt == NULL) {
		return;
	}

	release(pt->left);
	release(pt->right);

	free(pt);
}


void display_tree(Node* pt, int indent) {

	if (pt == NULL) {
		return;
	}

	int i;
	for (i=0; i<indent; i++) {
		printf(" ");
	}

	printf("%d\n", pt->cargo);
	display_tree(pt->left, indent + 1);
	display_tree(pt->right, indent + 1);

}


void display_sorted(Node* pt) {
	if (pt == NULL) {
		return;
	}
	display_sorted(pt->left);
	printf("%d\n", pt->cargo);
	display_sorted(pt->right);
}
