#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE node;

struct NODE
{
    int data;
    node *next;
};

node *head = NULL;
/***************
 * Pritom Paul
 * Reg: 200103020063
 * **************/
void insert_at_front(int item);
void insert_at_end(int item);
void insert_in_selected_position(int item);
void print_list(void);
void search_in_the_list(void);
void delete_from_front(void);
void delete_from_end(void);
void delete_from_position(void);
void print_reverse(node *head);
void max_node(void);
void min_nude(void);
bool isCircular();

void main()
{
    int choice, item;
    int del;

    while (1)
    {
        printf("\n.......................Linked List with Insertion, search and deletion.......................\n");
        printf("The choices are:-\n1. Insert data at the front.\n2. Insert at the last.\n3. Insert in a selected position.\n4. Display List.\n5. Search in the list.\n6. Delete data from front.\n7. Delete data from end.\n8. Delete data from a specific position.\n9. Print List in reverse.\n10. Find the maximum value.\n11. Find the minimum value.\n12. IsCircular?\n13. Exit program.\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("\n\tEnter data to insert at the front:- ");
            scanf("%d", &item);

            insert_at_front(item);

            break;
        }
        case 2:
        {
            printf("\n\tEnter data to insert at the end:- ");
            scanf("%d", &item);

            insert_at_end(item);

            break;
        }
        case 3:
        {
            printf("\n\tEnter data to insert in a selected position:- ");
            scanf("%d", &item);

            insert_in_selected_position(item);

            break;
        }
        case 4:
        {
            print_list();

            break;
        }
        case 5:
        {
            search_in_the_list();

            break;
        }

        case 6:
        {
            delete_from_front();

            break;
        }

        case 7:
        {

            delete_from_end();

            break;
        }
        case 8:
        {
            delete_from_position();

            break;
        }

        case 9:
        {
            printf("\nList printed in reverse:-\n");
            printf("Data:-   ");
            print_reverse(head);
            printf("NULL\n");

            break;
        }
        case 10:
        {
            max_node();

            break;
        }
        case 11:
        {
            min_nude();
        }
        case 12:
        {
            bool x = isCircular();
            if (x == true)
            {
                printf("Yes. List is circular.\n");
            }
            else
            {
                printf("No. list is linear.\n");
            }
            break;
        }
        case 13:
        {
            printf("\n\nProgram executed successfully.\n\n");

            exit(0);

            break;
        }
        default:
        {
            printf("Error...!!! Please enter valid option....!!!");

            break;
        }
        }
    }
}

void print_list(void)
{
    node *temp = NULL;
    if (head == NULL)
    {
        printf("\n404, Empty List...!!! Please, insert data first.\n");
        return;
    }
    else
    {
        temp = head;
        printf("\nData:-  ");
        while (temp != NULL)
        {
            printf("%d --> ", temp->data);

            temp = temp->next;
        }
        printf("NULL;\n");

        return;
    }
}

void insert_at_front(int item)
{
    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        printf("\nError...!!! Failed to allocate emory...!\n");
        return;
    }

    else
    {
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            head->next = NULL;

            printf("\nData inserted in the front successfully.\n");

            return;
            
        }
        else
        {
            ptr->next = head;
            head = ptr;

            printf("\nData inserted in thefront successfully.\n");

            return;
        }
    }
}
void insert_at_end(int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *temp = head;

    if (ptr == NULL)
    {
        printf("Error! Failed to allocate memory!\n");
        return;
    }
    else
    {
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;

            printf("\nData inserted at the biginning successfully.\n");
            return;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;

            printf("\nData inserted at the biginning successfully.\n");
            return;
        }
    }
}
void insert_in_selected_position(int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *temp = NULL;
    int pos;
    if (ptr == NULL)
    {
        printf("Error! Failed to allocate memory!\n");
        return;
    }
    else
    {

        printf("\n\tPlease, enter the position, after where you want to insert the data: ");
        scanf("%d", &pos);
        temp = head;
        ptr->data = item;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n404, No data found! Empty List\n");
                head = ptr;
                ptr->next = NULL;

                printf("\nData inserted in the front instead.\n");
                return;
            }
            else
            {
                ptr->next = temp->next->next;
                temp->next->next = ptr;
                printf("\nData inserted in the selected position successfully.\n");
                return;
            }
        }
    }
}

void search_in_the_list(void)
{
    node *temp;
    int i = 1, ser_item, q;

    temp = head;
    printf("\n\tEnter the data you want to search in the list: ");
    scanf("%d", &ser_item);

    if (temp == NULL)
    {
        printf("Error! Empty list!!!\n");
    }
    else
    {

        while (temp != NULL)
        {
            if (temp->data == ser_item)
            {
                printf("\nData found at position %d\n", i);
                q = 0;
                return;
            }
            else
            {
                q = 1;
            }
            temp = temp->next;
            i++;
        }
        if (q == 1)
        {
            printf("\n404, Data not found.\n");
            return;
        }
    }
}
void delete_from_front(void)
{
    node *temp;

    temp = head;
    if (temp == NULL)
    {
        printf("\nAlert...!!!\nList is already empty...!!!\n");
        return;
    }
    else
    {
        head = head->next;

        free(temp);
        temp = NULL;

        printf("\nData deleted from the front successfully.\n");
        return;
    }
}
void delete_from_end(void)
{
    node *temp;

    temp = head;

    if (temp == NULL)
    {
        printf("\nAlert...!!! List is already empty...!!!\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
        printf("\nData deleted from the end of the list successfully.\n");
        return;
    }
}
void delete_from_position(void)
{
    node *current = head;
    node *pre;
    int pos;

    printf("Enter the positions after which you want to delete data: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("\nAlert...!!! List is already empty!\n");
        return;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            pre = current;
            current = current->next;
        }

        pre->next = current->next;
        free(current);
        current = NULL;
        printf("\nData deleted successfully.\n");

        return;
    }
}
void print_reverse(node *head)
{
    if (head == NULL)
    {
        return;
    }

    print_reverse(head->next);

    printf("%d -->", head->data);
}

void max_node(void)
{
    node *temp = (node *)malloc(sizeof(node));
    int max = head->data;

    temp = head;

    if (head == NULL)
    {
        printf("Ops...! List is empty...!");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (max < temp->data)
            {
                max = temp->data;
            }
            temp = temp->next;
        }
        printf("\nThe maximum value is: %d\n", max);
        return;
    }
}

void min_nude(void)
{
    node *temp = NULL;
    int min = head->data;

    temp = head;
    if (head == NULL)
    {
        printf("Ops...! List is empty...!");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (min > temp->data)
            {
                min = temp->data;
            }
            temp = temp->next;
        }
        printf("\nThe minimum value is: %d\n", min);
        return;
    }
}

bool isCircular()
{
    if (head == NULL)
    {
        return true;
    }
    node *node = head->next;

    while (node != NULL && node != head)
    {
        node = node->next;
    }
    return (node == head);
}