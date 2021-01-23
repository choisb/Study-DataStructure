# Dubly Linked List
## 📝목차
- [양방향 연결 리스트의 이해](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList#-양방향-연결-리스트의-이해)
- [양방향 연결 리스트의 구현](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList#-양방향-연결-리스트의-구현)
___
## ✔ 양방향 연결 리스트의 이해
##### 양방향 연결 리스트 란
- 양방향 연결 리스트는 노드가 양쪽 방향으로 연결된 구조의 리스트이다.
  - `Node` 구조체에 `(Node*) prev` 포인터 라는 변수를 하나 두어 메모리를 더 사용한다.
  - 대신 `LPrevious()`함수가 O(1) 시간만 소모된다. (앞에 노드 탐색이 쉬워진다.)

    - `prev` 변수가 없다면 `LPrevious()` 함수를 사용하기 위해서는 O(n) 만큼의 시간이 필요했다. (시간 복잡도와 공간 복잡도 사이의 trad-off관계)

- 단순 연결리스트와 양방향 연결 리스트 중 어느것이 항상 좋다고 말 할수는 없다.

##### 양방향 연결 리스트의 종류
- 양방향 연결 리스트도 단순 리스트처럼 다양한 종류가 있을 수 있다. 대표적으로는 아래와 같은 것들이 있다.

  - 기본 양방향 연결 리스트 
  - 더미 노드 양방향 연결 리스트
  - 원형 연결 기반의 양방향 연결 리스트

[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList#dubly-linked-list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)

___
## ✔ 양방향 연결 리스트의 구현
- 양방향 연결 리스트 구현의 상세 내용에 대해서는 소스코드의 주석으로 대체.
  - 기본 양방향 연결 리스트 코드: [`DBLinkedList`](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList/DBLinkedList)
  - 더미 노드 양방향 연결 리스트 코드: [`DBDLinkedList`](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList/DBDLinkedList)
 
- 아래에는 양방향 연결 리스트의 ADT와 구현과정에 등장하는 몇 가지 주요 아이디어만 서술.


##### 양방향 연결 리스트의 ADT

> 원형 연결 리스트의 ADT
```c
void ListInit(List * plist);
// 초기화할 리스트의 주소 값을 인자로 전달한다.
// 리스트 생성 후 제일 먼저 호출되어야 하는 함수이다.

void LInsert(List * plist, LData data);
// 리스트의 앞에서 부터 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.

int LFirst(List * plist, LData * pdata);
// 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
// 데이터의 참조를 위한 초기화가 진행된다.
// 참조 성공 시 TRUE(1), 실패시 FALSE(0)반환.

int LNext(List * plist, LData * pdata);
// 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
// 순차적인 참조를 위해서 반복 호출이 가능하다.
// 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다.
// 참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환.

int LPrevious(List * plist, LData * pdata);
// 참조된 데이터의 이전 데이터가 pdata가 가리키는 메모리에 저장된다.
// 순차적인 참조를 위해서 반복 호출이 가능하다.
// 참조를 새로 시작하려면 먼저 LFirst 함수를 호출해야 한다.
// 참조 성공 시 TRUE(1), 실패 시 FALSE(0) 반환. 

LData LRemove(List * plist);
// LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
// 삭제된 데이터는 반환된다.
// 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.

int LCount(List * plist);
// 리스트에 저장되어 있는 데이터의 수를 반환한다.
```  
  
##### 더미노드 기반 양방향 연결 리스트
- 더미 노드의 장점은 앞서 단순 연결 리스트를 구현할때 다룬적이 있다. [(보러가기)](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#더미-노드-추가)

- 양방향 연결 리스트에서 더미 노드를 사용하면 데이터 추가 삭제시 처리할 예외가 줄어서 **일반화**가 쉬워진다.
  - 삽입 삭제 중 **데이터 삭제**시 예외처리가 어떻게 달라지나 살펴본다.

    - **기본 양방향 연결 리스트**
    > `DBLinkedList.c`
  ```c
    LData LRemove(List * plist)
    {
        Node* rpos = plist->cur; 
        LData rdata = rpos->data;

        // 리스트에 현재 노드 뿐인 경우
        if (plist->cur->prev == NULL && plist->cur->next == NULL)   
        {
            plist->head = NULL;
            plist->cur = NULL;
        }
        // 현재 노드가 리스트의 가장 앞에 있는 경우
        else if (plist->cur->prev == NULL)  
        {
            plist->head = plist->cur->next;
            plist->cur->next->prev = NULL;

            plist->cur = plist->head;
        }
        // 현재 노드가 리스트의 가장 뒤에 있는 경우
        else if (plist->cur->next == NULL)  
        {
            plist->cur->prev->next = NULL;

            plist->cur = plist->cur->prev;
        }
        // 현재 노드의 앞뒤로 노드가 있는 경우
        else 
        {
            plist->cur->prev->next = rpos->next;
            plist->cur->next->prev = rpos->prev;

            plist->cur = plist->cur->prev;
        }

        // 노드를 메모리에서 해제
        free(rpos);

        (plist->numOfData)--;
        return rdata;
    }
  ```
    - 더미노드 기반 양방향 연결 리스트
    > `DBDLinkedList.c`
  ```c
    // head 더미노드와 tail 더미노드가 존재하기 때문에
    // cur->next와 cur->prev는 항상 NULL이 아님을 보장받을 수 있다.
    // 따라서 별다른 예외처리가 필요 없다.
    LData LRemove(List * plist)
    {
        Node* rpos = plist->cur;
        LData rdata = rpos->data;

        plist->cur->prev->next = plist->cur->next;
        plist->cur->next->prev = plist->cur->prev;

        plist->cur = plist->cur->prev;
        free(rpos);

        (plist->numOfData)--;
        return rdata;
    }
  ```

[(위로)](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList#dubly-linked-list) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___