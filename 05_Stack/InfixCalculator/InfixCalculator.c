#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char * expcpy = (char*)malloc(len + 1); // 문자열 저장공간 마련
    strcpy_s(expcpy, len + 1, exp);                    // exp를 expcpy에 복사

    ConvToRPNExp(expcpy);       // 후위 표기법의 수식으로 변환
    ret = EvalRPNExp(expcpy);   // 변환된 수식의 계산

    free(expcpy);       // 문자열 저장곤간 해제
    return ret;         // 계산 결과 반환
}