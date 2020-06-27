#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <iostream>
#include <fstream>
#include <string>
#include "SortedList.h"
#define FILENAMESIZE 1024
using namespace std;
class Application
{
private:
	ifstream m_InFile; //input file descriptor
	ofstream m_OutFile;//output file descriptor
	SortedList m_List;//item list
	int m_Command;//current command number

public:
	Application(){
		m_Command = 0;
	}
	~Application(){}
	void Run();
	int GetCommand();
	int AddItem();
	void DisPlayAllItem();
	int OpenInFile(char* fileName);
	int OpenOutFile(char* fileName);
	int ReadDataFromFile();
	int WriteDataToFile();
	void RetrieveStudent();
	void DeleteStudent();
	void Replace();
};
#endif	// _APPLICATION