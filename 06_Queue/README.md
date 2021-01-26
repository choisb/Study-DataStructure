# Queue
## 📝 목차
- [큐의 이해와 ADT 정의](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue#-큐의-이해와-ADT-정의)
- [큐의 구현](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue#-큐의-구현)
- [큐의 활용](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue#-큐의-활용)
- [Deque](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue#-deque)
___

## ✔ 큐의 이해와 ADT 정의
##### 📍 큐의 이해
- 큐는 먼저 들어간 데이터가 먼저 나오는 구조이다. **선입선출** 혹은 **FIFO**(First-In, First-Out)이라고도 한다.


##### 📍 큐 ADT의 정의
> 큐 자료구조의 ADT
```c
void QueueInit(Queue * pq);
// 큐의 초기화를 진행한다.
// 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.

int QIsEmpty(Queue * pq);
// 큐가 빈 경우 TURE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

void Enqueue(Queue * pq, Data data);
// 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.

Data Dequeue(Queue * pq);
// 저장순서가 가장 앞선 데이터를 삭제한다.
// 삭제된 데이터는 반환된다.
// 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

Data QPeek(Queue * pq);
// 저장순사가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
// 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
```

[
[위로](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue#Queue) 
/ 
[처음으로](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
]
___

## ✔ 큐의 구현
- 큐의 구현은 배열기반 구현과, 리스트 기반 구현이 있다.

##### 📍 배열 기반의 원형 큐 구현
- 배열을 기반으로한 원형 큐를 구현할 때 한 가지 문제가 있다.

- 큐의 데이터가 입력되는 뒤쪽(R)과 큐의 데이터가 빠져나오는 앞쪽(F)의 위치 만으로는
 텅빈 경우와 꽉찬 경우를 구분할 수 없다.

- 이 문제를 해결하는 다양한 방법들이 존재하는데 여기서는 **배열을 꽉 채우지 않는** 방법으로 해결한다.
  - 저장 공간을 하나 활용하지 못한다는 단점
  - 별도의 변수없이 R과 F의 위치만으로 꽉찬 경우와 텅빈 경우를 구분할 수 있다.

- 배열기반 큐의 소스코드: [`CircularQueue`](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue/CircularQueue)

- 리스트기반 큐의 소스코드: [`ListBaseQueue`](https://github.com/choisb/Study-DataStructure/tree/master/06_Queue/ListBaseQueue)

## ✔ 덱(Deque)의 이해와 구현

- 덱(Deque) 이란 Double - ended queue의 약자로 데이터를 양방향으로 넣을 수도 뺄 수도 있는 자료구조이다.
- 때문에 덱은 스택과 큐의 특성을 모두 갖는 혹은 스택과 큐를 조합한 형태의 자료구조로 이해된다.

##### 📍 덱(Deque) 자료구조의 ADT
```c
void DequeInit(Deque * pdeq);
// 덱의 초기화를 진행한다.
// 덱 생성 후 제일 먼저 호출되어야 하는 함수이다.

int DQIsEmpty(Deque * pdeq);
// 덱이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.

void DQAddFirst(Deque * pdeq, DAta data);
// 덱의 머리에 데이터를 저장한다. data로 전달된 값을 저장한다.

void DQAddLast(Deque * pdeq, Data data);
// 덱의 꼬리에 데이터를 저장한다. data로 전달된 값을 저장한다.

Data DQRemoveFirst(Deque * pdeq);
// 덱의 머리에 위치한 데이터를 반환 및 소멸한다.

Data DQRemoveLast(Deque * pdeq);
// 덱의 꼬리에 위치한 데이터를 반환 및 소멸한다.

Data DQGetFirst(Deque * pdeq);
// 덱의 머리에 위치한 데이터를 소멸하지 않고 반환한다.

Data DQGetLast(Deque * pdeq);
//덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환한다.
```