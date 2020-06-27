/*
 *	@brief	���ø����̼� Ŭ������ ���
 *	@date	2019.10.06
 *	@author	��μ�
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
#include "DoublySortedLinkedList.h"//����ũ�帮��Ʈ
#include "BinarySearchTree.h"//����Ž��Ʈ��
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
	SortedList<ItemType> MasterList;//������ ����Ʈ
	//SortedLinkedList<ItemType> MasterList;
	//CircularSingleLinked<ItemType> QPlay;
	CircularQueue<PlayItem> PlayList;//���ø��� PlayItem Class�� ���� m_PlayList
	DoublySortedLinkedList<ItemType> TempList;//����ũ�� ����Ʈ Ȱ���ϴ� TempList
	DoublySortedLinkedList<SingerType> SingerList;
	BinarySearchTree<ItemType> MasterList2; //����Ž��Ʈ���� �̿��� MasterList
	CHeapBase<ItemType> *HeapList; //Itemtype�� HeapList
	
	int m_Command;//current command number
	int Order; //PlayList�� ��ϵ� ������ ���� ����
	
public:
	Application() {
		m_Command = 0;
		Order = 0;
		
	}
	~Application() {}
	void Run();

	int GetCommand();
	int AddMusic();//���� �߰�
	void DisPlayAllMusic();//��� ���� ���
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();//���Ͽ��� ���� �о����
	int WriteDataToFile();//���� ���Ͽ� ����
	int RetrieveMusic();// ����Ÿ��,����,�帣 ���� �����ϴ� Sorted Array �ҷ����� �Լ�.
	int DeleteMusic();	//Master List���� ���� ����
	void ReplaceMusic();//Master List���� ���� ���� ����
	int AddToPlayList();//Ű���ε�� ID�� �о master���� �˻��ϰ�
						//�����ϸ� Play List�� �߰�
						//���� PlayList�� Full�̸� �����Ȱ�
						//������ ���ο� �� �߰�.
	void PlayInsertOrder();//Play List ��� ����� ����� ��ȣ ����
							//������ ��ȣ numPlay +1
							// ���� �Է� ������ ���ѹݺ�
	
	void DeletePlayList();//PlayList���� �� ����

	//Doubly Linked List ��� �Լ�
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

	//MIN Heap ��ɵ�
	void WhatHeap();		//maxHeap ,MinHeap ����
	int MinHeapAdd();		//��� �߰�
	int MinHeapDelete();	//����
	int	MinHeapUpdate();	//����
	int MinHeapRetrieve(); //�˻�
	int DequeueItem();		//ù��° ��� ����


	
};