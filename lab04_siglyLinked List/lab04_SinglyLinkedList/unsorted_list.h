#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "SongList.h"
#define MAXSIZE 5

using namespace std;
class unsorted_list
{
private:
	SongList m_Array[MAXSIZE];
	int m_Length = 0;
	int m_CurPointer = 0;
public:
	unsorted_list() {
		m_Length = 0;
		ResetList();
	}
	~unsorted_list() {}

	void MakeEmpty();
	int GetLength();
	bool IsFull();
	bool IsEmpty();
	int Add(SongList data);
	void ResetList();
	int GetNextItem(SongList& data);

	int Get(SongList& data);
	int Delete(SongList data);
	int Replace(SongList data);
	
};


