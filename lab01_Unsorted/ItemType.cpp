#include "ItemType.h"

ItemType::ItemType() {
	m_Id = 0;
	m_sName = "";
	m_sAddress = "";
}
ItemType::~ItemType() {
	}

int ItemType::GetId() {
	return m_Id;
}

string ItemType::GetName() {
	return m_sName;
}
string ItemType::GetAddress() {
	return m_sAddress;
}
void ItemType::SetId(int inId) {
	m_Id = inId;
}
void ItemType::SetName(string inName) {
	m_sName = inName;
}
void ItemType::SetAddress(string inAddress) {
	m_sAddress = inAddress;
}
void ItemType::SetRecord(int inId, string inName, string inAddress) {
	SetId(inId);
	SetName(inName);
	SetAddress(inAddress);
}
void ItemType::DisplayIdOnScreen() {
	cout <<"Id: "<< m_Id << endl;;
}
void ItemType::DisplayNameOnScreen() {
	cout << "Name: "<<m_sName << endl;
}
void ItemType::DisplayAddressOnScreen() {
	cout <<"Address: "<< m_sAddress << endl;
}
void ItemType::DisplayRecordOnScreen() {
	DisplayIdOnScreen();
	DisplayNameOnScreen();
	DisplayAddressOnScreen();

}
void ItemType::SetIdFromKB() {
	cout << "\tID: ";
	cin >> m_Id;
}
void ItemType::SetNameFromKB() {
	cout << "\tName: ";
	cin >> m_sName;
}
void ItemType::SetAddressFromKB() {
	cout << "\tAddress: ";
	cin >> m_sAddress;
}
void ItemType::SetRecordFromKB() {
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}
// 파일에서 불러오는것????
int ItemType::ReadDataFromFile(ifstream& fin) {
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sAddress;
	return 1;
}
int ItemType::WriteDataToFile(ofstream& fout) {
	fout << endl;
	fout << m_Id;
	fout << m_sName;
	fout << m_sAddress;
	return 1;
}
bool ItemType::operator==(ItemType& data) {
	if (data.GetId() == m_Id) {
		DisplayRecordOnScreen();
		return true;
	}
}
/*
RelationType CompareByID(const ItemType& data) {

}
*/
