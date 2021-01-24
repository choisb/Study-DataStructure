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
        tok = exp[i];       // 한 문자씩 tok에 저장
        if(isdigit(tok))
        {
            SPush(&stack, tok - '0');   // tok이 정수일 경우 숫자로 변환 후 스택에 PUSH
        }
        else // 정수가 아닌 연산자라면,
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch (tok) // 연산하고 그 결과를 다시 스택에 PUSH!
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
    return SPop(&stack);    // 마지막 연산 결과를 스택에서 꺼내어 반환
}