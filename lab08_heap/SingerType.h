#pragma once

#include <string>
#include <iostream>
using namespace std;

class SingerType
{
private:
	string singername;
	int age;
	string gender;
	string id;
	string songname;

public:
	SingerType();
	~SingerType();
	void setsingername(string _name);
	void setage(int _age);
	void setgender(string _gender);
	void setid(string _id);
	void setsongname(string _songname);
	void setAll(string _name, int _age, string _gender, string _id, string _songname);

	void setsingernameKB();
	void setageKB();
	void setgenderKB();
	void setsingerKB();


	string getsingername();
	int getage();
	string getgender();
	//	SimpleItemType getIdName();
	string getid();
	string getsongname();
	bool operator==(SingerType& a);
	bool operator <(SingerType& a);
	bool operator >(SingerType& a);

	void display();

};

