#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void push(int i);
void print();
void pop();

int main(){
	char given[100];
	int i = 0,res=0;
	
	printf("Enter an RPN expression: ");
	gets(given);

	
	while(given[i] != '\0'){
		if(isdigit(given[i]))
			push((int)(given[i])-48);
		else{
			switch(given[i]){
				case '*':
					res = contents[top-2] * contents[top-1];
				break;
				case '-':
					res = contents[top-2] - contents[top-1];
				break;
				case '+':
					res = contents[top-2] + contents[top-1];
				break;
				case '/':
					res = contents[top-2] / contents[top-1];
				break;
				default:
					goto HERE;
			}
			pop();
			pop();
			push(res);
		}
		HERE: i++;
	}
		print();	
	return 0;
}


void make_empty(){
	top = 0;
}

bool is_empty(){
	return top == 0;
}

bool is_full(){
	return top == STACK_SIZE;
}

void push(int i){
	if(is_full())
		printf("overflow");
	else
		contents[top++] = i;
}

void pop(){
	if(is_empty())
		printf("underflow");
	else
		contents[--top];
}

void print(){
	int i;
	for(i=0;i<top;i++)
		printf("%d ",contents[i]);
		printf("\n");
}
