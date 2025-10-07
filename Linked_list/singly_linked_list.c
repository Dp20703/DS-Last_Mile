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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
// deletion
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main()
{
    int option, val;
    do
    {
        printf("\n Main menu...\n");
        printf("\n 1. create a list ");
        printf("\n 2. Insert at begin ");
        printf("\n 3. Insert at end ");
        printf("\n 4. Insert at before a given node ");
        printf("\n 5. Insert at after a given node ");
        printf("\n 6. display list ");
        printf("\n 7. Delete at begin ");
        printf("\n 8. Delete at end");
        printf("\n 9. Delete a given node");
        printf("\n 10. Delete after a given node");
        printf("\n 11. Delete entir list ");
        printf("\n 12. sort list ");
        printf("\n 13. exit ");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\n Linked list is created ...");
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
            break;
        case 4:
            start = insert_before(start);
            break;
        case 5:
            start = insert_after(start);
            break;
        case 6:
            start = display(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
        case 11:
            start = delete_list(start);
            break;
        case 12:
            start = sort_list(start);
            break;
        case 13:
            printf("\nbye bye");
            break;
        default:
            printf("\n Invalid option...");
            break;
        }

    } while (option != 13);

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
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter value: ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("\t %d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter value:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
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
    new_node->next = NULL;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *prevptr, *ptr;
    int num;
    int val;

    printf("\n Enter value:");
    scanf("%d", &num);
    printf("\n Enter value before which the data hase to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    prevptr = ptr;
    while (ptr->data != val)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *prevptr, *ptr;
    int num;
    int val;

    printf("\n Enter value:");
    scanf("%d", &num);
    printf("\n Enter value after which the data hase to be inserted: ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    prevptr = ptr;
    while (prevptr->data != val)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *prevptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = NULL;
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
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *prevptr, *ptr;
    int val;

    printf("\n Enter value of node which the data has to be deleted: ");
    scanf("%d", &val);

    ptr = start;
    if (ptr->data == val)
    {
        start = delete_beg(start);
    }
    else
    {
        while (ptr->data != val)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
    }
    prevptr->next = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            start = delete_beg(ptr);
            ptr = start;
        }
    }

    return start;
}

struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}