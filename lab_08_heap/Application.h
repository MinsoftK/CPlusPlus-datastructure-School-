/*
 *	@brief	어플리케이션 클래스의 헤더
 *	@date	2019.10.06
 *	@author	김민성
 */


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "ItemType.h"
#include  "PlayItem.h"
#include "SingerType.h"
#include "SortedLinkedList.h"
#include "SortedList.h"//MasterList 
#include "CircularQueue.h"//Circular Queue
#include "DoublySortedLinkedList.h"//더블링크드리스트
#include "BinarySearchTree.h"//이진탐색트리
#include "CHeapBase.h"
#include "CMaxHeap.h"
#include "CMinHeap.h"

#define FILENAMESIZE 1024
using namespace std;

class Application
{
private:
	ifstream m_InFile; //input file descriptor
	ofstream m_OutFile;//output file descriptor
	SortedList<ItemType> MasterList;//마스터 리스트
	//SortedLinkedList<ItemType> MasterList;
	//CircularSingleLinked<ItemType> QPlay;
	CircularQueue<PlayItem> PlayList;//템플릿에 PlayItem Class가 들어가는 m_PlayList
	DoublySortedLinkedList<ItemType> TempList;//더블링크드 리스트 활용하는 TempList
	DoublySortedLinkedList<SingerType> SingerList;
	BinarySearchTree<ItemType> MasterList2; //이진탐색트리를 이용한 MasterList
	CHeapBase<ItemType> *HeapList; //Itemtype의 HeapList
	
	int m_Command;//current command number
	int Order; //PlayList의 등록된 순서를 위한 변수
	
public:
	Application() {
		m_Command = 0;
		Order = 0;
		
	}
	~Application() {}
	void Run();

	int GetCommand();
	int AddMusic();//음악 추가
	void DisPlayAllMusic();//모든 음악 출력
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();//파일에서 정보 읽어오기
	int WriteDataToFile();//정보 파일에 쓰기
	int RetrieveMusic();// 뮤직타입,가수,장르 별로 구별하는 Sorted Array 불러오는 함수.
	int DeleteMusic();	//Master List에서 음악 삭제
	void ReplaceMusic();//Master List에서 음악 정보 수정
	int AddToPlayList();//키보로드로 ID를 읽어서 master에서 검색하고
						//존재하면 Play List에 추가
						//만약 PlayList가 Full이면 오래된것
						//삭제후 새로운 것 추가.
	void PlayInsertOrder();//Play List 목록 출력후 재생할 번호 선택
							//선택한 번호 numPlay +1
							// 종료 입력 전까지 무한반복
	
	void DeletePlayList();//PlayList에서 곡 삭제

	//Doubly Linked List 기능 함수
	int AddSongToPL();
	int DeleteSongFrPL();
	int PlayOAddTime();
	int PlayIOFreq();
	//Binary Search Tree
	int BSTAdd();
	int BTSDelete();
	int BTSSearch();
	int	BTSUpdate();
	void DisPlayTree();

	//MIN Heap 기능들
	void WhatHeap();		//maxHeap ,MinHeap 선택
	int MinHeapAdd();		//노드 추가
	int MinHeapDelete();	//삭제
	int	MinHeapUpdate();	//갱신
	int MinHeapRetrieve(); //검색
	int DequeueItem();		//첫번째 노드 삭제


	
};