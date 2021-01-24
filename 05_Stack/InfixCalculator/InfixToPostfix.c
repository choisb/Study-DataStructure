#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)  // 각 연산자 마다 우선순위 지정
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

int WhoPrecOp(char op1, char op2)   // 각 연산자의 우선순위를 비교하여서 1, -1, 0 반환
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

void ConvToRPNExp(char exp[])   // 스택을 활용해서 중위표기를 후위표기로
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
        tok = exp[i];   // 문자열에서 tok을 하나 받은 후

        if (isdigit(tok))   // tok이 숫자라면
        {
            convExp[idx++] = tok;
        }
        else                // tok이 연산자라면
            switch (tok)
            {
            case '(':       //'(' 일 경우 스택에 push만 한다.
                SPush(&stack, tok); 
                break;

            case ')':       //')' 일 경우 '(' 연산자까 나올때 까지 모든 연산자를 pop한다.
                while (1)
                {
                    popOp = SPop(&stack);
                    if (popOp == '(')
                        break;
                    convExp[idx++] = popOp;
                }
                break;

            case '+':   // 사칙연산자 일경우 우선순위를 판단해서 Pop과 Push를 한다.
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
