#include<stdlib.h>
#include<stdio.h>

typedef struct NODE {
        struct NODE* left;
        struct NODE* right;
        int cargo;
	int depth;
	int imbalance;
} Node;


int max(int a, int b) {
	if (a>b) { return a; }
	return b;
}

void append(Node** ppt, int cargo) {

	Node* pt = *ppt;

	if (pt == NULL) {
		pt = malloc(sizeof(Node));
		pt->cargo = cargo;
		pt->left = NULL;
		pt->right = NULL;
		pt->depth = 0;
		pt->imbalance = 0;
		*ppt = pt;
		return;
	}

	if (cargo < pt->cargo) {
		append(&(pt->left), cargo);
	} else {
		append(&(pt->right), cargo);
	}

	int rd = 0; int ld = 0;
	if (pt->right) {rd = pt->right->depth;}
	if (pt->left) {ld = pt->left->depth;}
	(pt->depth) = max(rd, ld) + 1;
	(pt->imbalance) = rd - ld;

}


void get_imbalances(Node* pt) {

	if (pt == NULL) {
		return;
	}
	int right = 0;
	int left = 0;


	if (pt->right != NULL) {
		get_imbalances(pt->right);
		right = pt->right->depth + 1;


	}

	if (pt->left != NULL) {
		get_imbalances(pt->left);
		left = pt->left->depth + 1;
	}

	pt->imbalance = right - left;
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


	int i;
	for (i=0; i<indent; i++) {
		printf(" ");
	}

	if (pt == NULL) {
		printf("*\n");
		return;
	}

	printf("%d(%d){%d}\n", pt->cargo, pt->depth, pt->imbalance);

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


Node* get_from_file(char* file_name) {

	Node* tp = NULL;

	char buff[255];
	FILE* fp;
	fp = fopen(file_name, "r");
	while (1 == fscanf(fp, "%s", buff)) {
		append(&tp, atoi(buff));
	}
	return tp;
}


void rot_left(Node** ppt) {

	Node* pt = *ppt;

	if (pt == NULL) { return; }
	if (pt->right == NULL) { return; }


	Node* beta = pt->right->left;
	Node* tmp = pt;
	pt  = pt->right;
	tmp->right = beta;
	pt->left = tmp;
	*ppt = pt;
}


void rot_right(Node** ppt) {

	Node* pt = *ppt;

	if (pt == NULL) { return; }
	if (pt->left == NULL) { return; }

	Node* beta = pt->left->right;
	Node* tmp = pt;
	pt = pt->left;
	tmp->left = beta;
	pt->right = tmp;
	*ppt = pt;
}


void walk(Node* pt) {

	rot_left(&((*pt).right->right));

}

