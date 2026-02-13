#include"apc.h"
int sub_num(Dlist *t1, Dlist *t2,
            Dlist **res_head, Dlist **res_tail)
{
    int borrow = 0;

    while (t1)
    {
        int diff = t1->data - borrow;
        if (t2)
        {
            diff -= t2->data;
            t2 = t2->prev;
        }

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        insert_first(res_head, res_tail, diff);
        t1 = t1->prev;
    }
    return SUCCESS;
}