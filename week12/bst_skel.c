#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	struct tnode* left;
	char val;
	struct tnode* right;	
} tnode;


typedef struct tree{
	tnode* root;	
} tree;

tnode* newtnode(char);

tree* newtree();

void inorder(tree*);

void preorder(tree*);

void postorder(tree*);

void insert(tree*, tnode* );

int main(int argc, char const *argv[]){
	tree* t = newtree();
	char a[10] = {'G','D','I','B','F','H','J','A','C','E'};
	int i;
	for(i = 0; i<10;i++){
		insert(t, newtnode(a[i]));
	}
	printf("inorder		: ");
	inorder(t);
	printf("\npreorder	:");
	preorder(t);
	printf("\npostorder	:");
	postorder(t);
	printf("\n");
	return 0;
}

tnode* newtnode(char newVal){
	tnode* new_tnode = (tnode*)malloc(sizeof(tnode));
	new_tnode -> left = NULL;
	new_tnode -> val = newVal;
	new_tnode -> right = NULL;
	return new_tnode;
}

tree* newtree(){
	tree* new_tree = (tree*)malloc(sizeof(tree));
	new_tree -> root = NULL;
	return new_tree;
}

void insert(tree* t, tnode* tn){
	if(t -> root == NULL){
		t -> root = tn;
		return;
	}
	tnode* temp = t -> root;
	tnode* parent = t -> root;
	int isLeft = 0;
	while(temp != NULL){
		parent = temp;
		if(tn -> val > temp -> val){
			temp = temp -> right;
			isLeft = 0;
		} 
		else{
			temp = temp -> left;
			isLeft = 1;
		}
	}
	if(isLeft == 0){
		parent -> right = tn;
	}
	else{
		parent -> left = tn;
	}
	
}

void inorder(tree* t){
	if(t == NULL){
		return;
	}
	tree* leftTree = newtree();
	tree* rightTree = newtree();
	leftTree -> root = t -> root -> left;
	rightTree -> root = t -> root -> right;
	if(leftTree -> root != NULL){
		inorder(leftTree);
	}
	printf(" %c ", t -> root -> val);
	if(rightTree -> root != NULL){
		inorder(rightTree);
	}
	free(leftTree);
	free(rightTree);
}

void preorder(tree* t){
	if(t == NULL){
		return;
	}
	tree* leftTree = newtree();
	tree* rightTree = newtree();
	leftTree -> root = t -> root -> left;
	rightTree -> root = t -> root -> right;
	printf(" %c ", t -> root -> val);
	if(leftTree -> root != NULL){
		preorder(leftTree);
	}
	if(rightTree -> root != NULL){
		preorder(rightTree);
	}
	free(leftTree);
	free(rightTree);
}

void postorder(tree* t){
	if( t == NULL){
		return ;
	}
	tree* leftTree = newtree();
	tree* rightTree = newtree();
	leftTree -> root = t -> root -> left;
	rightTree -> root = t -> root -> right;
	if(leftTree -> root != NULL){
		postorder(leftTree);
	}
	if(rightTree -> root != NULL){
		postorder(rightTree);
	}
	printf(" %c ", t -> root -> val);
	free(leftTree);
	free(rightTree);
}
