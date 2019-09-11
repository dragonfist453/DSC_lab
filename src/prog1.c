#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
struct Stack {
    int stack[MAXSIZE];
    int top;
};

void push(struct Stack *s, int num) {
    if (s->top == (MAXSIZE - 1)) {
        printf("Stack is Full\n");
        return;
    } else {
        s->top = s->top + 1;
        s->stack[s->top] = num;
    }
    return;
}

int pop(struct Stack *s) {
    int num;
    if (s->top == -1) {
        printf("Stack is Empty\n");
        return s->top;
    } else {
        num = s->stack[s->top];
        printf("\nPopped element is = %d\n", s->stack[s->top]);
        s->top = s->top - 1;
    }
    return (num);
}

void display(struct Stack *s) {
    int i;
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        printf("\n The status of the stack is \n");
        for (i = s->top; i >= 0; i--) {
            printf("%d\n", s->stack[i]);
        }
    }
    printf("\n");
}

void alg1(struct Stack *s) {
    printf("3rd element from top is %d\n", s->stack[s->top - 2]);
}

void popn(struct Stack *s, int n) {
    int i;
    for (i = 0; i < n; i++) {
        pop(s);
    }
}

void alg2(struct Stack *s) {
    printf("3rd element from bottom is %d\n", s->stack[2]);
}

int main() {
    struct Stack s;
    s.top = -1;
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    int choice, a;
    while (1) {
        printf(
            "Enter a choice :\n1)Push\n2)Pop\n3)Display\n4)Exit\n5)3rd from "
            "top\n6)Pop n elements\n7)3rd from bottom\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Input element to push into stack :");
                scanf("%d", &a);
                push(&s, a);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            case 5:
                alg1(&s);
                break;
            case 6:
                printf("Enter number of elements to be popped :");
                scanf("%d", &a);
                popn(&s, a);
                break;
            case 7:
                alg2(&s);
                break;
            default:
                printf("Wrong choice entered!!\nTry again\n");
        }
    }
    return 0;
}

