#include "Application.h"



void Application::Run() {
	while (1) {
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: //read a record and add to list
			AddItem();
			break;
		case 2: //display all the records on screen
			DisPlayAllItem();
			break;
		case 3: //make empty
			m_List.MakeEmpty();
			break;
		case 4: //Load list data from a file
			ReadDataFromFile();
			break;
		case 5: //save list data into a file
			WriteDataToFile();
			break;
		case 6: //retrieve
			RetrieveStudent();
			break;
		case 7:
			DeleteStudent();
			break;
		case 8:
			Replace();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection" << endl;
			break;
		}
	}
}
int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Get from file" << endl;
	cout << "\t   5 : Put to file " << endl;
	cout << "\t   6 : Retrieve Student information" << endl;
	cout << "\t   7 : Delete Student information" << endl;
	cout << "\t   8 : Replace Student information " << endl;
	cout << "\t   0 : Quit" << endl;


	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

int Application::AddItem() {
	if (m_List.IsFull())
	{
		cout << "List is full";
		return 0;
	}
	ItemType item;
	item.SetRecordFromKB();
	m_List.Add(item);

	DisPlayAllItem();
	return 1;
}
void Application::DisPlayAllItem() {
	ItemType data;
	cout << "\n\tCurrent list" << endl;

	//list의 모든 데이터를 화면에 출력.
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
		while (curIndex < length && curIndex != -1)
		{
			data.DisplayRecordOnScreen();
			curIndex = m_List.GetNextItem(data);
		}
}
// Open a file by file descriptor as an input file.
int Application::OpenInFile(char* fileName) {
	m_InFile.open(fileName);
	if (!m_InFile) return 0;
	else return 1;
}
int Application::OpenOutFile(char* fileName) {
	m_OutFile.open(fileName);
	if (!m_OutFile) return 0;
	return 1;

}
int Application::ReadDataFromFile() {
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisPlayAllItem();

}
int Application::WriteDataToFile() {
	ItemType item;
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name: ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(item);
	while (curIndex < length && curIndex != -1)
	{
		item.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(item);
	}

	m_OutFile.close();	// file close

	return 1;
}


void Application::RetrieveStudent() {
	int getId, findId; 
	cout << "\t write ID you wanna retrieve : "; 
	cin >> findId; 
	ItemType data; 

 
 	m_List.ResetList(); 
	int length = m_List.GetLength();
 	int curIndex = m_List.GetNextItem(data);

 	while (curIndex < length && curIndex != -1) 
	{ 
		getId = data.GetId(); 
		if (findId == getId) { 
 			m_List.Get(data); 
 			break; 
		} 
		curIndex = m_List.GetNextItem(data); 
	} 
 } 

void Application::DeleteStudent() {
	int getid, delid;
	cout << "Please Enter Id what you want to delete Id : ";
	cin >> delid;
	ItemType data;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);

	while (curIndex < length && curIndex != -1) {
		getid = data.GetId();
		if (getid == delid) {
			m_List.Delete(data);
			break;
		}
		curIndex = m_List.GetNextItem(data);
	}
}

void Application::Replace() {
	int getid, repid;
	cout << "Please Enter the id what you want to replace information Id: ";
	cin >> repid;

	ItemType data;
	string cname, caddress;
	cout << "enter name what you want to change name : ";
	cin>>cname;
	cout << "enter Address what you want to change address: ";
	cin >> caddress;

	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);

	while (curIndex < length && curIndex != -1) {
		getid = data.GetId();
		if (repid == getid) {
			data.SetName(cname);
			data.SetAddress(caddress);
			m_List.Replace(data);
			break;
		}
		curIndex = m_List.GetNextItem(data);
	}

}

