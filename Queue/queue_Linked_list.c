#include <stdio.h>
#include <stdlib.h> // use stdlib.h instead of malloc.h

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
    int val, option;
    struct queue *q;

    // ✅ Allocate memory for queue structure
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n\n--- Queue Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
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
            q = insert(q, val);
            break;

        case 2:
            q = delete(q);
            break;

        case 3:
            val = peek(q);
            if (val != -1)
                printf("\nFront value in queue: %d", val);
            break;

        case 4:
            q = display(q);
            break;

        case 5:
            printf("\nBye bye!\n");
            break;

        default:
            printf("\nInvalid option!");
        }

    } while (option != 5);

    return 0;
}

void create_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

struct queue *insert(struct queue *q, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    printf("\nInserted %d into the queue.", val);
    return q;
}

struct queue *delete(struct queue *q)
{
    struct node *ptr = q->front;

    if (q->front == NULL)
    {
        printf("\nUnderflow! Queue is empty.");
    }
    else
    {
        printf("\nDeleted value: %d", ptr->data);
        q->front = q->front->next;
        free(ptr);

        if (q->front == NULL)
            q->rear = NULL; // reset when queue becomes empty
    }

    return q;
}

struct queue *display(struct queue *q)
{
    struct node *ptr = q->front;

    if (ptr == NULL)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nQueue elements: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }

    return q;
}

int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("\nQueue is empty.");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}
