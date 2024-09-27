/*
    Created by: Bhuwan Pandey
*/
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int arr[100];
    int tos;
};

void push(struct Stack *, int);
int pop(struct Stack *);
int peek(struct Stack *);

int main()
{
    struct Stack s;
    int i, x, choise;
    s.tos = -1;

    do
    {
        printf("\n------------------------\n| 1. Push() Operation  |\n| 2. Pop() Operation   |\n| 3. Peek Operation    |\n| 4. Exit Program      |\n------------------------\n");
        printf("\nEnter a operation : ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
        {
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nenter the element : ");
            scanf("%d", &x);
            push(&s, x);
            break;
        }
        case 2:
        {
            x = pop(&s);
            if (x != 0)
            {
                printf("\n=========================================\n%d is poped Sucessfully!!\n=========================================\n", x);
            }
            break;
        }
        case 3:
            printf("\n=========================================\n%d is your top element of Stack\n=========================================\n", peek(&s));
            break;
        case 4:
            // break;
            goto b;
        default:
            printf("\n=========================================\nInvalid Operation\n=========================================\n");
            break;
        }
    } while (1);
b:
    return 0;
}

//Push Operation
void push(struct Stack *p, int x)
{
    if (p->tos == 99)
    {
        printf("\n=========================================\nStack OverFlow\n=========================================\n");
        return;
    }
    // p->tos++;
    // p->arr[p->tos] = x;
    p->arr[++p->tos] = x; //shorthand for above 2 lineSS
    printf("\n=========================================\nPushed %d Sucessfully!!\n=========================================\n", x);
}

//Pop Operation
int pop(struct Stack *p)
{
    // int del;
    if (p->tos == -1)
    {
        printf("\n=========================================\nStack Underflow\n=========================================\n");
        return 0;
    }
    // del = p->arr[p->tos];
    // p->tos--;
    // return del;
    return p->arr[p->tos--]; //shorthand for above 3 line
}


//Peek operation 
int peek(struct Stack *p)
{
    return p->arr[p->tos];
}