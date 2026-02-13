#include"apc.h"
int add_num(Dlist *t1, Dlist *t2,
            Dlist **res_head, Dlist **res_tail)
{
    int carry = 0;

    while (t1 || t2 || carry)
    {
        int sum = carry;

        if (t1)
        {
            sum += t1->data;
            t1 = t1->prev;
        }

        if (t2)
        {
            sum += t2->data;
            t2 = t2->prev;
        }

        carry = sum / 10;
        insert_first(res_head, res_tail, sum % 10);
    }
    return SUCCESS;
}
    



    
 