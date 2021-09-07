#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node node;
struct Node
{
    int data;
    node *next;
};
node *tail = NULL;
void print_list(void);
void create_list(int item);
void insert_at_front(int item);
void main()
{
    int item; //data
    int ch;   //switch argument
    while (1)
    {
        printf("\n.......................Circular Linked List.......................\n");
        printf("Options:-\n");
        printf("01. Create a list.\n");
        printf("02. Insert at beginning.\n");
        printf("03. Insert at end.\n");
        printf("04. IsCircular?");
        printf("09. Print List.\n");
        printf("00. Exit the program.\nEnter choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int count;
            printf("Enter number of nodes: ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++)
            {
                printf("\nEnter data %d: ", i+1);
                scanf("%d", &item);
                create_list(item);
            }
            break;
        }
        case 2:
        {
            printf("Inserting at the front....\n");
            printf("Enter data: ");
            scanf("%d", &item);
            insert_at_front(item);
            break;
        }
        case 3:
        {

        }
        case 9:
        {
            printf("Print list...\n");
            print_list();
            break;
        }
        case 00:
        {
            printf("\nTerminated\n");
            exit(0);
        }
        default:
        {
            printf("\nPlease, enter valid option...!\n");
            break;
        }
        }
    }
}

void create_list(int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory could not created.....");
        return;
    }
    else
    {
        ptr->data = item;
        if(tail == NULL)
        {
            tail = ptr;
            ptr->next = tail;
            printf("\n1st node added...!");
            return;
        }
        else
        {
            node *temp = tail;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = tail;
            printf("\nData added in the end...!\n");
            return;
        }
    }  
}
void print_list(void)
{
    node *temp = tail;
    if(tail == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }
    else
    {
        do
        {
            printf("%d ==> ", temp->data);
            temp = temp->next;
        }while (temp != tail);
        return;
    }
    
}

void insert_at_front(int item)
{
    node *ptr = malloc(sizeof(node));
    node *temp = tail;
    if(ptr == NULL)
    {
        printf("\nerror....!\n");
        return;
    }
    else
    {
        ptr->data = item;
        if (tail == NULL)
        {
            printf("List is empty...!");
            return;
        }
        else
        {
             ptr->next = tail;
             do
             {
                 temp = temp->next;
             } while (temp->next != tail);
             temp->next= ptr;
             tail = ptr;

             printf("\nData added at the front.\n");
        }
        
        
    }
    
}

bool isCircular(struct Node *head)
{
    // An empty linked list is circular
    if (head == NULL)
       return true;
 
    // Next of head
    struct Node *node = head->next;
 
    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
       node = node->next;
 
    // If loop stopped because of circular
    // condition
    return (node == head);
}