#include "SortedList.h"
//#include "ItemType.h"

void SortedList::MakeEmpty() {
	m_Length = 0;
}
int SortedList::GetLength() {
	return m_Length;
}
bool SortedList::IsFull() {
	if (m_Length > MAXSIZE - 1)
		return true;
	else return false;
}
//data

//Sorted List
int SortedList::Add(ItemType data) {
	//list�� ��� ó������ �Է�
	//list�� ��á�ٸ� �Ұ�
	data.
	//list�� ��ġ�� �ľ��ϰ� �� ��ġ�� �Է�

}

/*
int SortedList::Add(ItemType data) {
	if (!IsFull()) {
		m_Array[m_Length] = data;
		m_Length++;
	}
	else return 0;
	return 1;
}
void SortedList::ResetList() {
	m_CurPointer = -1;
}
int SortedList::GetNextItem(ItemType& data) {
	m_CurPointer++;
	//IsFull ��� �Ұ�?
	if (m_CurPointer==MAXSIZE){
		return -1;
	}
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

*/

bool SortedList::IsEmpty() {
	if (m_Length == 0) {
		cout << "List is empty." << endl;
		return true;
	}
	else {
		cout << "List is remain. " << endl;
		return false;

	}
}
int SortedList::Get(ItemType& data) {
	m_Array[m_CurPointer] == data;
	return 0;


}

/*Unsorted list
int SortedList::Delete(ItemType data) {
	while (m_CurPointer < MAXSIZE - 1) {
		data = m_Array[m_CurPointer + 1];
		m_Array[