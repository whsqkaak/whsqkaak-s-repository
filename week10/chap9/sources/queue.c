#include <stdio.h>
#include <stdlib.h>
#include "../headers/node.h"

/* Define  'queue' using typedef and struct.
	queue has front, rear, and size */
typedef struct{
	node* front;
	node* rear;
	int size;	
}queue;

/* Prototypes */
queue* init_queue();
void enqueue(queue*, node*);
void dequeue(queue*);
int front(queue*);
void print_queue(queue*);


int main(int argc, char const *argv[]){
	int i;
	queue* q = init_queue();
	enqueue(q, newnode(1));
	printf("front : %d\n", front(q));
	dequeue(q);
	dequeue(q);
	for(i = 2; i<6;i++){
		enqueue(q, newnode(i));
	}
	dequeue(q);
	print_queue(q);
	for(i = 0; i<3;i++) dequeue(q);
	front(q);
	return 0;
}

queue* init_queue(){
	queue* init;
	init = (queue*)malloc(sizeof(queue));
	init->front = (node*)malloc(sizeof(node));
	init->front->val = 0;
	init->front->next = NULL;
	init->rear = (node*)malloc(sizeof(node));
	init->rear->val = 0;
	init->rear->next = NULL;
	init->size = 0;
	return init;
}

void enqueue(queue* queue, node* newnode){
	if(queue->size == 0){
		queue->rear->next = newnode;
		queue->front->next = newnode;
		queue->size += 1;
		return;
	}
	queue->rear->next->next = newnode;
	queue->rear->next = newnode;
	queue->size += 1;
}

void dequeue(queue* queue){
	if(queue->size == 0){
		printf("dequeue() : queue is empty\n");
		return;	
	}	
	node* delnode = queue->front->next;
	queue->front->next = delnode->next;
	queue->size -= 1;
	free(delnode);
}

int front(queue* queue){
	if(queue->size == 0){
		printf("front() : queue is empty\n");
		return 0;
	}
	return queue->front->next->val;
}

void print_queue(queue* queue){
	node* temp = queue->front;
	printf("Q:");
	for(int i = 0; i < queue->size; i++){
		temp = temp->next;
		printf(" [%d] ", temp->val);
	}
	printf("\n");
}
