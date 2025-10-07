#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int st[MAX], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main()
{
    int val, option;
    do
    {
        printf("\n\n--- Stack Menu ---\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the number to insert in the queue: ");
            scanf("%d", &val);
            push(st, val);
            break;

        case 2:
            val = pop(st);
            if (val != -1)
            {
                printf("\n Popped value : %d ", val);
            }
            break;

        case 3:
            val = peek(st);
            if (top != -1)
                printf("\n Top value in queue: %d", val);
            break;

        case 4:
            display(st);
            break;

        case 5:
            printf("\nBye bye!\n");
            break;

        default:
            printf("\nInvalid option!");
        }

        /* code */
    } while (option != 5);

    return 0;
}

void display(int st[])
{
    if (top == -1)
    {
        printf("\n Stack is empty..");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\t %d ", st[i]);
        }
        printf("\n");
    }
}
void push(int st[], int val)
{
    if (top == MAX - 1)
    {
        printf("\n Stack is full..");
    }
    else
    {
        st[++top] = val;
    }
}
int pop(int st[])
{
    int val;
    if (top == -1)
    {
        printf("\n Stack is empty ...");
        return -1;
    }
    else
    {
        val = st[top--];
        return val;
    }
}
int peek(int st[])
{

    if (top == -1)
    {
        printf("\n Stack is empty ...");
        return -1;
    }
    else
    {
        return st[top];
    }
}