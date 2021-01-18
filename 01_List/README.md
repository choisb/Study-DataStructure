# List
## 📝 목차
- [리스트 자료구조의 이해](https://github.com/choisb/Study-DataStructure/tree/master/01_List#-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%EC%9D%98-%EC%9D%B4%ED%95%B4)
- [배열 기반 순차 리스트 구현](https://github.com/choisb/Study-DataStructure/tree/master/01_List#-%EB%B0%B0%EC%97%B4-%EA%B8%B0%EB%B0%98-%EC%88%9C%EC%B0%A8-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EA%B5%AC%ED%98%84)
- [리스트에 구조체 변수 저장하기](https://github.com/choisb/Study-DataStructure/tree/master/01_List#-%EB%A6%AC%EC%8A%A4%ED%8A%B8%EC%97%90-%EA%B5%AC%EC%A1%B0%EC%B2%B4-%EB%B3%80%EC%88%98-%EC%A0%80%EC%9E%A5%ED%95%98%EA%B8%B0)
- [배열기반 리스트의 장점과 단점](https://github.com/choisb/Study-DataStructure/tree/master/01_List#-%EB%B0%B0%EC%97%B4%EA%B8%B0%EB%B0%98-%EB%A6%AC%EC%8A%A4%ED%8A%B8%EC%9D%98-%EC%9E%A5%EC%A0%90%EA%B3%BC-%EB%8B%A8%EC%A0%90)

[(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___
## ✔ 리스트 자료구조의 이해
먼저 리스트에 대한 대표적인 오해를 짚을 필요가 있다.

> "List는 연결 리스트를 의미한다." (X)

리스트라는 자료구조는 **구현 방법**에 따라서 다음의 두가지로 나뉜다. 
즉, 리스트라고 해서 반드시 연결 리스트를 의미하는 것은 아니다.
- [순차 리스트: 배열을 기반으로 구현된 리스트](https://github.com/choisb/Study-DataStructure/tree/master/01_List#-%EB%B0%B0%EC%97%B4-%EA%B8%B0%EB%B0%98-%EC%88%9C%EC%B0%A8-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EA%B5%AC%ED%98%84)
- [연결 리스트: 메모리의 동적 할당을 기반으로 구현된 리스트](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#linked-list)

##### 리스트 자료구조의 공통된 특성
순차 리스트와 연결 리스트는 구현 방법에 따라 구분된다.이 둘의 ADT는 동일 할 수도 있고 상황에 따라 다를 수도 있다. 
하지만 이 두 리스트 자료구조의 **가장 기본적이고도 중요한 특성**은 다음과 같다.

- 리스트 자료구조는 데이터를 나란히 저장한다.
- 리스트 자료구조는 중복된 데이터의 저장을 막지 않는다.  

[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/01_List#list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)

___
## ✔ 배열 기반 순차 리스트 구현
- 배열을 기반으로 구현된 순차 리스트를 구현한다.
- 구현의 순서는 다음과 같다.
  - 리스트 자료구조의 추상 자료형(ADT) 정의
  - 정의된 ADT를 기반으로 정의된 main 함수 작성
  - 정의된 ADT를 기반으로 리스트 구현
  
##### 리스트 자료구조의 추상자료형(ADT)
데이터가 나란히 저장된다는 특성을 기반으로 제공해야 할 기능은 다음과 같다.
> 리스트 자료구조의 ADT
```c
void ListInit(List* plist);
// 초기화할 리스트의 주소 값을 인자로 전달
// 리스트 생성 후 제일 먼저 호출되어야 하는 함수

void LInsert(List* plist, LData data);
// 리스트에 데이터를 저장. 매개변수 data에 전달된 값을 저장.

int LFirst(List* plist, LData* pdata);
// 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
// 데이터의 참조를 위한 초기화가 진행된다.
// 참조 성공시 TRUE(1), 실패시 FALSE(0)반환

int LNext(List* plist, LData* pdata);
// 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
// 순차적인 참조를 위해서 반복 호출이 가능하다.
// 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다.
// 참조 성공시 TRUE(1), 실패시 FALSE(0) 반환

LData LRemove(List* plist);
// LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
// 삭제된 데이터는 반환된다.
// 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.

int LCount(List* plist);
// 리스트에 저장되어 있는 데이터의 수를 반환한다.
```

##### 리스트의 ADT를 기반으로 정의된 main 함수
> [`ListMain.c`](https://github.com/choisb/Study-DataStructure/blob/master/01_List/ArrayList/ListMain.c)

`main()`함수에서 사용자가 `List`를 어떻게 사용할 수 있는지 몇 가지 상황을 살펴보자.
- 리스트의 생성 및 초기화
  - 사용자는 `List` 타입의 list 자료구조를 만들 수 있다.
  - 사용자는 `ListInit()` 함수를 통해서 리스트를 초기화 할 수 있다.
    ```c
        List list;        //리스트 선언
        ...
        ListInit(&list);  //리스트 초기화    
    ```  
- 리스트에 데이터 삽입
  - 사용자는 `LInsert()`함수를 통해서 리스트에 데이터를 삽입할 수 있다.
    ```c
        for (i = 0; i < 10; i++)
            LInsert(&list, i);  //리스트 삽입
    ```
- 리스트에서 데이터 탐색
  - 사용자는 `LFirst()`함수를 통해서 리스트의 첫 번째 데이터에 접근 할 수 있다.
  - 사용자는 `LNext()`함수를 통해서 리스트의 두 번째 이후의 데이터에 접근 할 수 있다.
    - 이것이 가능 한 이유는 리스트 내에서 '데이터의 참조위치'를 기록하고 있기 때문이다.
    ```c
        // 리스트에 있는 모든 데이터 출력
        if (LFirst(&list, &data))   // 첫 번째 데이터를 변수 data에 저장
        {
            printf("%d ", data);

            while (LNext(&list, &data)) // 두 번째 이후의 데이터를 변수 data에 저장
                printf("%d ", data);
        }
        printf("\n\n");
    ```
- 리스트에서 데이터 삭제
  - 사용자는 `LRemove()`함수를 통해서 현재 위치의 데이터를 삭제할 수 있다.
    ```c
        // 2의 배수, 3의 배수 삭제
        if (LFirst(&list, &data))
        {
            if ((data % 2 == 0) || (data % 3 == 0))
                LRemove(&list);

            while (LNext(&list, &data))
            {
                if ((data % 2 == 0) || (data % 3 == 0))
                    LRemove(&list);
            }
        }
    ```

##### 배열 기반 리스트 구현하기
> [`ArrayList` 소스](https://github.com/choisb/Study-DataStructure/tree/master/01_List/ArrayList)

- 소스코드에서 리스트의 삽입, 탐색, 삭제 과정을 잘 살펴보자.

##### 다양한 종류의 데이터와 다양한 종류의 리스트를 지원하기 위한 `typedef`

- 지금은 `int` 데이터를 지원하지만, `typedef`의 선언만 바꾸면 다른 데이터를 지원할 수도 있다.
    ```c
        typedef int LData; // 현재 코드는 int형 데이터만 지원한다.
    ```
- `int`형 뿐만 아니라 `float`이나 `char`등 기본타입은 물론 이고, 구조체 변수의 주소값도 리스트의 데이터로도 사용할 수 있다.
- (뒤에서 사용자가 정의한 `Point`구조체의 주소를 가지는 예제도 다루고 있음.) (링크)
    ```c
        typedef float LData;
    ```
- `ArrayList`에도 `typedef`를 사용하면 사용자 코드의 수정 없이도 다른 자료구조의 `List`로 쉽게 대체할 수도 있다.
    ```c
        typedef ArrayList List;     // ArrayList를 사용하는 List
        typedef LinkedList List;    // LinkedList를 사용하는 List
    ``` 
[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/01_List#list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___
## ✔ 리스트에 구조체 변수 저장하기
> [`PointArrayList` 소스](https://github.com/choisb/Study-DataStructure/tree/master/01_List/PointArrayList)
- 실제로 리스트에서는 구조체 변수를 비롯해서 각종 데이터들이 저장된다.
- 이번 예제에서는 Point 구조체를 데이터로 저장해본다.

> `ArrayList.h`
```c
#include "Point.h"          // Point.h 추가

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100
typedef  Point * LData;     //int -> Point로 변경
```
- `ArrayList.h` 파일에 두줄만 수정하면 Point 구조체를 리스트의 데이터로 사용가능하다.

>`PointListMain.c`
```c
int main()
{
...
    if (LFirst(&list, &ppos))
    {
        if (PointComp(ppos, &comPos) == 0 || PointComp(ppos, &comPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }

        while (LNext(&list, &ppos))
        {
            if (PointComp(ppos, &comPos) == 0 || PointComp(ppos, &comPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }
...
}
``` 
- 데이터를 삭제하는 부분을 살펴보면, `main()`함수에서 사용자가 직접 메모리 해제를 하는 것을 볼 수 있다.
- 일반적인 리스트는 메모리의 해제까지 책임을 지지 않는다.
- 이를 위해서 `LRemove`함수는 삭제된 데이터를 반환하도록 디자인된 것이다.  

[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/01_List#list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___
## ✔ 배열기반 리스트의 장점과 단점
- 배열 기반 리스트의 단점
  - 배열의 길이가 초기에 결정되어야 한다. 변경이 불가능하다.
  - 삭제의 과정에서 데이터의 이동(복사)가 매우 빈번히 일어난다.

- 배열 기반 리스트의 장점
  - 데이터의 참조가 쉽다. 인덱스 값을 기준으로 어디든 한 번에 참조가 가능하다.

- 배열 기반 리스트의 오해
  - 보통 리스트라고 하면 연결 리스트만을 떠올리고, 배열 기반 리스트는 불필요하다는 오해가 있다.
  - 배열 리스트가 가진 장점은 연결 리스트가 가질 수 없는 장점인 만큼, 충분히 가치가 있는 자료구조이고, 배열 기반 리스트는 실제 실무에서도 사용된다.  
  
[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/01_List#list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
