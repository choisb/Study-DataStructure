#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)  // �� ������ ���� �켱���� ����
{
    switch (op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }
    return -1;
}

int WhoPrecOp(char op1, char op2)   // �� �������� �켱������ ���Ͽ��� 1, -1, 0 ��ȯ
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec)
        return 1;
    else if (op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPNExp(char exp[])   // ������ Ȱ���ؼ� ����ǥ�⸦ ����ǥ���
{
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(expLen + 1);

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char) * expLen + 1);
    StackInit(&stack);

    for (i = 0; i < expLen; i++)
    {
        tok = exp[i];   // ���ڿ����� tok�� �ϳ� ���� ��

        if (isdigit(tok))   // tok�� ���ڶ��
        {
            convExp[idx++] = tok;
        }
        else                // tok�� �����ڶ��
            switch (tok)
            {
            case '(':       //'(' �� ��� ���ÿ� push�� �Ѵ�.
                SPush(&stack, tok); 
                break;

            case ')':       //')' �� ��� '(' �����ڱ� ���ö� ���� ��� �����ڸ� pop�Ѵ�.
                while (1)
                {
                    popOp = SPop(&stack);
                    if (popOp == '(')
                        break;
                    convExp[idx++] = popOp;
                }
                break;

            case '+':   // ��Ģ������ �ϰ�� �켱������ �Ǵ��ؼ� Pop�� Push�� �Ѵ�.
            case '-':
            case '*':
            case '/':
                while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                    convExp[idx++] = SPop(&stack);
            
                SPush(&stack, tok);
                break;      
            }
    }
    while (!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);

    strcpy_s(exp, expLen +1, convExp);
    free(convExp);
}
