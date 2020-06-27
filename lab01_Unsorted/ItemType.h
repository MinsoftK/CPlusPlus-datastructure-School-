#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//enum RelationType{Less,Greater,Equal};
class ItemType
{
protected:
	int m_Id;
	string m_sName;
	string m_sAddress;
public:
	ItemType();
	~ItemType();
	int GetId();
	string GetName();
	string GetAddress();
	void SetId(int inId);
	void SetName(string inName);
	void SetAddress(string inName);
	void SetRecord(int inId, string inName, string inAddress);
	void DisplayIdOnScreen();
	void DisplayNameOnScreen();
	void DisplayAddressOnScreen();
	void DisplayRecordOnScreen();
	void SetIdFromKB();
	void SetNameFromKB();
	void SetAddressFromKB();
	void SetRecordFromKB();
	int ReadDataFromFile(ifstream& fin);
	int WriteDataToFile(ofstream& fout);
	bool operator==(ItemType& item);
	//RelationType CompareById(const ItemType& data);

};
#endif	// _ITEMTYPE_H