#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//enum RelationType{Less,Greater,Equal};
class SongList
{
protected:
	string SongName;
	string SongMaker;

	string Singer;
	string genre;
	int MusicNumber;   //Primary key


public:
	SongList();
	~SongList();


	string GetSongName();	//노래제목
	string GetSongMaker();	//작곡가
	string GetSinger();		//가수
	string Getgenre();		//장르
	int GetMusicNumber(); //음악의 고유 ID



	void SetSongName(string inName);
	void SetSongMaker(string inMaker);

	void SetSinger(string inSinger);
	void Setgenre(string ingenre);
	void SetMusicNumber(int inMN);



	void SetRecord(string inName, string inMaker, string inSinger, string ingenre, int inMN);

	void DisplaySongNameOnScreen();
	void DisplaySongMakerOnScreen();

	void DisplaySingerOnScreen();
	void DisplaygenreOnScreen();
	void DisplayMNOnScreen();
	void DisplayRecordOnScreen();


	void SetSongNameFromKB();
	void SetSongMakerFromKB();
	void SetSingerFromKB();
	void SetgenreFromKB();
	void SetMNFromKB();


	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);


	bool operator==(SongList& item); //Music Number 비교를 위한 연산자 오버로딩
	bool operator+=(SongList& data); //genrer 비교를 위한 연산자 오버로딩
	bool operator-=(SongList& data); //Singer 비교를 위한 연산자 오버로딩
	bool operator>(SongList& data);
	bool operator<(SongList& data);
	//RelationType CompareById(const ItemType& data);

};


