


#include "apc.h"
#include <stdlib.h>

/* Insert at the beginning of the doubly linked list */
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = malloc(sizeof(Dlist));
    if (!new_node)
        return FAILURE;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL)  // Empty list
    {
        *head = new_node;
        *tail = new_node;
    }
    else  // Non-empty list
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }

    return SUCCESS;
}

/* Insert at the end of the doubly linked list */
int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = malloc(sizeof(Dlist));
    if (!new_node)
        return FAILURE;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL)  // Empty list
    {
        *head = new_node;
        *tail = new_node;
    }
    else  // Non-empty list
    {
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }

    return SUCCESS;
}
