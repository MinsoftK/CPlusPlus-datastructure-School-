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


	string GetSongName();	//�뷡����
	string GetSongMaker();	//�۰
	string GetSinger();		//����
	string Getgenre();		//�帣
	int GetMusicNumber(); //������ ���� ID



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


	bool operator==(SongList& item); //Music Number �񱳸� ���� ������ �����ε�
	bool operator+=(SongList& data); //genrer �񱳸� ���� ������ �����ε�
	bool operator-=(SongList& data); //Singer �񱳸� ���� ������ �����ε�
	bool operator>(SongList& data);
	bool operator<(SongList& data);
	//RelationType CompareById(const ItemType& data);

};


