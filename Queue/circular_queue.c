#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;
void insert(void);
int delete(void);
int peek(void);
void display(void);
int main()
{
    int option, val;
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
            insert();
            break;

        case 2:
            val = delete();
            if (val != -1)
                printf("\n Deleted num value in queue: %d", val);
            break;

        case 3:
            val = peek();
            if (val != -1)
                printf("\nFront value in queue: %d", val);
            break;

        case 4:
            display();
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

void insert()
{
    int val;
    printf("\nEnter the number to insert in the queue: ");
    scanf("%d", &val);
    if (front == 0 && rear == MAX - 1)
    {
        printf("\n Queue is full ");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if (front != 0 && rear == MAX - 1)
    {
        rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
}

int delete()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\n Underflow");
        return -1;
    }
    val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return val;
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Underflow");
        return -1;
    }
    else
    {
        return queue[front];
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n queue is empty");
    }
    else
    {
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("\t %d ", queue[i]);
            }
        }
        else
        {
            for (int i = front; i <= MAX - 1; i++)
            {
                printf("\t %d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("\t %d ", queue[i]);
            }
        }
    }
}