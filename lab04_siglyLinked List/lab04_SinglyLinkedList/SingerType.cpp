/*
 *	@brief	singerType 클래스의 멤버 함수 정의
 *	@date	2019.10.12
 *	@author	김민성
 */



#include "SingerType.h"

string SingerType::GetName() {
	return Name;
}
int SingerType::GetAge() {
	return Age;
}
string SingerType::GetSex() {
	return Sex;
}

void SingerType::SetName(string inName) {
	Name = inName;
}
void SingerType::SetAge(int inAge) {
	Age = inAge;
}
void SingerType::SetSex(string inSex) {
	Sex = inSex;
}

void SingerType::SetNameFromKB() {
	cout << "Enter Name: ";
	cin >> Name;
}
void SingerType::SetAgeFromKB() {
	cout << "Enter Age: ";
	cin >> Age;

}
void SingerType::SetSexFromKB() {
	cout << "Enter Sex: ";
	cin >> Sex;
}
void SingerType::SetRecordFromKB() {
	SetNameFromKB();
	SetAgeFromKB();
	SetSexFromKB();
}

void SingerType::DisplayNameOnScreen() {
	cout << "Name : " << Name << endl;
}
void SingerType::DisplayAgeOnScreen() {
	cout << "Age: " << Age << endl;
	
}
void SingerType::DisplaySexOnScreen() {
	cout << "Sex : " << Sex<< endl;

}
void SingerType::DisplayRecordOnScreen() {
	DisplayNameOnScreen();
	DisplayAgeOnScreen();
	DisplaySexOnScreen();
}












bool SingerType::operator==(SingerType& data) {//MusicNumber 비교를 위한 연산자 오버로딩
	if (data.GetName() == Name) {
		//DisplayRecordOnScreen();
		return true;
	}
	else return false;

}