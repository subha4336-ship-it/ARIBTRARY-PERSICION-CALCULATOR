/*NAME: SUBHASHREE.M
IN THIS PROJECT USING DOUBLE LINKED LIST ARITHMETIC PERCISION CALCULATOR -BASIC AIRTHMETIC FUNCTIONS DONE*/

#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *res_head = NULL, *res_tail = NULL;

    Slist *res_head_div = NULL, *res_tail_div = NULL;

    int sign1 = 1, sign2 = 1, result_sign = 1;

    /* Argument validation */
    if (argc != 4)
    {
        printf("usage: ./apc <num1> <operator> <num2>\n");
        return FAILURE;
    }

    /* Do NOT modify argv directly */
    char *num1_str = argv[1];
    char *num2_str = argv[3];

    /* Handle sign */
    if (num1_str[0] == '-')
    {
        sign1 = -1;
        num1_str++;
    }

    if (num2_str[0] == '-')
    {
        sign2 = -1;
        num2_str++;
    }

    /* Convert strings to DLL */
    string_to_list(num1_str, &head1, &tail1);
    string_to_list(num2_str, &head2, &tail2);

    switch (argv[2][0])
    {
        case '+':
            result_sign = sign1 * sign2;
            add_num(tail1, tail2, &res_head, &res_tail);

            printf("Result: ");
            if (result_sign == -1)
                printf("-");
            print(res_head);
            break;

        case '-':
        {
            int cmp = compare_num(head1, head2);

            if (cmp == 0)
            {
                printf("Result: 0\n");
            }
            else if (cmp > 0)
            {
                sub_num(tail1, tail2, &res_head, &res_tail);
                printf("Result: ");
                if (sign1 == -1)
                    printf("-");
                print(res_head);
            }
            else
            {
                sub_num(tail2, tail1, &res_head, &res_tail);
                printf("Result: ");
                if (sign1 == 1)
                    printf("-");
                print(res_head);
            }
        }
        break;

        case '*':
        case 'x':
        case 'X':
            result_sign = sign1 * sign2;

            if (multiplication(tail1, tail2, &res_head, &res_tail) == SUCCESS)
            {
                printf("Result: ");
                if (result_sign == -1)
                    printf("-");
                print(res_head);
            }
            else
            {
                printf("Multiplication failed\n");
            }
            break;

        case '/':
        {
            /* Division by zero check */
            if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
            {
                printf("Error: Division by zero\n");
                return FAILURE;
            }

            result_sign = sign1 * sign2;

            if (division(head1, tail1,
                         head2, tail2,
                         &res_head_div, &res_tail_div) == SUCCESS)
            {
                printf("Result: ");
                if (result_sign == -1)
                    printf("-");

                Slist *curr = res_head_div;
                while (curr)
                {
                    printf("%d", curr->data);
                    curr = curr->next;
                }
                printf("\n");
            }
            else
            {
                printf("Division failed\n");
            }
        }
        break;

        default:
            printf("Invalid operator\n");
            return FAILURE;
    }

    return SUCCESS;
}



