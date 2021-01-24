#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for (i = 0; i < expLen; i++)
    {
        tok = exp[i];       // �� ���ھ� tok�� ����
        if(isdigit(tok))
        {
            SPush(&stack, tok - '0');   // tok�� ������ ��� ���ڷ� ��ȯ �� ���ÿ� PUSH
        }
        else // ������ �ƴ� �����ڶ��,
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok) // �����ϰ� �� ����� �ٽ� ���ÿ� PUSH!
            {
            case '+':
                SPush(&stack, op1 + op2);
                break;
 
            case '-':
                SPush(&stack, op1 - op2);
                break;

            case '*':
                SPush(&stack, op1 * op2);
                break;

            case '/':
                SPush(&stack, op1 / op2);
                break;
            }
        }
    }
    return SPop(&stack);    // ������ ���� ����� ���ÿ��� ������ ��ȯ
}