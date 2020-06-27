#pragma once

#define MAXSIZE 10
#include <iostream>
#include <string>
using namespace std;
class SingerType
{
private:
	string Name;
	int Age;
	string Sex;
	
public:
	SingerType() {
		Name = "";
		Age = 0;
		Sex = "";

	}
	~SingerType() {
	}
	string GetName();
	int GetAge();
	string GetSex();

	void SetName(string Name);
	void SetAge(int Age);
	void SetSex(string Sex);
	void SetRecord(string inName, int inAge, string inSex) {
		SetName(inName);
		SetAge(inAge);
		SetSex(inSex);
	}

	void SetNameFromKB();
	void SetAgeFromKB();
	void SetSexFromKB();
	void SetRecordFromKB();

	void DisplayNameOnScreen();
	void DisplayAgeOnScreen();
	void DisplaySexOnScreen();
	void DisplayRecordOnScreen();
	bool operator==(SingerType& data); //Music Number 비교를 위한 연산자 오버로딩
};

