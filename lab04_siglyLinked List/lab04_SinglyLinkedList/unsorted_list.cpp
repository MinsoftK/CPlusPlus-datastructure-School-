/*
 *	@brief	unsorted_list 클래스의 멤버 함수 정의
 *	@date	2019.10.12
 *	@author	김민성
 */


#include "unsorted_list.h"
//#include "ItemType.h"

void unsorted_list::MakeEmpty() {
	m_Length = 0;
}
int unsorted_list::GetLength() {
	return m_Length;
}
bool unsorted_list::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else return false;
}
//data
int unsorted_list::Add(SongList data) {
	if (!IsFull()) {
		m_Array[m_Length] = data;
		m_Length++;
	}
	else return 0;
	return 1;
}
void unsorted_list::ResetList() {
	m_CurPointer = -1;
}
int unsorted_list::GetNextItem(SongList& data) {
	m_CurPointer++;
	//IsFull 사용 불가?
	if (m_CurPointer == MAXSIZE) {
		return -1;
	}
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}
bool unsorted_list::IsEmpty() {
	if (m_Length == 0) {
		cout << "List is empty." << endl;
		return true;
	}
	else {
		cout << "List is remain. " << endl;
		return false;

	}
}
int unsorted_list::Get(ItemType & data) {
	m_Array[m_CurPointer] == data;
	return 0;


}

int unsorted_list::Delete(ItemType data) {
	while (m_CurPointer < MAXSIZE - 1) {
		data = m_Array[m_CurPointer + 1];
		m_Array[m_CurPointer] = data;
		m_CurPointer++;
	}
	m_Length--;
	cout << "record is deleted. " << endl;
	return 0;
}

int unsorted_list::Replace(ItemType data) {
	m_Array[m_CurPointer] = data;
	return 0;
}
