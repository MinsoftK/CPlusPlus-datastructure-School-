#pragma once
#include <string>
#include <iostream>

using namespace std;

// �� �÷��̿� ���� ������ ��� Ŭ���� (���� �÷��� Ƚ��, ���� ���� ��)
class PlayItem {

private:
	int MusicNumber; // Primary Key �� �������� �����Ƿ� Master ���� ���´�.
	int numPlay; // ���� �÷��� Ƚ��
	int inTime; // ���� ���� ����

public:

	PlayItem() {
		MusicNumber = 0;
		numPlay = 0;
		inTime = 0;
	}
	~PlayItem() {}

	void setMusicNumberFromKB();
	void setMN(int MusicNumber);//music Number set
	void setNumPlay(int play); // ť�� ���� ���´�
	void setInTime(int Time);

	int getMN();
	int getNumPlay();
	int getInTime();
};
