#include <stdio.h>
#include <string.h>
#define MAX 10
int st[MAX];
int top = -1;
void push(char);
char pop();
int main()
{
    char exp[MAX], temp;
    int flag = 1;
    printf("\n Enter an expression:..");
    gets(exp);
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if (exp[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '{' || temp == '('))
                {
                    flag = 0;
                }
            }
        }
    }
    if (top >= 0)
    {
        flag = 0;
    }
    if (flag == 1)
        printf("\n Valid expression..");
    else
    {
        printf("\n Invalid expression...");
    }

    return 0;
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("\n Stack overflow");
    }
    else
    {
        top++;
        st[top] = c;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("\n Stack is empty ...");
    }
    else
    {
        return st[top--];
    }
}