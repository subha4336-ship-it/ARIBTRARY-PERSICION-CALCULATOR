#include "apc.h"

int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Slist **res_head, Slist **res_tail)
{
    /* Division by zero */
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    /* dividend < divisor → quotient = 0 */
    if (compare_num(head1, head2) < 0)
    {
        Slist *n = malloc(sizeof(Slist));
        n->data = 0;
        n->next = NULL;
        *res_head = *res_tail = n;
        return SUCCESS;
    }

    /* Make working copy of dividend */
    Dlist *work_h = NULL, *work_t = NULL;
    copy_list(head1, &work_h, &work_t);

    int quotient = 0;

    /* Repeated subtraction */
    while (compare_num(work_h, head2) >= 0)
    {
        Dlist *new_h = NULL, *new_t = NULL;

        /* work = work - divisor (TAIL BASED) */
        sub_num(work_t, tail2, &new_h, &new_t);

        /* Free old work list */
        while (work_h)
        {
            Dlist *tmp = work_h;
            work_h = work_h->next;
            free(tmp);
        }

        /* Remove leading zeros */
        while (new_h && new_h->data == 0 && new_h->next)
        {
            Dlist *tmp = new_h;
            new_h = new_h->next;
            new_h->prev = NULL;
            free(tmp);
        }

        work_h = new_h;
        work_t = new_t;

        quotient++;
    }

    /* Store quotient in SLL */
    *res_head = *res_tail = NULL;

    if (quotient == 0)
    {
        Slist *n = malloc(sizeof(Slist));
        n->data = 0;
        n->next = NULL;
        *res_head = *res_tail = n;
        return SUCCESS;
    }

    while (quotient > 0)
    {
        Slist *n = malloc(sizeof(Slist));
        n->data = quotient % 10;
        n->next = *res_head;
        *res_head = n;
        if (*res_tail == NULL)
            *res_tail = n;
        quotient /= 10;
    }

    return SUCCESS;
}


