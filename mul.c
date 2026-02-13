#include "apc.h"

int multiplication(Dlist *tail1, Dlist *tail2,
                   Dlist **res_head, Dlist **res_tail)
{
    /* If either number is 0 */
    if (!tail1 || !tail2)
        return FAILURE;

    /* Final result list */
    *res_head = NULL;
    *res_tail = NULL;

    Dlist *t1 = tail1;
    int shift = 0;   // position shift (like multiplying by 10, 100...)

    /* Outer loop → each digit of first number */
    while (t1)
    {
        int carry = 0;

        Dlist *t2 = tail2;      //  RESET for every digit
        Dlist *temp_head = NULL;
        Dlist *temp_tail = NULL;

        /* Add zeros for positional shift */
        for (int i = 0; i < shift; i++)
            insert_first(&temp_head, &temp_tail, 0);

        /* Inner loop → multiply with second number */
        while (t2)
        {
            int prod = (t1->data * t2->data) + carry;
            int digit = prod % 10;
            carry = prod / 10;

            insert_first(&temp_head, &temp_tail, digit);

            t2 = t2->prev;     //  correct direction
        }

        /* If carry remains */
        if (carry)
            insert_first(&temp_head, &temp_tail, carry);

        /* Add partial result to final result */
        if (*res_head == NULL)
        {
            *res_head = temp_head;
            *res_tail = temp_tail;
        }
        else
        {
            Dlist *sum_h = NULL;
            Dlist *sum_t = NULL;

            add_num(*res_tail, temp_tail, &sum_h, &sum_t);

            *res_head = sum_h;
            *res_tail = sum_t;
        }

        shift++;            // move to next digit position
        t1 = t1->prev;      //  correct traversal
    }

    return SUCCESS;
}
