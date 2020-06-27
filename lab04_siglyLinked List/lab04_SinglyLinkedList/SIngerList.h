#pragma once
#include <iostream>
#include <fstream>
#include <string>

#define MAXSIZE 10

using namespace std;

template<class T>
class SortedList
{
private:
	T * m_Array;
	int m_ArraySize;
	int m_Length;
	int m_CurPointer;

public:
	SortedList() {
		m_Array = new T[MAXSIZE];
		m_Length = 0;
		m_ArraySize = 0;
		m_CurPointer = 0;
		ResetList();
	}
	SortedList(int size);
	~SortedList() {
		delete [] m_Array;
	}
	void MakeEmpty();
	int GetLength();
	bool IsFull();
	int Add(T data);
	int Retrieve_SeqS(T& target);
	int Delete(T& target);
	int GetNextItem(T& data);
	void ResetList();
	bool IsEmpty();
	//변경할 정보 입력하는 함수, m_Array 에 변경정보 입력
	int Replace(T data);
	//Singer Name이 일치하는 음악 찾아서 모든 정보를 return 해준다. -> Application RetrieveMusic에 쓰임.
	int RetrieveBySinger(T& target);
	int RetrieveBygenre(T& target);//genre 으로 검색결과 찾는 함수
	int RetrieveByMusicNumber(T & target);
	////Binary Search
	int RetrieveByBS(T& target);
	
};
//cpp


template<typename T>
SortedList<T>::SortedList(int size) {
	m_Array = new T[size];
	m_Length = 0;
	m_ArraySize = 0;
	m_CurPointer = 0;
	ResetList();
}

template<typename T>
void SortedList<T>::MakeEmpty() {
	m_Length = 0;
}
template<typename T>
int SortedList<T>::GetLength() {
	return m_Length;
}
template<typename T>
bool SortedList<T>::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else return false;
}
//data

//Sorted List Add
template<typename T>
int SortedList<T>::Add(T data) {
	int index = GetLength() - 1;
	if (m_Length == 0) { //비어있다면
		m_Array[m_Length++] = data;
	}
	//list가 비면 처음부터 입력
	   //list의 위치를 파악하고 그 위치에 입력
	else {

		for (int i = 0; i <= index; i++) {
			if (data == m_Array[i]) {
				cout << "Same list exist. " << endl;
				return 0;
			}

			else if (data < m_Array[i]) {
				for (int k = index; k >= i; k--) {
					m_Array[k + 1] = m_Array[k];
				}
				m_Array[i] = data;
				m_Length++;
				return 1;
			}
			else if (data > m_Array[index]) {
				m_Array[index + 1] = data;
				m_Length++;
				return 1;
			}

		}
	}

	return 1;
}

//Music Number가 일치한다면 1을 반환한다.


template<typename T>
int SortedList<T>::Retrieve_SeqS(T& target) {

	int index = m_Length - 1;
	ResetList();
	for (int i = 0; i <= index; i++) {
		m_CurPointer++;
		if (target == m_Array[i]) {
			m_Array[i].DisplayRecordOnScreen();
			return 1;
		}

	}
	;//ID 일치가 안하면 0을 반환
}



//Retrieve_SeqS 가 반환하는 1 값 이용 해서 정보 삭제
template<typename T>
int SortedList<T>::Delete(T& target)
{
	if (Retrieve_SeqS(target))//Retrieve_SeqS(target)	//Primary key가 일치하는 item을 발견한다면(1)
	{

		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	else {
		cout << endl << "There is no match item." << endl << endl;
		return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
	}
}
/* 변경
int SortedList::Delete(ItemType data) {
	while (m_CurPointer < MAXSIZE - 1) {
		data = m_Array[m_CurPointer + 1];
		m_Array[m_CurPointer] = data;
		m_CurPointer++;
	}
	m_Length--;
	cout << "record is deleted. " << endl;
	return 0;
}
*/


//다음 위치 반환 함수
template<typename T>
int SortedList<T>::GetNextItem(T& data) {
	m_CurPointer++;
	if (m_CurPointer == MAXSIZE) {
		return -1;
	}
	data =  m_Array[ m_CurPointer];

	return m_CurPointer;
}

template<typename T>
void SortedList<T>::ResetList() {
	m_CurPointer = -1;
}

template<typename T>
bool SortedList<T>::IsEmpty() {
	if (m_Length == 0) {
		cout << "List is empty." << endl;
		return true;
	}
	else {
		cout << "List is remain. " << endl;
		return false;
	}
}




//변경할 정보 입력하는 함수, m_Array 에 변경정보 입력
template<typename T>
int SortedList<T>::Replace(T data) {
	 
		m_Array[m_CurPointer] = data;
		return 0;

}


//Singer Name이 일치하는 음악 찾아서 모든 정보를 return 해준다. -> Application RetrieveMusic에 쓰임.
template<typename T>
int SortedList<T>::RetrieveBySinger(T& target) {

	int index = m_Length - 1;
	if (m_Length == 0) {//list가 비었다면
		cout << "There is no List" << endl;
		return 0;
	}
	else {//List 가 존재한다면.

		for (int i = 0; i <= index; i++) {
			if (target -= m_Array[i]) {//Singer Name 같은경우 모두 출력!
				m_Array[i].DisplayRecordOnScreen();

			}
		}
		return 0;
	}
}


template<typename T>
int SortedList<T>::RetrieveBygenre(T& target) {//genre 으로 검색결과 찾는 함수

	int index = m_Length - 1;
	if (m_Length == 0) {//list가 비었다면
		cout << "There is no List" << endl;
		return 0;
	}
	else {//List 가 존재한다면.

		for (int i = 0; i <= index; i++) {
			if (target += m_Array[i]) {//Name 같은경우 출력!
				m_Array[i].DisplayRecordOnScreen();
			}
		}
		return 0;
	}
}

template<typename T>
int SortedList<T>::RetrieveByMusicNumber(T& target) {//Music Number으로 검색결과 찾는 함수: PrimaryKey
	int index = m_Length - 1;
	if (m_Length == 0) {
		cout << "There is no List" << endl;
		return 0;
	}
	else {

		for (int i = 0; i <= index; i++) {
			if (target == m_Array[i]) {
				m_Array[i].DisplayRecordOnScreen();

			}

		}
		return 0;
	}
}






/*  @@@@@@@@@@@@ 나중에 Singer 와 genre 로 search 하는 알고리즘.
int RetrieveBySinger(ItemType& target) {

	for (int i = 0; i <= index; i++) {
		if (target == m_Array[i]) {// 같은경우 출력!
			m_Array[i].DisplayRecordOnScreen();
			return 0;
		}
		if (index == 9 || target < m_Array[i])//index 가 9이거나 m_Array ID가 더 크다면
			return 0;
	}
	return 0;
}


}
int RetrieveBygenre(ItemType& target){


}

*/

////Binary Search
template<typename T>
int SortedList<T>::RetrieveByBS(T& target) {
	//이진코드 검색 방법
	int index = m_Length - 1;// 입력된 리스트개수에 맞게 index 값 설정
	int mid = 5;//중간 index
	int point = 1;//index 재설정을 위한 변수
	while (true) {
		point = index / 2;
		if (target < m_Array[point]) {//Array의 Name가 더 크다면
			point = point / 2;
			continue;
		}
		else if (target > m_Array[point]) { //target의 Name가 더 크다면
			index = index + point;  //index를 point를 이용해 범위에 맞게 Search 설정
			continue;
		}
		else if (target == m_Array[point]) { //Name 값이 같을 경우 출력후 break;
			m_Array[point].DisplayRecordOnScreen();
			break;
		}

	}
	return 0;
}