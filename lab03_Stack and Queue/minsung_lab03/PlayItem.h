/*
 *	@brief	PlayItem 클래스의 멤버 함수 헤더
 *	@date	2019.10.06
 *	@author	김민성
 */


#pragma once
#include <string>
#include <iostream>

using namespace std;

// 곡 플레이에 관한 정보만 담는 클래스 (곡의 플레이 횟수, 곡의 순서 등)
class PlayItem {

private:
	string MusicNumber; // Primary Key 는 공통으로 가지므로 Master 에서 얻어온다.
	int Playcount; // 곡의 플레이 횟수
	int InTime; // 곡이 들어온 순서

public:

	PlayItem() {
		MusicNumber = "";
		Playcount = 0;
		InTime = 0;
	}
	~PlayItem() {}

	//정보를 각각의 변수에 입력된 정보를 읽는 Get
	string GetMusicNumber();
	int GetPlaycount();
	int GetInTime();
	//정보를 각각의 변수에 입력받는 Set
	void SetMusicNumber(string MN);//music Number set
	void SetPlaycount(int play);
	void SetInTime(int Time);
	
	void SetRecord(string inMusicNumber, int inplaycount, int inInTime) {
		MusicNumber = inMusicNumber; 
		Playcount = inplaycount;
		InTime = inInTime;
	}

	void SetMusicNumberFromKB();

	//각각의 멤버변수들의 정보 출력하는 함수들 
	void DisPlayMusicNumberOnScreen();
	void DisPlayPlayCountOnScreen();
	void DisPlayInTimeOnScreen();
	void DisPlayRecordOnScreen();

	//Primary Key값의 비교를 위한 연산자 오버로딩
	bool operator ==(PlayItem& item);
	bool operator > (PlayItem& item);
	bool operator < (PlayItem& item);
	bool operator >= (PlayItem& item);
	bool operator <= (PlayItem& item);
};
