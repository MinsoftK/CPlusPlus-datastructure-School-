
/*
*	@brief	원형큐에 대한 선언부
*	@date	2019.10.06 
*	@author	김민성
*/

#pragma once
#include <iostream>
#include <string>

#define maxQueue 30

template <typename T>
class CircularQueue
{
public:
	/**
	*	@brief	Allocate dynamic array whose size is maxQueue.
	*	@pre	The maxQueue is defined
	*	@post	Member of items points the allocated array.
	*/
	CircularQueue();

	/**
	*	@brief	Allocate dynamic array whose size is max.
	*	@pre	none.
	*	@post	Member of items points the allocated array.
	*/
	CircularQueue(int max);

	/**
	*	@brief	Destruct the object. Free the array dynamically allocated.
	*	@pre	Release memory for queue pointer.
	*	@post	none.
	*/
	~CircularQueue();


	/**
	*	@brief	Determines whether the queue is full.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is full)
	*/
	bool IsFull();

	/**
	*	@brief	Determines whether the queue is empty.
	*	@pre	Queue has been initialized.
	*	@post	Function value = (queue is empty)
	*/
	bool IsEmpty();

	/**
	*	@brief	Makes the queue empty.
	*	@pre	Queue has been initialized.
	*	@post	m_iFront와 m_iRear is set same value as Constructer.
	*/
	void MakeEmpty();

	/**
	*	@brief	Adds newItem to the last of the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is full), FullQueue exception is thrown; otherwise, newItem is at the last.
	*/
	bool EnQueue(T item);

	bool DeQueue();

	/**
	*	@brief	Removes first item from the queue.
	*	@pre	Queue has been initialized.
	*	@post	If (queue is empty), EmptyQueue exception is thrown; otherwise, first element has been removed from queue. item gets value of removed item.
	*/
	bool DeQueue(T& item);

	/**
	*	@brief	Print all the items in the queue on screen
	*	@pre	Queue has been initialized.
	*	@post	None.
	*/
	void Print();

private:
	int m_iFront;	//index of one infront of the first element.
	int m_iRear;	//index of the last element.
	int m_nMaxQueue;	//max size of the queue.
	T* m_pItems;	//pointer for dynamic allocation.
	
};

//Allocate dynamic array whose size is maxQueue.
template <typename T>
CircularQueue<T>::CircularQueue()
{
	m_pItems = new T[maxQueue];	//m_pItems에 크기가 maxQueue인 배열을 만든다.
	m_nMaxQueue = maxQueue;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//멤버 변수들을 초기화시켜준다.

}

//Allocate dynamic array whose size is max.
template <typename T>
CircularQueue<T>::CircularQueue(int max)
{
	m_pItems = new T[max];	//m_pItems에 크기가 max인 배열을 만든다.
	m_nMaxQueue = max;
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//멤버 변수들을 초기화시켜준다.

}

//Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueue<T>::~CircularQueue()
{
	delete[] m_pItems;	//동적할당했던 메모리를 해제해준다.
}

//Determines whether the queue is full.
template <typename T>
bool CircularQueue<T>::IsFull()
{
	if (m_iFront - m_iRear == 1 || m_iRear - m_iFront == m_nMaxQueue - 1)
		return 1;	//m_iFront가 m_iRear보다 1 앞일때는 꽉 찬것이므로 1을 리턴한다. m_iFront가 0일때는 m_iRear가 m_nMaxQueue-1과 같을때 꽉 찬것이다.
	return 0;	//꽉 차지 않았으면 0을 리턴한다.
}

//Determines whether the queue is empty.
template <typename T>
bool CircularQueue<T>::IsEmpty()
{
	if (m_iFront == m_iRear)
		return 1;	//m_iFront와 m_iRear가 같은 경우는 queue가 비어있는 상태이므로 1을 리턴한다.
	return 0;	//비어있지 않으면 0을 리턴한다.
}

//Makes the queue empty.
template <typename T>
void CircularQueue<T>::MakeEmpty()
{
	m_iFront = m_nMaxQueue - 1;
	m_iRear = m_nMaxQueue - 1;	//생성자와 같은 값으로 m_iFront와 m_iRear를 변경해준다.
}

//Adds newItem to the last of the queue.
template <typename T>
bool CircularQueue<T>::EnQueue(T item)
{
	if (IsFull())
		return false;	//꽉 찼을땐 throw FullQueue

	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	m_pItems[m_iRear] = item;	//m_iRear를 1증가시켜주고 item값을 넣어준다.
	
	return true;
}

//Overloading..
template <typename T>
bool CircularQueue<T>::DeQueue()
{
	if (IsEmpty())
		return false;

	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	
	//item = m_pItems[m_iFront];	//m_iFront를 1 증가시켜주고 삭제될 값을 item에 복사해준다.
	return true;
}

//Removes first item from the queue.
template <typename T>
bool CircularQueue<T>::DeQueue(T & item)
{
	if (IsEmpty())
		return false;

	m_iFront = (m_iFront + 1) % m_nMaxQueue;
	item = m_pItems[m_iFront];	//m_iFront를 1 증가시켜주고 삭제될 값을 item에 복사해준다.
	
	return true;
}

template <typename T>
void CircularQueue<T>::Print() {
	if (m_iFront > m_iRear) {
		for (int i = m_iFront + 1; i < m_nMaxQueue; i++) {
			m_pItems[i].DisPlayRecordOnScreen();
			cout << "===================================" << endl;
		}
		for (int i = 0; i <= m_iRear; i++) {
			m_pItems[i].DisPlayRecordOnScreen();
			cout << "===================================" << endl;
		}
	}
	else {
		for (int i = m_iFront + 1; i <= m_iRear; i++) {
			m_pItems[i].DisPlayRecordOnScreen();
			cout << "===================================" << endl;
		}
	}
	cout << endl;
}
