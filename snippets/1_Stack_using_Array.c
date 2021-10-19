#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct{
	int* data;
	int top;
}stack;

void initialization(stack*,int);
int is_empty(stack);
int is_full(stack,int);
void push(stack*, int,int);
int pop(stack*);
void display(stack*, int);

void initialization(stack* p,int stack_size){
	p->data=(int *) malloc(sizeof(int*)*stack_size);
	p->top=-1;
}

int is_empty (stack p){
	return (p.top == -1);
}

int is_full (stack p,int size){ 
	return (p.top==size-1);
}

void push (stack *p, int n,int size){

	if (p->top!=size-1) 
		p->data[++(p->top)]=n;
	else
		printf ("\n Stack Over Flow\n");
}

int pop (stack *p){

	if (p->top!=-1) 
		return( p->data[(p->top)--]);
	else
	{
		printf("\nEmpty Stack\n");
		return -111;
	}
}

void display( stack* p,int size) {
	int i = 0;
	for(i=0; i<=p->top; i++) {
		printf("item= %d\n", p->data[i]);	
	}
	printf("\n");
}
	
void main(){
	stack s;
	
	int size;
	printf("Enter the stack size:\n");
	scanf("%d",&size);
	initialization(&s,size);
	int choice=0;
	int item=0;
	do{
		printf("Please Select Your Choice\n");
		printf(" 1.Push\n 2.Pop\n 3.Display\n 4.EXIT\n");
		fflush(stdin);
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: 
				printf("Enter the Item to Push into the Stack: ");
				scanf("%d", &item);
				push(&s,item,size);
				display(&s,size);
				break;
			case 2:
				printf("Popping Element from the Stack\n");
				int x = pop(&s);
				if(x != -size)	
					printf("Removed Item is: %d\n", x);
				display(&s,size);
				break;
			case 3:
				display(&s,size);
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("Please Select the Appropriate Choice\n");
		}
		
	
	} while(choice != 4);
	
	
	
}
