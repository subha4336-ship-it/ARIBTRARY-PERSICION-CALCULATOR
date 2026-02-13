#include "apc.h"
#include <stdlib.h>
#include <string.h>

void string_to_list(char *str, Dlist **head, Dlist **tail)
{
    *head = NULL;
    *tail = NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        Dlist *new = malloc(sizeof(Dlist));
        new->data = str[i] - '0';
        new->prev = NULL;
        new->next = NULL;

        if (*head == NULL)   // first node
        {
            *head = new;
            *tail = new;
        }
        else                  // append at tail
        {
            (*tail)->next = new;
            new->prev = *tail;
            *tail = new;
        }
    }
}



    
int compare_num(Dlist *head1, Dlist *head2)
{
    int len1 = 0;
    int len2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    /* Step 1: find length of both numbers */
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    /* Step 2: compare length */
    if (len1 > len2)
    {
        return 1;
    }
    else if (len1 < len2)
    {
        return -1;
    }

    /* Step 3: same length → compare digit by digit */
    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            return 1;
        }
        else if (temp1->data < temp2->data)
        {
            return -1;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    /* Step 4: numbers are equal */
    return 0;
}

void print(Dlist *head)
{
    if (!head)
    {
        printf("0\n");
        return;
    }

    Dlist *temp = head;
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;  // head → tail (MSD → LSD)
    }
    printf("\n");
}

void copy_list(Dlist *src, Dlist **dest_head, Dlist **dest_tail)
{
    *dest_head = NULL;
    *dest_tail = NULL;

    Dlist *curr = src;
    while (curr)
    {
        insert_last(dest_head, dest_tail, curr->data);
        curr = curr->next;
    }
}

