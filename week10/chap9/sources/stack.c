#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

/* Define 'stack' using typedef and struct.
	stack has top, size */
typedef struct{
	node* top;
	int size;
}stack;

/* Prototypes */
stack* init_stack();
void push(stack*, node*);
void pop(stack*);
int top(stack*);
void print_stack(stack*);

int main(int argc, char const *argv[]) {
	int i;
	stack* s = init_stack();
	push(s, newnode(1));
	printf("top : %d\n", top(s));
	pop(s);
	pop(s);
	for (i = 2; i < 6; i++) {
		push(s, newnode(i));
	}
	pop(s);
	print_stack(s);
	for (i = 0; i < 3; i++) pop(s);
	top(s);
	return 0;
}

stack* init_stack(){
	stack* init;
	init = (stack*)malloc(sizeof(stack));
	init->top = (node*)malloc(sizeof(node));
	init->top->next = NULL;
	init->top->val = 0;
	init->size = 0;
	return init;
}

void push(stack* stack, node* newnode){
	newnode->next = stack->top->next;
	stack->top->next = newnode;
	stack->size = stack->size + 1;
}

void pop(stack* stack){
	if(stack->size == 0){
		printf("pop() : stack is empty.\n");
		return;
	}
	node* popnode = stack->top->next;
	stack->top->next = stack->top->next->next;
	free(popnode);
	stack->size = stack->size - 1;
}

int top(stack* stack){
	if(stack->size ==0){
		printf("top() : stack is empty.\n");
		return 0;
	}
	return stack->top->next->val;
}

void print_stack(stack* stack){
	node* temp = stack->top;
	printf("Top\n");
	for(int i = 0; i< stack->size; i++){
		temp = temp->next;
		printf(" [%d] \n", temp->val);
	}
}
