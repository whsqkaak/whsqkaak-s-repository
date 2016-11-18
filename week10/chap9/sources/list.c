#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

/* Define  'list' using typedef and struct.
	list has head, and size */
typedef struct{
	node* head;
	int size;
}list;

/* Prototypes */
list* init_list();
void appendTo(list* list, node* newnode);
void delAt(list* list, int n);
void print_list(list* list);

int main(int argc, char const *argv[]) {
	list* linked = init_list();
	int i;
	for (i = 1; i < 6; i++) {
		appendTo(linked, newnode(i));
	}
	print_list(linked);
	delAt(linked, -1);
	delAt(linked, 5);
	print_list(linked);
	delAt(linked, 3);
	print_list(linked);
	return 0;
}

list* init_list(){
	list* init;
	init = (list*)malloc(sizeof(list));
	init->size = 0;
	init->head = (node*)malloc(sizeof(node));
	init->head->val = 0;
	init->head->next = NULL;
	return init;
}

void appendTo(list* list, node* newnode){
	node* temp = list->head;
	for(int i = 0; i < list->size; i++){
		temp = temp->next;
	}
	temp->next = newnode;
	list->size = list->size + 1;
}

void delAt(list* list, int n){
	printf("Delete %d index of linked list\n", n);
	printf("-----------------------------------\n");
	if(n < 1 || n > list->size){
		printf("delAt() : out of index ( n = %d )\n", n);
		return;
	}
	node* temp = list->head;
	for(int i = 0; i < n-1; i++){
		temp = temp->next;
	}
	node* delnode = temp->next;
	temp->next = delnode->next;
	free(delnode);
	list->size = list->size - 1;
}

void print_list(list* list){
	node* temp = list->head;
	printf("List size = %d\n", list->size);
	for(int i = 0; i < list->size; i++){
		temp = temp->next;
		printf("[%d]", temp->val);
	}
	printf("\n\n");
}
