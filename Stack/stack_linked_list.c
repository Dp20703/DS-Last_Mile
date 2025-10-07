#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

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
            top = push(top, val);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            val = peek(top);
            if (top != -1)
                printf("\n Top value in Stack: %d", val);
            else
            {
                printf("\n Stack is Empty");
            }
            break;

        case 4:
            top = display(top);
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
struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;
    if (top == NULL)
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
};

struct stack *pop(struct stack *top)
{
    struct stack *ptr = top;
    if (top == NULL)
    {
        printf("\n Stack is empty ..");
    }
    else
    {
        top = top->next;
        printf("\n Deleted value %d ", ptr->data);
        free(ptr);
    }
    return top;
}
int peek(struct stack *top)
{
    if (top == NULL)
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

struct stack *display(struct stack *top)
{
    struct stack *ptr = top;
    if (top == NULL)
    {
        print("\n Stack is empty....");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\t %d ", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}