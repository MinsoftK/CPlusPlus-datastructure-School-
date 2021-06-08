/*
 *	@brief	ItemType 클래스의 멤버 함수 헤더
 *	@date	2019.10.06
 *	@author	김민성
 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//enum RelationType{Less,Greater,Equal};
class ItemType
{
protected:
	string SongName;
	string Singer;
	string SongMaker;
	string genre;
	string MusicNumber;   //Primary key
	int InTime;
	int Playnum;

public:
	ItemType();
	~ItemType();


	string GetSongName();	//노래제목
	string GetSinger();		//가수
	string GetSongMaker();	//작곡가
	string Getgenre();		//장르
	string GetMusicNumber(); //음악의 고유 ID
	int GetPlaynum();
	int GetInTime();
	
	//Set 변수에 값을 입력해줌
	void SetSongName(string inName);
	void SetSinger(string inSinger);
	void SetSongMaker(string inMaker);
	void Setgenre(string ingenre);
	void SetMusicNumber(string inMN);
	void SetPlaynum(int inPlaynum);
	void SetInTime(int inInTime);
	void SetRecord(string inName, string inMaker, string inSinger, string ingenre, string inMN,int inPlaynum,int inInTime);

	//변수 값을 출력해줌.
	void DisPlaySongNameOnScreen();
	void DisPlaySingerOnScreen();
	void DisPlaySongMakerOnScreen();
	void DisPlaygenreOnScreen();
	void DisPlayMusicNumberOnScreen();
	void DisPlayPlaynumOnScreen();
	void DisPlayInTimeOnScreen();

	void DisPlayRecordOnScreen();

	//키보드로부터 입력받은 값 넣어줌.
	void SetSongNameFromKB();
	void SetSingerFromKB();
	void SetSongMakerFromKB();
	void SetgenreFromKB();
	void SetMusicNumberFromKB();


	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);

	//연산자 오버로딩
	bool operator==(ItemType& item); //Music Number 비교를 위한 연산자 오버로딩
	bool operator+=(ItemType& data); //genrer 비교를 위한 연산자 오버로딩
	bool operator-=(ItemType& data); //Singer 비교를 위한 연산자 오버로딩
	bool operator*=(ItemType& data); //SongName 비교를 위한 연산자 오버로딩
	bool operator>(ItemType& data);	//Music Number의 크기를 비교하기 위한 오버로딩
	bool operator<(ItemType& data);	//Music Number의 크기를 비교하기 위한 오버로딩
	//RelationType CompareById(const ItemType& data);

};


