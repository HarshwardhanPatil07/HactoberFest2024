//Parentheses checker problem
//Arushi2S
#include <stdio.h>
#include <string.h>
#define MAX 10
int top=-1;
char stk[MAX];
void push(char);
char pop();
void main()
{ 
char exp[MAX],temp; 
int i, flag=1;
printf("Enter an expression : ");
 gets(exp); 
for(i=0;i<strlen(exp);i++)
 { 
if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
   push(exp[i]);  
if(exp[i]== ')' || exp[i]== '}' || exp[i]== ']')
{
	if(top==-1)
    flag=0;
	else
	{
    temp=pop(); 
	if(exp[i]==')' && (temp=='{' || temp=='[')) 
	flag=0;  
	else if(exp[i]=='}' && (temp=='(' || temp=='[')) 
	flag=0;  
	else if(exp[i]==']' && (temp=='(' || temp=='{')) 
	flag=0;
	}
} 
} 
if(top>=0) 
	flag=0; 
if(flag==1) 
printf("\n Valid expression");
else 
printf("\n Invalid expression");
}
void push(char val)
{
	// Check Overflow // if not push the element into the stack
	stk[++top] = val;
}
char pop()
{
	// Check Underflow // if not pop the element from the stack
	return (stk[top--]);
}
