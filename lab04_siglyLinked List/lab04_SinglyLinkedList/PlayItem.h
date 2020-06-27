#pragma once
#include <string>
#include <iostream>

using namespace std;

// 곡 플레이에 관한 정보만 담는 클래스 (곡의 플레이 횟수, 곡의 순서 등)
class PlayItem {

private:
	int MusicNumber; // Primary Key 는 공통으로 가지므로 Master 에서 얻어온다.
	int numPlay; // 곡의 플레이 횟수
	int inTime; // 곡이 들어온 순서

public:

	PlayItem() {
		MusicNumber = 0;
		numPlay = 0;
		inTime = 0;
	}
	~PlayItem() {}

	void setMusicNumberFromKB();
	void setMN(int MusicNumber);//music Number set
	void setNumPlay(int play); // 큐로 부터 얻어온다
	void setInTime(int Time);

	int getMN();
	int getNumPlay();
	int getInTime();
};
