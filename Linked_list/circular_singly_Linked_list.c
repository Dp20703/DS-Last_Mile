#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
/// declaration
struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);

// insertion
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
// deletion
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
{
    int option, val;
    do
    {
        printf("\n Main menu...\n");
        printf("\n 1. create a list ");
        printf("\n 2. display list ");
        printf("\n 3. Insert at begin ");
        printf("\n 4. Insert at end ");
        printf("\n 5. Delete at begin ");
        printf("\n 6. Delete at end");
        printf("\n 7. Delete after a given node");
        printf("\n 8. Delete entir list ");
        printf("\n 9. exit ");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\n Linked list is created ...");
            break;

        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_after(start);
            break;
        case 8:
            start = delete_list(start);
            break;
        case 9:
            printf("\nbye bye");
            break;
        default:
            printf("\n Invalid option...");
            break;
        }

    } while (option != 9);

    return 0;
}
struct node *create_ll(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter -1 to end ...");
    printf("\n Enter value: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\n Enter value: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    if (start == NULL)
    {
        printf("\nList is empty.");
        return start;
    }
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        printf("\t %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d ", ptr->data);
    return start;
}

// insertion
struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter value:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter value:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    return start;
}

// deletion
struct node *delete_beg(struct node *start)
{
    struct node *ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;

    free(start);
    start = ptr->next;
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *prevptr;
    ptr = start;
    while (ptr->next != start)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *prevptr, *ptr;
    int val;

    printf("\n Enter value after which the data has to be deleted: ");
    scanf("%d", &val);

    ptr = start;
    prevptr = ptr;
    while (prevptr->data != val)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = ptr->next;
    if (ptr == start)
    {
        start = prevptr->next;
    }
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        start = delete_end(start);
    }
    free(start);
    return start;
}
