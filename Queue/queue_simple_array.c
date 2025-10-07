#include <stdio.h>
#define MAX 10
int queue[MAX];
int rear = -1;
int front = -1;

void display(void);
void insert(void);
int delete(void);
int peek(void);
int main()
{
    int option;
    int val;
    do
    {
        printf("\n Menu....\n");
        printf("\n 1.Insert an element");
        printf("\n 2.delete an element");
        printf("\n 3. peek");
        printf("\n 4. display");
        printf("\n 5.Exit...\n");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete();
            if (val != -1)
            {
                printf("\n The number deleted : %d ", val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("\n The first value in queue : %d ", val);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n bye bye");
            break;
        default:
            printf("\n invalid option");
            break;
        }
    } while (option != 5);

    return 0;
}
void display()
{
    printf("\n");
    if (front == -1 || front > rear)
    {
        printf("\n Queue is empty ");
    }
    else
    {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("\t %d ", queue[i]);
        }
    }
}

int peek()
{
    if (front == -1 || front > rear)
    {
        printf("\n Queue is empty ");
        return -1;
    }
    else
    {
        return queue[front];
    }
}
int delete()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("\n Queue is empty ");
        return -1;
    }
    else
    {
        val = queue[front];
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }
}
void insert()
{
    int val;
    printf("\n Enter value: ");
    scanf("%d", &val);
    if (rear == MAX - 1)
    {
        printf("\n Queue is full ");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = val;
    printf("\nInserted %d into the queue.", val);
}