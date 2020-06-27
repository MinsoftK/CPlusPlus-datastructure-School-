#include "PlayItem.h"


void PlayItem::setMusicNumberFromKB() {
		cout << "\tEnter Music Number: ";
		cin >> MusicNumber;
	}
//music Number set
void PlayItem::setMN(int MN) {
	MusicNumber = MN;
}
void PlayItem::setNumPlay(int play) {
	numPlay = play;
}// 큐로 부터 얻어온다rh xmrrkd
void PlayItem::setInTime(int Time) {
	inTime = Time;
}
int PlayItem::getMN() {
	return MusicNumber;
}
int PlayItem::getNumPlay() {
	return numPlay;
}
int PlayItem::getInTime() {
	return inTime;
}