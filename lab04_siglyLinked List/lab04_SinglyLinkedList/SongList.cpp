//* @date	2019.10.14
//* @author	김민성

#include "SongList.h"

SongList::SongList() {

	SongName = "";
	SongMaker = "";
	Singer = "";
	genre = "";
	MusicNumber = 0;  //음악의 고유 ID


}
SongList ::~SongList() {
}


string SongList::GetSongName() {
	return SongName;
}
string SongList::GetSongMaker() {
	return SongMaker;
}
string SongList::GetSinger() {
	return Singer;
}
string SongList::Getgenre() {
	return genre;
}
int SongList::GetMusicNumber() {
	return MusicNumber;
}

void SongList::SetSongName(string inName) {
	SongName = inName;
}

void SongList::SetSongMaker(string inMaker) {
	SongMaker = inMaker;
}
void SongList::SetSinger(string inSinger) {
	Singer = inSinger;
}
void SongList::Setgenre(string ingenre) {
	genre = ingenre;
}
void SongList::SetMusicNumber(int inMN) {
	genre = inMN;
}



void SongList::SetRecord(string inName, string inMaker, string inSinger, string ingenre, int inMN) {

	SetSongName(inName);
	SetSongMaker(inMaker);
	SetSinger(inSinger);
	Setgenre(ingenre);
	SetMusicNumber(inMN);
}

void SongList::DisplaySongNameOnScreen() {
	cout << "SongName: " << SongName << endl;
}

void SongList::DisplaySongMakerOnScreen() {
	cout << "Song Maker: " << SongMaker << endl;
}
void SongList::DisplaySingerOnScreen() {
	cout << "Singer: " << Singer << endl;
}
void SongList::DisplaygenreOnScreen() {
	cout << "Genre : " << genre << endl;
}
void SongList::DisplayMNOnScreen() {
	cout << "MusicNumber: " << MusicNumber << endl;
}
void SongList::DisplayRecordOnScreen() {

	DisplaySongNameOnScreen();

	DisplaySongMakerOnScreen();
	DisplaySingerOnScreen();
	DisplaygenreOnScreen();
	DisplayMNOnScreen();
}

void SongList::SetSongNameFromKB() {
	cout << "\tSong Name: ";

	cin >> SongName;

}

void SongList::SetSongMakerFromKB() {
	cout << "\tSongMaker: ";
	cin >> SongMaker;
}
void SongList::SetSingerFromKB() {
	cout << "\tSinger: ";
	cin >> Singer;
}
void SongList::SetgenreFromKB() {
	cout << "\tGenre : ";
	cin >> genre;

}
void SongList::SetMNFromKB() {
	cout << "\tMusic Number: ";
	cin >> MusicNumber;
}


void SongList::SetRecordFromKB() {

	SetSongNameFromKB();
	SetSongMakerFromKB();
	SetSingerFromKB();
	SetgenreFromKB();
	SetMNFromKB();
}
// 파일에서 불러오는것????
int SongList::ReadDataFromFile(ifstream& fin) {

	fin >> SongName;
	fin >> SongMaker;
	fin >> Singer;
	fin >> genre;
	fin >> MusicNumber;

	return 1;
}
int SongList::WriteDataToFile(ofstream& fout) {

	fout << setw(2) << SongName;
	fout << setw(2) << SongMaker;
	fout << setw(2) << Singer;
	fout << setw(2) << genre;
	fout << setw(2) << MusicNumber;

	return 1;
}


bool SongList::operator==(SongList& data) {//MusicNumber 비교를 위한 연산자 오버로딩
	if (data.GetMusicNumber() == MusicNumber) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;

}

bool SongList ::operator+=(SongList& data) {//genrer 비교를 위한 연산자 오버로딩
	if (data.Getgenre() == genre) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;
}
bool SongList::operator-=(SongList& data) { //Singer 비교를 위한 연산자 오버로딩
	if (data.GetSinger() == Singer) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;
}

bool SongList::operator>(SongList& data) {//이름 순서를 위한 연산자 오버로딩
	if (data.GetMusicNumber() > MusicNumber) {
		return true;
	}
	else return false;
}
bool SongList::operator<(SongList& data) {//이름 순서를 위한 연산자 오버로딩
	if (data.GetMusicNumber() < MusicNumber) {
		return true;
	}
	else return false;
}
/*
RelationType CompareByID(const ItemType& data) {

}
*/
