#include <stdio.h>
#define MAX 10
void push(int);
int pop(void);

int top = -1;
int stack[MAX];
int main()
{
    int arr[MAX], val;
    int n;
    printf("\n Enter the number to be reversed ....");
    scanf("%d", &n);
    printf("\n Enter value of element ..");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        push(arr[i]);
    }
    printf("\n Before value of element ..");
    for (int i = 0; i < n; i++)
    {
        printf("\t %d", arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        val = pop();
        arr[i] = val;
    }

    printf("\n Reversed value of element ..");
    for (int i = 0; i < n; i++)
    {
        printf("\t %d", arr[i]);
    }
    return 0;
}

void push(int val)
{
    stack[++top] = val;
}
int pop()
{
    return stack[top--];
}