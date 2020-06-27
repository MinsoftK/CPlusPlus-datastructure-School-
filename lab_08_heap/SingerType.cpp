#include "SingerType.h"

SingerType::SingerType() {}

SingerType::~SingerType() {}

void SingerType::setsingername(string _name) { singername = _name; }
void SingerType::setage(int _age) { age = _age; }
void SingerType::setgender(string _gender) { gender = _gender; }
void SingerType::setid(string _id) { id = _id; }

void SingerType::setsongname(string _songname) { songname = _songname; }

void SingerType::setAll(string _name, int _age,
	string _gender, string _id, string _songname)
{
	setsingername(_name);
	setage(_age);
	setgender(_gender);
	setid(_id);
	setsongname(_songname);

}


string SingerType::getsingername() { return singername; }

int SingerType::getage() { return age; }
string SingerType::getgender() { return gender; }
string SingerType::getid()
{
	return id;
}

string SingerType::getsongname()
{
	return songname;
}


void SingerType::setsingernameKB() {
	cout << "가수명 : ";
	cin >> singername;
}
void SingerType::setageKB() {
	cout << "AGE : ";
	cin >> age;
}
void SingerType::setgenderKB() {
	cout << "GENDER : ";
	cin >> gender;
}


void SingerType::setsingerKB() {
	setsingernameKB();
	setageKB();
	setgenderKB();
}

bool SingerType::operator==(SingerType& a) {
	return (this->singername == a.singername);
}

bool  SingerType::operator <(SingerType & a) {
	return (this->singername < a.singername);
}

bool  SingerType::operator >(SingerType & a) {
	return (this->singername > a.singername);
}

void  SingerType::display() {
	cout << "가수명 : " << getsingername() << endl;
	cout << "나이 : " << getage() << endl;
	cout << "성별 : " << getgender() << endl;
	//	IdName.display();
}

