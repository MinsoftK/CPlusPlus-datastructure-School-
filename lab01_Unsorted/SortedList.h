#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include "ItemType.h"
#define MAXSIZE 5

using namespace std;
class SortedList
{
private:
	ItemType m_Array[MAXSIZE];
	int m_Length=0;
	int m_CurPointer=0;
public:
	SortedList() {
		m_Length = 0;
		ResetList();
	}
	~SortedList() {}

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	int Add(ItemType data);
	void ResetList();
	int GetNextItem(ItemType& data);
	
	int Get(ItemType& data);
	int Delete(ItemType data);
	int Replace(ItemType data);
	//Ãß°¡µÈ Sorted List
	int Retr