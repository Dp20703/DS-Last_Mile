#include <stdio.h>
#include <ctype.h>
#define MAX 100
float st[MAX];
int top = -1;
void push(float[], float val);
float pop(float[]);
float evalPostfix(char exp[]);
int main()
{
    char exp[MAX];
    float val;
    printf("\n Enter the expression: ");
    gets(exp);
    val = evalPostfix(exp);
    printf("\n The value of expression: %.2f", val);
    return 0;
}

void push(float st[], float val)
{
    if (top == MAX - 1)
    {
        printf("\n Stack overflow...");
    }
    else
    {
        top++;
        st[top] = val;
    }
}
float pop(float st[])
{
    if (top == -1)
    {
        printf("\n Stack underflow...");
    }
    else
    {
        return st[top--];
    }
}

float evalPostfix(char exp[])
{
    int i = 0;
    float op1, op2, val;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, (float)(exp[i] - '0'));
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '%':
                val = (int)op1 % (int)op2;
                break;
            }
            push(st, val);
        }
        i++;
    }
    return (pop(st));
}