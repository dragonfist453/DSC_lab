#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
struct STACK
{
    char stack[MAX];
    int top;
};
typedef struct STACK* stk;
void push(stk s, char ch)
{
    if (s->top == (MAX - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        s->top = s->top + 1;
        s->stack[s->top] = ch;
    }
    return;
}
char pop(stk s)
{
	char ch;
    if (s->top == - 1)
    {
        printf ("Stack is Empty\n");
    return NULL;
    }
    else
    {
        ch = s->stack[s->top];
        //printf ("\nPopped element is = %d\n", s->stack[s->top]);
        s->top = s->top - 1;
    }
    return(ch);
}
void display(stk s)
{
	int i;
    if (s->top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s->top; i >= 0; i--)
        {
            printf (" %c", s->stack[i]);
        }
    }
    printf ("\n");
}
int checkprec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
                break;
        case '*':
        case '/':return 2;
                break;
        default:return -1;
                break;
    }
}
int main()
{
    struct STACK postfix,infix,main_stack;
    infix.top = postfix.top = main_stack.top = -1;
    char ch='y';
    char expression[MAX];
    printf("Enter infix expression : ");
    scanf(" %s",expression);
    int i;
    for(i=0;i<strlen(expression);i++)
        push(&infix,expression[i]);
    while(infix.top!=-1)
    {
        char ele = pop(&infix);
        if(isalnum(ele))
            push(&postfix,ele);
        else if(ele == '(')
            push(&main_stack,ele);
        else if(ele == ')')
        {
            push(&main_stack,ele);
            char empty;
            do
            {
                empty = pop(&main_stack);
                if(empty !='('||empty!=')')
                    push(&postfix,empty);
            }while(empty!='('||main_stack.top!=-1);
        }
        else
        {
            if(checkprec(ele)==2)
            {
                char empty = pop(&main_stack);
                push(&postfix,empty);
                push(&main_stack,ele);
            }
            else if(checkprec(ele)==1)
            {
                char empty = pop(&main_stack);
                if(checkprec(empty)==2)
                    push(&main_stack,ele);
                else
                    push(&postfix,empty);
                    push(&main_stack,ele);
            }
            else
            {
                printf("Proper symbol not entered!! Bye.");
                exit(0);
            }
        }
    }
    while(main_stack.top!=-1)
    {
        push(&postfix,pop(&main_stack));
    }
    display(&postfix);
    return 0;
}
