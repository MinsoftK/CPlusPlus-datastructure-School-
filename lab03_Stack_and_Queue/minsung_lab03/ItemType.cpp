/*
 *	@brief	ItemType 클래스의 멤버 함수 헤더
 *	@date	2019.10.06
 *	@author	김민성
 */


#include "ItemType.h"

ItemType::ItemType() {

	SongName = "";
	Singer = "";
	SongMaker = "";
	genre = "";
	MusicNumber = "";  //음악의 고유 ID
	InTime = 0;
	Playnum = 0;

}
ItemType::~ItemType() {
}


string ItemType::GetSongName() {
	return SongName;
}
string ItemType::GetSongMaker() {
	return SongMaker;
}
string ItemType::GetSinger() {
	return Singer;
}
string ItemType::Getgenre() {
	return genre;
}
string ItemType::GetMusicNumber() {
	return MusicNumber;
}
int ItemType::GetPlaynum() {
	return Playnum;
}
int ItemType::GetInTime() {
	return InTime;
}
void ItemType::SetSongName(string inName) {
	SongName = inName;
}

void ItemType::SetSongMaker(string inMaker) {
	SongMaker = inMaker;
}
void ItemType::SetSinger(string inSinger) {
	Singer = inSinger;
}
void ItemType::Setgenre(string ingenre) {
	genre = ingenre;
}
void ItemType::SetMusicNumber(string inMN) {
	MusicNumber= inMN;
}
void ItemType::SetPlaynum(int inPlaynum) {
	Playnum = inPlaynum;
}

void ItemType::SetInTime(int inInTime) {
	InTime= inInTime;
}



void ItemType::SetRecord(string inMN,string inName, string inMaker, string inSinger, string ingenre,int inPlaynum,int inInTime) {
	SetMusicNumber(inMN);
	SetSongName(inName);
	SetSongMaker(inMaker);
	SetSinger(inSinger);
	Setgenre(ingenre);
	SetPlaynum(inPlaynum);
	SetInTime(inInTime);
}

void ItemType::DisPlaySongNameOnScreen() {
	cout << "\tSongName: " << SongName << endl;
}

void ItemType::DisPlaySongMakerOnScreen() {
	cout << "\tSong Maker: " << SongMaker << endl;
}
void ItemType::DisPlaySingerOnScreen() {
	cout << "\tSinger: " << Singer << endl;
}
void ItemType::DisPlaygenreOnScreen() {
	cout << "\tGenre : " << genre << endl;
}
void ItemType::DisPlayMusicNumberOnScreen() {
	cout << "\tMusicNumber: " << MusicNumber << endl;
}

void ItemType::DisPlayPlaynumOnScreen() {
	cout << "\tPlaynum(재생횟수): " << Playnum<< endl;
}
void ItemType::DisPlayInTimeOnScreen() {
	cout << "\t등록된 순서: " << InTime << endl;
}

void ItemType::DisPlayRecordOnScreen() {

	DisPlaySongNameOnScreen();
	DisPlaySongMakerOnScreen();
	DisPlaySingerOnScreen();
	DisPlaygenreOnScreen();
	DisPlayMusicNumberOnScreen();
	DisPlayPlaynumOnScreen();
	
}

void ItemType::SetSongNameFromKB() {
	cout << "\tSong Name: ";

	cin >> SongName;

}

void ItemType::SetSongMakerFromKB() {
	cout << "\tSongMaker: ";
	cin >> SongMaker;
}
void ItemType::SetSingerFromKB() {
	cout << "\tSinger: ";
	cin >> Singer;
}
void ItemType::SetgenreFromKB() {
	cout << "\tGenre : ";
	cin >> genre;

}
void ItemType::SetMusicNumberFromKB() {
	cout << "\tMusic Number: ";
	cin >> MusicNumber;
}


void ItemType::SetRecordFromKB() {
	SetMusicNumberFromKB();
	SetSongNameFromKB();
	SetSingerFromKB();
	SetSongMakerFromKB();
	SetgenreFromKB();
	
}
//파일에서 불러오는 것
int ItemType::ReadDataFromFile(ifstream& fin) {

	fin >> SongName;
	fin >> Singer;
	fin >> SongMaker;
	fin >> genre;
	fin >> MusicNumber;

	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout) {

	fout << setw(2) << SongName;
	fout << setw(2) << Singer;
	fout << setw(2) << SongMaker;
	fout << setw(2) << genre;
	fout << setw(2) << MusicNumber;

	return 1;
}


bool ItemType::operator==(ItemType& data) {//MusicNumber 비교를 위한 연산자 오버로딩
	if (data.GetMusicNumber() == MusicNumber) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;

}
bool ItemType::operator*=(ItemType& data) {//MusicNumber 비교를 위한 연산자 오버로딩
	if (data.GetSongName() == SongName) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;

}


bool ItemType::operator+=(ItemType& data) {//genrer 비교를 위한 연산자 오버로딩
	if (data.Getgenre() == genre) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;
}
bool ItemType::operator-=(ItemType& data) { //Singer 비교를 위한 연산자 오버로딩
	if (data.GetSinger() == Singer) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;
}

bool ItemType::operator>(ItemType& data) {//이름 순서를 위한 연산자 오버로딩
	if (data.GetMusicNumber() > MusicNumber) {
		return true;
	}
	else return false;
}
bool ItemType::operator<(ItemType& data) {//이름 순서를 위한 연산자 오버로딩
	if (data.GetMusicNumber() < MusicNumber) {
		return true;
	}
	else return false;
}


/*
RelationType CompareByID(const ItemType& data) {

}
*/
