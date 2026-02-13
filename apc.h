#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

/* ===================== */
/* Doubly Linked List    */
/* ===================== */
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

/* ===================== */
/* Singly Linked List    */
/* ===================== */
typedef struct snode
{
    int data;
    struct snode *next;
} Slist;

/* ===================== */
/* Utility Functions     */
/* ===================== */
void string_to_list(char *str, Dlist **head, Dlist **tail);
int compare_num(Dlist *head1, Dlist *head2);
void copy_list(Dlist *src, Dlist **dest_head, Dlist **dest_tail);
void print(Dlist *head);

/* ===================== */
/* DLL Operations        */
/* ===================== */
int insert_first(Dlist **head, Dlist **tail, int data);
int insert_last(Dlist **head, Dlist **tail, int data);

/* ===================== */
/* Arithmetic Operations */
/* (TAIL based)          */
/* ===================== */
int add_num(Dlist *tail1, Dlist *tail2,
            Dlist **res_head, Dlist **res_tail);

int sub_num(Dlist *tail1, Dlist *tail2,
            Dlist **res_head, Dlist **res_tail);

int multiplication(Dlist *tail1, Dlist *tail2,
                   Dlist **res_head, Dlist **res_tail);

/* ===================== */
/* Division              */
/* ===================== */
// Use Dlist for input numbers, Slist for quotient
int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Slist **res_head, Slist **res_tail);




#endif /* APC_H */