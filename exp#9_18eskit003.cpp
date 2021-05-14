#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char stack[100];
int top = -1;
void push(char item){
	if(top >= 100-1)
			printf("\nStack Overflow.");
  else{	top = top+1;
				stack[top] = item;		}			}
char pop(){	char item ;
	if(top <0){		printf("stack under flow: invalid infix expression");
								getchar();
								exit(1);	}
		else{		item = stack[top];
						top = top-1;
						return(item);	}
	}
int is_operator(char symbol){
	if(symbol == '^' ||symbol == '*'||symbol == '/'
			||symbol == '+'||symbol == '-')
		 return 1;
	else		return 0;
	}
int precedence(char symbol){
	if(symbol = '^')		return(3);
	else if(symbol=='*' || symbol == '/')			return(2);
  else if(symbol=='+' || symbol=='-')			return(1);
	else			return(0);
}
void infixToPostfix(char infix_exp[], char postfix_exp[]){
	int i, j;	char item, x;
	push('(');
	strcat(infix_exp,")");
	i=0, j=0;
	item=infix_exp[i];
	while(item != '\0'){			if(item == '(')
					push(item);
			else if( isdigit(item) || isalpha(item)){
					postfix_exp[j] = item;					j++;				}
		 else if(is_operator(item)==1){					x=pop();
					while(is_operator (x) == 1 &&	precedence(x)>= precedence (item)){
							postfix_exp[j] = x;
							j++;	x = pop();				}
					push(x);		push(item);			}
		else if(item==')'){		x = pop();
			while(x != '('){		postfix_exp[i]=x;
													j++;	x = pop();			}		}
else{	printf("\nInvalid infix Expression. An");
			getchar();
			exit(1);}
	i++;	item = infix_exp[i];	}
if(top>0){	printf("\tInvalid infix Expression. In");
						getchar();
						exit (1);	}
postfix_exp[j] = '\0';
}
int main(){
	char infix[100], postfix[100];
	FILE *fptr;
	if ((fptr = fopen("xyz.txt", "r")) == NULL){
		printf("Error! Opening file");
		exit (1);	}
	int i=0;	char ch;
	while ((ch = fgetc(fptr)) != EOF)		{
			infix[i]=ch;
			i++;	}
	infix[i-1]='\0';
	printf("\nInfix expression :%s",infix);
	infixToPostfix(infix,postfix);
	printf("\nPostfix Expression: ");
	puts (postfix);
	return 0;}
