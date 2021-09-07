//pritom
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node
{
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

void print_list(void);
void insert_at_front(int item);
void insert_at_the_end(int item);
void add_after_pos(int item);
void print_reverse(void);
void delete_from_front(void);
void delete_from_end(void);
void delete_from_intermidiate_node(void);

int main()
{
    int item;
    int choice;

    while (1)
    {
        printf("\n......................................Double Linked List Insertion......................................\n");
        printf("Please select a option:-\n1. Insert data at front.\n2. Insert data in the end.\n3. Insert data after a given position.\n4. Print list in reverse.\n5. Display List.\n6. Delete data from front of the list.\n7. Delete data from the end of the list.\n8. Delete from intermediate node.\n9. Exit program.\nYour choice:- ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\n\tEnter data  to insert at front: ");
            scanf("%d", &item);

            insert_at_front(item);
            break;
        }
        case 2:
        {
            printf("\n\tEnter data to insert at the end of the list: ");
            scanf("%d", &item);

            insert_at_the_end(item);
            break;
        }
        case 3:
        {
            printf("\n\tEnter data to insert in a given position: ");
            scanf("%d", &item);

            add_after_pos(item);
            break;
        }
        case 4:
        {
            printf("\nPrtinting list in reverse:\nData:  ");
            print_reverse();
            break;
        }
        case 5:
        {
            printf("Printing List......\n");
            print_list();

            break;
        }
        case 6:
        {
            printf("\nDeleting data from front...\n");
            delete_from_front();

            break;
        }
        case 7:
        {
            printf("\nDeleting from end....\n\n");
            delete_from_end();

            break;
        }
        case 8:
        {
            printf("\nDeleting from intermediate node....");

            delete_from_intermidiate_node();

            break;
        }
        case 9:
        {
            printf("\nProgram executed successfully.\n\n");
            exit(0);

            break;
        }
        default:
        {
            printf("\nIncvalid option...!!! Please select a valid option and try again.\n");
            break;
        }
        }
    }
    return 0;
}

void print_list(void)
{
    node *temp = NULL;
    temp = head;
    if (head == NULL)
    {
        printf("\nAlert...! Empty List...! Please insert data first.\n");

        return;
    }
    else
    {
        printf("Data:  ");
        while (temp != NULL)
        {
            printf("%d <---> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insert_at_front(int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Error! Couldnt' allocate memory...!!!\n");
        return;
    }
    else
    {
        ptr->prev = NULL;
        ptr->data = item;
        ptr->next = NULL;
        if (head == NULL)
        {

            head = ptr;

            printf("\nData inserted into the list successfully.\n");

            return;
        }
        else
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;

            printf("\nData inserted in the front successfully.\n");

            return;
        }
    }
}
void insert_at_the_end(int item)
{
    node *temp = NULL;
    node *ptr = (node *)malloc(sizeof(node));

    temp = head;
    if (ptr == NULL)
    {
        printf("Error...!!! Couldn't allocate memory...!\n");
        return;
    }

    else
    {
        ptr->prev = NULL;
        ptr->data = item;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;

            printf("Data inserted at the end of the list, list was empty.");
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;

            printf("\nData inserted at the end successfully.\n");
            return;
        }
    }
}

void add_after_pos(int item)
{
    node *temp1 = head;
    node *temp2 = NULL;

    int pos, i;
    printf("\n\tEnter the position, which after you want to insert data: ");
    scanf("%d", &pos);

    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Error! Unable to allocate memory...!");
        return;
    }
    else
    {
        ptr->prev = NULL;
        ptr->data = item;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;
            printf("\nList was empty, Data inserted at the front instead of the position.\n");
            return;
        }
        else if (temp1->next == NULL)
        {
            for (i = 1; i < pos; i++)
            {

                temp1 = temp1->next;
            }
            temp1->next = ptr;
            ptr->prev = temp1;

            printf("\nYou've selected the last node! Data inserted at the end instead of after the position.\n");
            return;
        }
        else
        {
            for (i = 1; i < pos; i++)
            {
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            temp1->next = ptr;
            temp2->prev = ptr;
            ptr->next = temp2;
            ptr->prev = temp1;

            printf("\nData inserted after the position successfully.\n");
            return;
        }
    }
}

void print_reverse(void)
{
    node *temp = NULL;
    if (head == NULL)
    {
        printf("\nAlert! List is empty...! Please insert data first.\n");
        return;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            printf("%d <--> ", temp->data);
            temp = temp->prev;
        }
        printf("NULL\n");
    }
}
void delete_from_front(void)
{
    if (head == NULL)
    {
        printf("\nAlert...!!! List is already empty...!\n");
        return;
    }
    else
    {
        head = head->next;

        free(head->prev);
        head->prev = NULL;

        printf("\nData deleted from the front successfully.\n");
        return;
    }
}

void delete_from_end(void)
{
    node *temp = NULL;
    node *temp2 = NULL;
    temp = head;
    temp = head;

    if (head == NULL)
    {
        printf("\nAlert...! list is already empty...!");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp2 = temp->prev;
        temp2->next = NULL;
        free(temp);
        temp = NULL;

        printf("\nData deleted from the end successfully.\n");
        return;
    }
}

void delete_from_intermidiate_node(void)
{
    node *temp1, *temp2;
    int dat;

    printf("\nEnter the data, after which you want to delete the  node: ");
    scanf("%d", &dat);

    temp1 = head;
    while (temp1->data != dat)
    {
        temp1 = temp1->next;
    }
    if (temp1->next == NULL)
    {
        printf("\nData can not be deleted.\n");
        return;
    }
    else if (temp1->next->next == NULL)
    {
        free(temp1->next);
        temp1->next = NULL;

        return;
    }
    else
    {
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        free(temp2);
        temp2 = NULL;

        printf("\nNode is deleted successfully...!\n");
        return;
    }
}