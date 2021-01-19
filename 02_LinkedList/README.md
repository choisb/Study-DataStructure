# Linked List
##  📝목차
- [연결 리스트의 이해](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8%EC%9D%98-%EC%9D%B4%ED%95%B4)
- [단순 연결 리스트 구현](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#-%EB%8B%A8%EC%88%9C-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EA%B5%AC%ED%98%84)
- [단순 연결 리스트 응용](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#-%EB%8B%A8%EC%88%9C-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8%EC%9D%98-%EC%9D%91%EC%9A%A9)

[(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)

___
## ✔ 연결 리스트의 이해
##### 배열 기반 리스트의 특징
- 원하는 위치의 데이터에 바로 접근할 수 있다.
- 메모리의 특성이 정적이어서 전체 저장공간의 크기를 변경하는 것이 불가능하다.
- 원하는 위치에 데이터를 삽입 삭제하는 것이 불편하다.

##### 연결 리스트의 특징
- 원하는 위치의 데이터에 바로 접근할 수 없다.
- 필요할때 마다 메모리를 할당 해제할 수 있다.
- 리스트의 중간지점에서 노드를 삽입하거나 삭제하기 쉽다.

##### 연결 리스트의 종류
- [단순 연결 리스트](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#-%EB%8B%A8%EC%88%9C-%EC%97%B0%EA%B2%B0-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EA%B5%AC%ED%98%84)
- 원형 연결 리스트
- 이중 연결 리스트

[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#linked-list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___
## ✔ 단순 연결 리스트 구현
- 단순 연결 리스트는 연결의 형타가 한쪽 방향으로 전개되고 시작과 끝이 분명히 존재한다.
![단순 연결 리스트 도표](../img/01_LinkedList.png)

##### 단순 연결 리스트의 종류
- 새 노드를 앞에서부터 추가
  - 장점: 포인터 변수 tail이 필요 없다.
  - 단점: 저장된 순서를 유지하지 않는다.
  
- 새 노드를 뒤에서 추가
  - 장점: 저장된 순서가 유지된다.
  - 단점: 포인터 변수 tail이 필요하다.

>여기서는 새 노드를 앞에서부터 추가하는 방식으로 구현할 예정. 
왜냐하면, 리스트는 반드시 저장 순서를 유지해야하는 자료구조가 아니기 때문에
개발의 편의성 면에서 tail이 필요없는 방식을 택함. 

##### 단순 연결 리스트의 구현
- 단순 연결 리스트 구현의 상세 내용에 대해서는 소스코드의 주석으로 대체.
  - [`DlinkedList` 소스](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList/DLinkedList)
- 아래에는 단순 연결 리스트의 ADT와 구현과정에 등장하는 몇 가지 주요 아이디어만 서술.

##### 단순 연결 리스트의 ADT 정의
- 앞서 다룬 List의 ADT는 모든 List들이 필수로 가져야 할 기능들이 모두 정의되어 있기 때문에 그대로 적용할 수 있다.
- 하지만 리스트에 정렬 관련 기능을 추가하기 위해서 조금 더 확장된 ADT를 정의한다.
 
> 단순 연결 리스트의 ADT
```c
void ListInit(List * plist);
// 초기화할 리스트의 주소 값을 인자로 전달한다.
// 리스트 생성 후 제일 먼저 호출되어야 하는 함수이다.

void LInsert(List * plist, LData data);
// 리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.

int LFirst(List * plist, LData * pdata);
// 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
// 데이터의 참조를 위한 초기화가 진행된다.
// 참조 성공 시 TRUE(1), 실패시 FALSE(0)반환

int LNext(List * plist, LData * pdata);
// 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
// 순차적인 참조를 위해서 반복 호출이 가능하다.
// 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다.
// 참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환

LData LRemove(List * pdata);
// LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
// 삭제된 데이터는 반환된다.
// 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.

int LCount(List * plist);
// 리스트에 저장되어 있는 데이터의 수를 반환한다.

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));
// 리스트에 정렬의 기준이 되는 함수를 등록한다.
```

- `SetSortRule()`함수를 살펴보자. 데이터를 정렬하기 위해서는 **데이터의 크기를 비교**할 수 있어야 한다.
- 데이터가 정수라면 쉽게 비교할 수 있지만 데이터가 알파벳의 순서나 이름 등 **사용자 정의 구조체**일 경우 **별도의 비교 기준**(함수)이 필요하다.
- 이를 사용자가 비교함수를 등록할 수 있도록 **함수 포인터**를 사용한다. comp가 참조할 함수의 예시는 다음과 같다.
  - 매개변수 `d1`에 전달되는 인자가 정렬 순서상 앞서서 `head`에 더 가까워야 하는 경우에는 `0`을 반환하고, 아닌 경우에 `1`을 반환한다.
  
    ```c
    int WhoIsPrecede(LData d1, Ldata d2)
    {
        if(d1 < d2)
            return 0;   // d1이 정렬 순서상 앞선다.
        else
            return 1;   // d2가 정렬 순서상 앞서거나 같다.
    }
    ``` 
##### 더미 노드 추가
- 연결 리스트에서 첫 번째 노드는 포인터 변수 head가 가리킨다는 점에서 다른 노드들과 차이가 있다.
- 때문에 노드를 추가, 삭제 그리고 조회할때 첫 번째 노드에 대한 접근은 다른 노드와 차이를 둬야 했다.
- 앞으로 구현할 연결 리스트에서는 그 차이가 더 커지기 때문에 Head 노드 이후 첫 번째 노드에 아무런 의미 없는 Dummy Node를 삽입하여 이 문제를 해결한다.

> 기존의 연결리스트

![단순 연결 리스트 도표](../img/01_LinkedList.png)

> 더미 노드가 추가된 연결리스트

![더미 노드 연결리스트 도표](../img/02_DLinkedList.png)

##### 정렬 기능이 추가된 연결 리스트의 구조체와 헤더파일 
- 연결 리스트의 구현을 위해서 다음과 같은 `Node` 구조체 정의는 필수 적이다.
```c
typedef struct _node
{
    LData data; // typedef int LData
    struct _node * next;
}Node;
```
- 하지만 종종 연결 리스트의 구현에 필요한 다음 유형의 변수들은 구조체로 묶지 않고 main 함수의 지역변수나 전역변수로 선언하기도 한다.
```c
    Node * head;    // 연결 리스트의 머리를 가리키는 포인터 변수
    Node * cur;     // 참조를 위한 포인터 변수
```
- 이들은 다음과 같은 이유로 반드시 main함수의 지역변수나 전역변수가 아니라 다음과 같이 구조체로 정의되어야 한다.
  - 한 프로그램에서 다수의 리스트가 필요한 경우를 위해서.
  - 리스트를 사용하기 위해 필요한 변수들을 모두 하나의 구조체에 묶어서 **모듈**화 하기 위함.
```c
typedef struct _linkedList
{
    Node * head;                        // 더미 노드를 가리키는 멤버
    Node * cur;                         // 참조 및 삭제를 돕는 멤버
    Node * before;                      // 삭제를 돕는 멤버
    int numOfData;                      // 저장된 데이터의 수를 기록하기 위한 멤버
    int (*comp)(LData d1, LData d2);    // 정렬의 기준을 등록하기 위한 멤버
}LinkedList;
```

[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#linked-list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)

___
## ✔ 단순 연결 리스트의 응용
- 앞선 예제에서는 `Ldata`를 `int`로 선언하여서 사용하였다.
- `01_List` 장에서 다뤘던것 처럼 `LData`를 `Point`구조체의 주소값을 저장해서 사용할 수도 있다.
- [`PointDLinkedList` 소스](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList/PointDLinkedList)
- 이때 주의해야할 점은 정렬을 위해서 사용한 사용자 정의 비교함수이다.
    ```c
    // Ldata가 int일 때 WhoIsPrecede() 함수
    int WhoIsPrecede(int d1, int d2)
    {
        if (d1 < d2)
            return 0;   // d1이 정렬 순서상 앞선다.
        else
            return 1;   // d2가 정렬 순서상 앞선다.
    }
    ```
- `LinkedList`를 만들때 사용자가 연결 리스트의 정렬 기준을 결정하도록 유연성을 
부여한 설계를 위해서 함수 포인터 `(*comp)`로 콜백 함수를 만들었다.
  >`DLinkedList.c`  

    ```c
    ...
    void LInsert(List * plist, LData data)
    {
        if (plist->comp == NULL)
            FInsert(plist, data);   //comp 함수가 등록되지 않았을 경우, 첫 번째 노드 삽입
        else
            SInsert(plist, data);   //comp 함수가 등록되어 있는 경우, comp노드 정렬 기준에 맞는 위치에 노드 삽입.
    }
    ...
    void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
    {
        plist->comp = comp;
    }
    ``` 
  > `DLinkedListMain.c`
    ```c
    int main()
    {
        // DLinked List의 생성 및 초기화 ////
        List list;
        int data;
        ListInit(&list);

        SetSortRule(&list, WhoIsPrecede);  //정렬기준 함수 등록
    ...
    ```
- 따라서 사용자는 다음과 같이 `WhoIsPrecede()`함수를 어떻게 정의하냐에 따라서 오름차순으로 정렬을 할 수도, 사용자 구조체의 정렬 순서를 정할 수도 있다.
- 여기에서는 `Point`구조체의 x좌표를 기준으로 오름차순 정렬을 하도록 만들었다. 
    > `PointListMain.c`
    ```c
    int WhoIsPrecede(Point* d1, Point* d2)
    {
        if (d1->xpos < d2->xpos)  // x좌표 기준으로 오름차순.
            return 0;   
        else
            return 1;   
    }
    ```
[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#linked-list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
