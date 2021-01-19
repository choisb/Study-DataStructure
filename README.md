# Data Structure
## 💡프로젝트의 목적 과 구성
- 본 프로젝트는 자료구조에 대한 학습한 내용을 정리하기 위한 프로젝트 입니다.
- 본 프로젝트는 자료구조의 이론과 구현 코드 및 설명으로 구성되어 있습니다.
- 본 프로젝트의 코드는 모두 C언어로 작성했습니다.
- 학습용 프로젝트이기 때문에 일부 오류가 포함되어 있을 수 있습니다.
- 본 프로젝트는 윤성우 저자의 열혈 자료구조를 바탕으로 정리하였습니다.
- 본 프로젝트에서 자료구조 구현에 대한 자세한 설명은 가급적 소스코드 내의 주석으로 대체하며, 각 자료구조의 특징 및 구현 시 특별히 살펴봐야할 지점만 부연 설명을 진행. 

## 📝 프로젝트 목차
- [자료구조란](https://github.com/choisb/Study-DataStructure/blob/master/README.md#-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0%EB%9E%80)
- [추상 자료형: Abstract Data Type (ADT)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#-%EC%B6%94%EC%83%81-%EC%9E%90%EB%A3%8C%ED%98%95-abstract-data-type-adt)
- [List](https://github.com/choisb/Study-DataStructure/tree/master/01_List#list)
  - [배열기반 리스트: ArrayList](https://github.com/choisb/Study-DataStructure/tree/master/01_List#-%EB%B0%B0%EC%97%B4-%EA%B8%B0%EB%B0%98-%EC%88%9C%EC%B0%A8-%EB%A6%AC%EC%8A%A4%ED%8A%B8-%EA%B5%AC%ED%98%84)
  | [소스](https://github.com/choisb/Study-DataStructure/tree/master/01_List/ArrayList)
  - [연결 리스트: Linked List](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList#linked-list)
  | [소스](https://github.com/choisb/Study-DataStructure/tree/master/02_LinkedList/DLinkedList)
  - [원형 연결 리스트: Circular Linked List](https://github.com/choisb/Study-DataStructure/tree/master/03_CircularLinkedList)
  | [소스](https://github.com/choisb/Study-DataStructure/tree/master/03_CircularLinkedList/CLinkedList)
  - [이중 연결 리스트: Double Linked List](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList#dubly-linked-list)
  | [소스](https://github.com/choisb/Study-DataStructure/tree/master/04_DoublyLinkedList/DBDLinkedList)
- Stack and Queue
- Tree
   - Binary Tree
   - Full Binary Tree
   - Complete Binary Tree 
   - BST (Binary Search Tree)  
- Binary Heap  
... 현재 작성중

___
## ✔ 자료구조란
 자료구조란 **데이터를 표현하고, 표현된 데이터를 처리하는 방법**을 뜻한다.

##### 자료구조와 알고리즘
- 자료구조: 데이터의 표현 및 저장 방법
- 알고리즘: 저장된 데이터를 대상으로 하는 문제의 해결 방법

자료구조에 따라서 알고리즘은 달라진다. 즉, **알고리즘은 자료구조에 의존적이다.**

##### 시간 복잡도와 공간 복잡도

- 시간 복잡도(Time Complecity): 알고리즘에 사용되는 연산 횟수(소요 시간)
- 공간 복잡도(Space Complecity): 알고리즘에 사용되는 메모리의 양.  

일반적으로 시간복잡도와 공간 복잡도는 서로 trade-off 관계를 가진다.
어떤 알고리즘을 사용할 것인지 선택하기 위해서는 가용할 수 있는 시간, 공간 자원의 양과 구현의 편의성을 종합적으로 고려하여 선택한다.
이러한 이유로 만능 키와 같은 자료구조와 알고리즘은 없다.

##### 성능 평가

일반적으로 알고리즘을 평가할 때는 메모리의 사용량보다는 실행속도에 초점을 둔다.
- 최선의 경우(best case): 알고리즘을 수행할 때 시간이 가장 짧은 경우. 대부분의 알고리즘의 best case는 큰 차이가 없기 때문에 성능 평가시 사용하지 않는다.
- 최악의 경우(worst case): 알고리즘을 수행할 때 시간이 가장 오래 걸리는 경우. 알고리즘의 성능에 따라서 worst case는 큰 차이를 보인다. 때문에 성능 평가시 중요하게 활용 된다.
- 평균의 경우(average case): 평균 시간 또한 유의미한 데이터다. 하지만, 알고리즘연산에서 소요되는 평균시간을 구하는 것이 어려운 문제이기 때문에 일반적으로 최악의 경우를 기준으로 알고리즘을 평가한다.

> 최악의 경우(worst case)를 통해서 알고리즘의 성능을 표현하면 **알고리즘의 연산 시간을 보장할 수 있다.**
> 이 알고리즘을 사용할 경우 반드시 worst case보다는 짧은 시간에 연산을 마치기 때문이다. 
> 즉, average case를 사용하는 것 보다 worst case를 사용하는 것이 "**신뢰도가 높다.**" 고 할 수 있다.

##### Big-O 표기법

T(n)이 다항식일 경우 최고차항의 차수만 표현한 것을 Big-O 표기법 이라고한다. 

 
> T(n) = n^2^  + 2n + 1 -> O(n^2^) 

데이터의 수 n과 그에 따른 시간 복잡도를 정확히 그리고 오차 없이 구하는 것은 대부분의 경우 쉽지 않다. 
그리고 컴퓨터 공학에서 n의 크기는 상당히 크다.
n의 크기가 커질 수록 최고차항의 비중이 압도적이게 되기 때문에, 알고리즘의 성능을 평가할 때는 Big-O 표기법을 사용한다.

##### 대표적인 Big-O표기는 다음과 같이 존재한다.
- **O(1)**: 상수형 Big-O. 데이터 수에 상관없이 연산횟수가 고정인 유형의 알고리즘.
- **O(logn)**: 로그형 Big-O. 데이터 수의 증가율에 비해서 연산횟수의 증가율이 훨씬 낮은 알고리즘.
- **O(n)**: 선형 Big-O. 데이터의 수와 연산횟수가 비례하는 알고리즘.
- **O(nlogn)**: 선형로그형 Big-O. 데이터가 증가하는 속도보다 연산량이 조금더 증가하는 알고리즘. 이에 해당하는 알고리즘이 많음.
- **O(n^2^)**: 데이터 수의 제곱에 해당하는 연산횟수를 요구하는 알고리즘. 데이터의 양이 많은 경우 적용하기가 다소 부적절한 알고리즘.
- **O(n^3^)**: 데이터 수의 세 제곱에 해당하는 연산횟수를 요구하는 알고리즘. 주로 삼중 중첩 반복문에서 발생하며 그냥 적용하기에 부적절한 알고리즘.

[(위로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___
## ✔ 추상 자료형: Abstract Data Type (ADT)
##### 추상 자료형 이란?
- 구체적인 기능의 완성과정을 언급하지 않고, **순수하게 기능이 무엇인지를 나열**한 것.
- 모든 자료구조에서 ADT를 정의할 때는 **자료구조의 구현**과 **구현된 자료구조의 활용**이 완전 분리될 수 있어야 한다.

##### 추상 자료형의 예시
>`Wallet` 의 ADT
```c
int TakeOutMoney(Wallet *pw, int coinNum, int billNum); 
// pw: 돈을 꺼낼 지갑의 주소값.
// coinNum: 지갑에서 꺼낼 동전의 수.
// billNum: 지갑에서 꺼낼 지폐의 수.
// 기능: 지갑에서 꺼내고자 하는 돈의 총 액이 반환되고 그 금액만큼 pw 지갑에서 차감.
 
void PutMoney(Wallet *pw, int coinNum, int billNum);
// pw: 돈을 넣을 지갑의 주소값.
// coinNum: 지갑에 넣을 동전의 수
// billNum: 지갑에 넣을 지폐의 수
// 기능: 지갑에 넣으려고 하는 돈의 총 액이 반환되고 그 금액만큼 pw 지갑에 증가.
```
- 이때 `Wallet` 구조체는 추상 자료형(ADT)에 해당하지 않는다. (`Wallet`은 자료구조에 해당한다.)
- 사용자가 지갑에 돈을 넣고, 빼는 기능을 사용하고자 할때 `Wallet`의 내부까지 아는 것은 불필요기 때문이다.
- 대표적인 사례로 우리가 C언어에서 파일 입출력 기능을 사용할 때 `FILE` 구조체 내부를 궁금해 하지는 않는다. 

##### 자료구조 학습에 추상자료형 정의 적용
- 앞으로 다룰 자료구조에는 아래와 같은 순서를 적용한다.
  - 자료구조의 ADT를 정의한다.
  - ADT를 근거로 자료구조를 사용하는 main 함수를 정의한다. (사용자측 코드)
  - ADT를 근거로 자료구조를 구현한다.

[(위로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure) / [(처음으로)](https://github.com/choisb/Study-DataStructure/blob/master/README.md#data-structure)
___