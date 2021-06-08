/*
 *	@brief	PlayItem 클래스의 멤버 함수 선언부
 *	@date	2019.10.06
 *	@author	김민성
 */


#include "PlayItem.h"


void PlayItem::SetMusicNumber(string MN) {
	MusicNumber = MN;
}
void PlayItem::SetPlaycount(int play) {
	Playcount = play;
}// 큐로 부터 얻어온다


void PlayItem::SetInTime(int Time) {
	InTime = Time;
}
string PlayItem::GetMusicNumber() {
	return MusicNumber;
}
int PlayItem::GetPlaycount() {
	return Playcount;
}
int PlayItem::GetInTime() {
	return InTime;
}

void PlayItem::SetMusicNumberFromKB() {
	cout << "\tMusic Number: ";
	cin >> MusicNumber;

}




void PlayItem::DisPlayMusicNumberOnScreen() {
	cout << "\tMusic Number: " << MusicNumber<<endl;
}
void PlayItem::DisPlayPlayCountOnScreen() {
	cout << "\tPlay Count(재생된 횟수): " << Playcount << endl;
}
void PlayItem::DisPlayInTimeOnScreen() {
	cout << "\tInTime (들어온순서): " << InTime<<endl;
}
void PlayItem::DisPlayRecordOnScreen() {
	DisPlayMusicNumberOnScreen();
	//DisPlayPlayCountOnScreen();
	DisPlayInTimeOnScreen();
}



bool PlayItem::operator ==(PlayItem& item) {
		if (item.GetMusicNumber() == MusicNumber) {
				return 1;
		}

		else return 0;
}

bool PlayItem::operator > (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
bool PlayItem::operator < (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
bool PlayItem::operator >= (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
bool PlayItem::operator <= (PlayItem& item) {
	if (item.GetMusicNumber() > MusicNumber)
		return 1;
	else
		return 0;
}
