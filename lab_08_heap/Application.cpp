/*
 *	@brief	���ø����̼� Ŭ������ ��� �Լ� �����
 *	@date	2019.10.06
 *	@author	��μ�
 */



#include "Application.h"
//���� ���� ���
void Application::Run()
{
	
		while (1)
		{
			m_Command = GetCommand();

			switch (m_Command)
			{
			case 1:
				AddMusic();	// �� ������ �Է� �޾� ����Ʈ�� �߰�					AddMusic();
				break;
			case 2:
				DeleteMusic();
				// ���� ������ȣ�� �Է� �޾� ����Ʈ���� ����					DeleteMusic();
				break;
			case 3:
				RetrieveMusic();
				break;
				//RetrieveMusic();
				//������ �̸��̳� �帣�� �ش��ϴ� ��� ã��.				
			case 4:
				ReplaceMusic();// �� MusicNumber ������ �Է� �޾Ƽ� ����Ʈ���� �ش� �� ������ ����			ReplaceMusic();
				break;

			case 5:		// ����Ʈ�� ����� ��� ���� ȭ�鿡 ���
				DisPlayAllMusic();
				break;
			case 6:
				MasterList.MakeEmpty();// ����Ʈ�� �Էµ� ��� ���� ����

				break;
			case 7:
				// load list data from a file.
				ReadDataFromFile();
				break;
			case 8:
				// save list data into a file.
				WriteDataToFile();
				break;
			case 9:
				AddToPlayList();
				break;

			case 10:
				PlayInsertOrder();//PlayList �� ��� �����ְ� ��� ASK
				break;

			case 11:
				DeletePlayList();
				break;
			case 12:
				AddSongToPL();
				break;
			case 13:
				DeleteSongFrPL();
				break;
			case 14:
				PlayOAddTime();
				break;
			case 15:
				PlayIOFreq();
				break;
			case 16:
				BSTAdd();
				break;
			case 17 :
				BTSDelete();
				break;
			case 18:
				BTSSearch();
				break;
			case 19:
				BTSUpdate();
				break;
			case 20:
			WhatHeap(); 
			case 21:
				MinHeapAdd();
				break;
			case 22 :
				MinHeapDelete();
				break;
			case 23:
				DequeueItem();
			case 24:
				MinHeapUpdate();
				break;
			case 25:
				MinHeapRetrieve();
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}


//���ο� ��ɾ� �޴� �κ� 
int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Retrieve Music" << endl;
	cout << "\t   4 : Replace Music list By Music Unique Number or Name" << endl;
	cout << "\t   5 : Display All Music" << endl;
	cout << "\t   6 : Delete All Music list" << endl;
	cout << "\t   7 : load list data from a file" << endl;
	cout << "\t   8 : save list data into a file " << endl;
	cout << "\t   9 : Add Play List By ID " << endl;
	cout << "\t   10 :Display Play List And Play" << endl;
	cout << "\t   11 :Delete Play List" << endl;
	cout << "\t------����ũ�� ����Ʈ ��ɵ�----" << endl;
	cout<<  "\t	12 : AddSongToPL() "<<endl;
	cout << "\t	13 : DeleteSongFrPL();" << endl;
	cout << "\t	14 : PlayOAddTime()" << endl;
	cout << "\t	15 : PlayIOFreq();" << endl;
	cout << "\t------������ġƮ�� ��ɵ�----" << endl;
	cout << "\t	16 : ����Ʈ���� �̿��� Add" << endl;
	cout << "\t	17 : ����Ʈ���� �̿��� Delete" << endl;
	cout << "\t	18 : ����Ʈ���� �̿��� Search" << endl;
	cout << "\t	19 : ����Ʈ���� �̿��� Update" << endl;
	cout << "\t------MinHeap ��ɵ�----" << endl;
	cout << "\t	20 : MaxHeap MinHeap�� �����ϼ���" << endl;
	cout << "\t	21 : Heap �̿��� Add" << endl;
	cout << "\t	22 : Heap �̿��� Delete" << endl;
	cout << "\t	23 : Heap ù��° ��� Delete" << endl;
	cout << "\t	24 : Heap �̿��� Update" << endl;
	cout << "\t	25 : Heap �̿��� Retrieve" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;


	return command;
}

//���� ������ Sorted �ϰ� �Է�.
int Application::AddMusic() {

	ItemType item;
	item.SetRecordFromKB();
	MasterList.Add(item);//Sorted ����
	DisPlayAllMusic();

	return 1;
}

//Sorted �� Delete �̿� Song Name ��
int Application::DeleteMusic() {
	int pre = MasterList.GetLength();//���� item������ �޾ƿ´�.
	
	ItemType item;
	item.SetMusicNumberFromKB();
	MasterList.Delete(item);

	if (pre > MasterList.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "<========DELETE SUCCESS !===========>" << endl << endl;
		cout << "\t Current List" << endl;
		this->DisPlayAllMusic();
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

//�Է¹��� ������ �ش� ��� ��� ����ϱ�
int Application::RetrieveMusic() {
	int getN;
	string MusicNumber, SingerName, genre, SongName;

	while (true) {
		cout << "\t\t� Ű����� �˻��Ұ��� ������." << endl;
		cout << "\t\t1.���� ������ȣ" << endl;
		cout << "\t\t2.���� ����" << endl;
		cout << "\t\t3.���� �帣" << endl;
		cout << "\t\t4.���� ����" << endl;
		cout << "\t\t5.exit" << endl;

		cout << "\t\t Choose one. (1~5) : ";
		cin >> getN;
		if (getN != 1 && getN != 2 && getN != 3 && getN != 4 &&getN!=5) { ///getN != 3 
			cout << "Wrong Input!" << endl;
			continue;
		}
		if (getN == 1) {
			cout << "ã�� ������ ������ȣ��(Primary Key) �Է��ϼ��� : ";
			cin >> MusicNumber;
			ItemType item;
			item.SetMusicNumber(MusicNumber);
			MasterList.RetrieveByBS(item);//�����˻� ���
			//item2.SetRecord(item.GetMusicNumber(), item.GetSongName(), item.GetSongMaker(), item.GetSinger(), item.Getgenre(), item.GetPlaynum(), item.GetInTime());
			//item2.DisPlayRecordOnScreen();
			
		}
		else if (getN == 2) {//2:Singer�϶� ������ �����ε�
			cout << "ã�� ������ ���� �̸��� �Է��ϼ��� : ";
			cin >> SingerName;
			ItemType item, item2;
			item.SetSinger(SingerName);
			MasterList.RetrieveBySinger(item);
			//item2.SetRecord(item.GetMusicNumber(), item.GetSongName(), item.GetSongMaker(), item.GetSinger(), item.Getgenre(), item.GetPlaynum(), item.GetInTime());
			item.DisPlayRecordOnScreen();
			
		}
		else if (getN == 3) {//3:Genre�϶��� ������ �����ε�
			cout << "ã�� ������ �帣�� �Է��ϼ��� : ";
			cin >> genre;
			ItemType item;
			item.SetSinger(genre);
			MasterList.RetrieveBygenre(item);
			//item2.SetRecord(item.GetMusicNumber(), item.GetSongName(), item.GetSongMaker(), item.GetSinger(), item.Getgenre(), item.GetPlaynum(), item.GetInTime());
			item.DisPlayRecordOnScreen();// Retrieve���� ���
			
		}
		else if (getN == 4) {
			cout << "ã�� ������ ������ �Է��ϼ���: ";
			cin >> SongName;
			ItemType item;
			item.SetSongName(SongName);
			MasterList.RetrieveBySongName(item);
			item.DisPlayRecordOnScreen();//item�� ����� ���� ���
		}
		else if (getN == 5)
			break;
	}
	return 0;
}
	
//Sorted �� replace �̿�
void Application::ReplaceMusic() {

	string repMusic;
	cout << "Please Enter the MusicNumber what you want to replace information : ";
	cin >> repMusic;

	ItemType data;
	string cSongName, cSongMaker, cSinger, cgenre;


	cout << "enter SongName what you want to change : ";
	cin >> cSongName;
	cout << "enter SongMaker what you want to change : ";
	cin >> cSongMaker;
	cout << "enter Singer what you want to change : ";
	cin >> cSinger;
	cout << "enter genre what you want to change : ";
	cin >> cgenre;

	MasterList.ResetList();
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(data);

	while (curIndex < length && curIndex != -1) {
		string getMusic = data.GetMusicNumber();
		if (repMusic == getMusic) {

			data.SetSongName(cSongName);
			data.SetSongMaker(cSongMaker);
			data.SetSinger(cSinger);
			data.Setgenre(cgenre);

			MasterList.Replace(data);
		}
	}
}



//list�� ��� �����͸� ȭ�鿡 ���.
void Application::DisPlayAllMusic() {
	ItemType data;
	cout << "\t=========================" <<endl;
	cout << "\n\tCurrent list" << endl;
	cout << "\t=========================" << endl;
	
	MasterList.ResetList();
	int length = MasterList.GetLength();
	for (int i = 0; i < length; i++) {
		MasterList.GetNextItem(data);
		data.DisPlayRecordOnScreen();
		cout << "\t=========================" << endl;
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
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		MasterList.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisPlayAllMusic();

}

int Application::WriteDataToFile() {
	ItemType item;
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name: ";
	cin >> filename;

	if (!OpenOutFile(filename))
		return 0;

	MasterList.ResetList();
	int length = MasterList.GetLength();
	int curIndex = MasterList.GetNextItem(item);
	while (curIndex < length && curIndex != -1)
	{
		item.WriteDataToFile(m_OutFile);
		curIndex = MasterList.GetNextItem(item);
	}

	m_OutFile.close();	// file close

	return 1;
}

//Play List ��� Circular Queue �̿�.
int Application::AddToPlayList() {
	//���� ������� ǥ��
	PlayItem play;
	ItemType item;
	play.SetMusicNumberFromKB();
	item.SetMusicNumber(play.GetMusicNumber());
	MasterList.RetrieveByMusicNumber(item);
	item.SetInTime(++Order);
	play.SetRecord(item.GetMusicNumber(),item.GetPlaynum(),item.GetInTime());
	
	if (!(PlayList.IsFull())) {
		//List�� Full�� �ƴҰ��
		
		if (MasterList.RetrieveByMusicNumber(item)) {//Id�� Master�� �����Ҷ� return 1
			//item�� master ���� ����.
			
			PlayList.EnQueue(play);
			cout << endl << "\t=================================" << endl;
			cout << "\tAdd Music Number: " << play.GetMusicNumber() << " is in PlayList!" << endl;
			cout << "\t=================================" << endl;
			return 0;
		}
		else {

			cout << endl << "\t=================================" << endl;
			cout << "This Music Number is not exist in Master List!!" << endl;
			cout << "\t=================================" << endl;
			return 0;

		}
	}
	else { //List�� Full�ϰ��
		PlayItem check;
		PlayList.DeQueue(check);//check�� ������ ���� ����
	
		PlayList.EnQueue(play);

		cout << endl << "\t=================================" << endl;
		cout << "\tDeleted Music Number is: " << check.GetMusicNumber() << endl;
		cout << "\t=================================" << endl;

		cout << endl << "\t=================================" << endl;
		cout << "\tAdd Music Number: " << play.GetMusicNumber() << " is in PlayList!" << endl;
		cout << "\t=================================" << endl;
		return 0;
	}
}

void Application::PlayInsertOrder() {
	PlayItem play;
	ItemType item;
	int count[30] = { 0 };//Play Count item���� ����ϱ����� �迭
	int count2 = 0; //Play Count item���� ����ϱ� ���� ����
	while (1) {
		cout <<endl<< "\tCurrent Play List : " << endl;
		PlayList.Print();
		cout << endl;
		string num;
		cout << endl;
		cout << "\t==============================================" << endl;
		cout << "\t Choose Music Number Do you want to play." << endl;
		cout << "\tif Press '0' is Exit PlayList." << endl;
		cout << "\tif Enter '-1' is Reset All Play Count." << endl;
		cout << "\t==============================================" << endl;
		cout << "\tNumber :";
		cin >> num;
		count2=atoi(num.c_str());//string�� int �� ��ȯ��Ű�� ���� �Լ�
		cout << endl << endl;
		if (num == "0")
			break;
		if (num == "-1") {
			for(int i=0;i<30;i++)
			count[i] = 0;
			item.SetPlaynum(0);
		}
		play.SetMusicNumber(num);//PlayItem ��ü�� MN ����
		item.SetMusicNumber(num);//masterList�� ���� key �Է�
		MasterList.RetrieveByMusicNumber(item);//item��ü�� MusicNumber�� ��ġ�ϴ� ��������
		int a = ++count[count2 - 1];
		item.SetPlaynum(a);//���� ���Ƚ���� item��ü�� ���� count++
		item.SetInTime(Order);
		play.SetRecord(item.GetMusicNumber(), item.GetPlaynum(), item.GetInTime());

		//item���� MusicNumber ��ġ�ϴ� 
		//maseter ���� �ԷµǾ�����
		//�Է¹��� num�� Playcount++ ���ش�.
		cout << "\t==============================================" << endl;
		cout << "\t Choosen Music Information is:" << endl;
		//masterList�� ���� �Է�.
		item.DisPlayRecordOnScreen();//Master �������
		cout << "\t==============================================" << endl;
	}
}

void Application::DeletePlayList() {
	//�÷��̸���Ʈ�� ���� ����
	PlayItem play;//item ��ü�� MN ����
	ItemType item; //master List�� �񱳸� ���� ��ü ����
	play.SetMusicNumberFromKB();
	item.SetMusicNumber(play.GetMusicNumber());
	MasterList.RetrieveByMusicNumber(item);

	if (!(PlayList.IsEmpty())) {
		//List�� empty�� �ƴҰ��
			PlayList.DeQueue(play);
			cout << endl << "\t=================================" << endl;
			cout << "\tDeleted Music Number is: " << endl;
			item.DisPlayRecordOnScreen();
			cout << "\t=================================" << endl;
			
		}
		else {

			cout << endl << "\t=================================" << endl;
			cout << "This Music Number is not exist in Master List!!" << endl;
			cout << "\t=================================" << endl;
			

		}
}
//----------------------����ũ�� ����Ʈ ------
int Application::AddSongToPL() {
	ItemType data;
	cout << "�÷��̸���Ʈ�� ���� MusicNumber�� �Է����ּ���." << endl;
	data.SetMusicNumberFromKB();//�÷��� ����Ʈ�� ������� ������
	if (MasterList.RetrieveByMusicNumber(data)) {
		TempList.Add(data);
		data.SetInTime(++Order);
		cout << "���������� ��ϵǾ����ϴ�." << endl;
	}
	return 0;
}
int Application::DeleteSongFrPL() {
	ItemType data;
	cout << "delete�ϰ��� �ϴ� ���� MusicNumber : ";
	data.SetMusicNumberFromKB();
	TempList.Delete(data);
	return 0;

}
int Application::PlayOAddTime() {
	string anw;
	ItemType data;
	DoublyIterator<ItemType>iter(TempList);
	int i = 0;
	int num;
	while (1) {
		i++;
		iter.Next();
		data = iter.Getdata();

		num = data.GetPlaynum() + 1;
		data.SetPlaynum(num);
		TempList.Replace(data);

		//		data.DisplayId();
		data.DisPlayPlaynumOnScreen();
		data.DisPlayInTimeOnScreen();

		MasterList.RetrieveByBS(data);
		data.DisPlayRecordOnScreen();

		if (i >= TempList.GetLength()) {
			iter.Reset();
			i = 0;
		}

		cout << "���� ���� ����Ͻðڽ��ϱ�? ��� �������� �ƹ�Ű��, �����Ϸ��� n" << endl;
		cin >> anw;
		if (anw == "n") break;

	}
	return 0;

}
int Application::PlayIOFreq() {
	string anw;
	ItemType data;
	int num;

	DoublyIterator<ItemType>iter1(TempList);
	DoublyIterator<ItemType>iter2(TempList);

	int length = TempList.GetLength();
	ItemType* v = new ItemType[length];


	int cnt;

	for (int i = 0; i < length; i++) {
		iter1.Next();
		iter2.Reset();
		iter2.Next();
		int x1 = iter1.Getdata().GetPlaynum();
		int x2 = iter2.Getdata().GetPlaynum();

		cnt = 0;
		for (int j = 0; j < length; j++) {
			if (x1 < x2)cnt++;
			iter2.Next();
			x2 = iter2.Getdata().GetPlaynum();
		}
		v[cnt] = iter1.Getdata();
	}
	int i = 0;

	while (1) {

		data = v[i];
		num = data.GetPlaynum() + 1;
		data.SetPlaynum(num);
		TempList.Replace(data);
		v[i] = data;

		data.DisPlayPlaynumOnScreen();
		data.DisPlayInTimeOnScreen();

		MasterList.RetrieveByBS(data);
		data.DisPlayRecordOnScreen();


		cout << "���� ���� ����Ϸ��� �ƹ�Ű��, �����Ϸ��� x" << endl;
		cin >> anw;
		i++;

		if (i >= MasterList.GetLength()) {
			i = 0;
		}
		if (anw == "x") break;
	}
	delete[] v;

	return 0;
}
void Application::DisPlayTree() {
	MasterList2.PrintTree(cout);
}

int Application::BSTAdd() {
	ItemType item;
	cout << "Insert Item : " << endl;
	item.SetRecordFromKB();				// Tree�� �߰��� item ���� Ű����κ��� �Է¹���

	MasterList2.Add(item);						// Add�Լ��� ���ؼ� item�� Tree�� �߰���
	DisPlayTree();						// ���� Tree�� node�� ��� �����
	return 1;
}

int Application::BTSDelete() {
	ItemType item;
	cout << "Input MusicNumber to delete item : " << endl;
	item.SetMusicNumberFromKB();		// Tree���� ������� �ϴ� item�� MusicNumber���� Ű����κ��� �Է¹���

	bool found;							// �˻����ο� ���� ����� ������ found
	MasterList2.RetrieveItem(item, found);		// RetrieveItem �Լ��� ���ؼ� Tree���� �˻�

	if (found == true)					// Tree�� item�� ������
	{
		MasterList2.DeleteItem(item);			// DeleteItem�Լ��� ���ؼ� Tree���� item���� �ش��ϴ� ��带 ������
		DisPlayTree();
		return 1;// ����� ������ Tree�� ���
	}
	else {
		cout << "No item to delete" << endl;	// ������� �ϴ� ���� node�� ���� ��� 
		return 0;
	}
	
}
int Application::BTSSearch() {
	ItemType item;
	cout << "Input MusicNumber to search item : " << endl;
	item.SetMusicNumberFromKB();								// �˻��ϰ��� �ϴ� ��(Id)�� Ű����κ��� �Է¹���

	bool found;										// �̻����θ� ������ found
	MasterList2.RetrieveItem(item, found);					// RetrieveItem �Լ��� ���� Tree���� �˻�
	if (found == true)								// ã���� ã�Ҵٴ� ������ �Բ�, ���� �������� ���
	{
		cout << "Target item exists in the list." << endl;
		item.DisPlayRecordOnScreen();
		return 1;
	}
	else
		cout << "Target item is not in the list." << endl;		// �� ã������ �� ã�Ҵٴ� ������ ���
	return 0;
}
int	Application::BTSUpdate() {
	ItemType GetItem,SetItem;
	bool Check; //Update �� ���������� True 
	cout << "Input MusicNumber to Update item : " << endl;
	GetItem.SetMusicNumberFromKB();
	cout << "Input Information to Update Music information" << endl;
	SetItem.SetRecordFromKB();
	MasterList2.UpdateItem(GetItem, SetItem, Check);
	return 0;
}


///////////////////////Heap ���////////////
// MaxHeap�� MinHeap �� �� �ϳ��� �����ϴ� �Լ�.
void Application::WhatHeap()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Max Heap" << endl;
	cout << "\t   2 : Min Heap" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	switch (command)
	{
	case 1:		// Max Heap
		HeapList = new CMaxHeap<ItemType>(10);
		break;
	case 2:		// Min Heap
		HeapList= new CMinHeap<ItemType>(10);
		break;
	case 0:		// ����
		return;
	default:	// �� ��
		cout << "\tIllegal sellection...\n";
		break;
	}

}



int Application::MinHeapAdd() {
	ItemType item;
	cout << "�߰��� ������ ������ �Է��ϼ���: ";
	item.SetRecordFromKB();	//�߰��� ������ ���� �Է�
	
	if (!HeapList->IsFull()) {
		HeapList->Add(item);		//Heap�� ������ �߰�
		cout << "----�߰� ����! �����������----" << endl;
		HeapList->PrintHeap();
		cout << endl;
		return 1;
	}
	else {
		cout << "�߰� ����!" << endl;
		return 0;
	}
}
int Application::MinHeapUpdate() {
	ItemType item;
	bool found = false;
	cout << "������ ������ MusicNumber�� �Է��ϼ���. ";
	item.GetMusicNumber();
	HeapList->RetrieveItem(item,found);
	if (found == true) {
		ItemType item2;
		cout << "���ο� ������ �Է��ϼ���." << endl;
		item2.SetRecordFromKB();
		HeapList->UpdateItem(item,item2,found);
		cout << "----�����������----" << endl;
		HeapList->PrintHeap();
		return 1;
	}
	else {
		cout << "���� ����!"<<endl<<endl;
		return 0;
	}
}
int Application::MinHeapDelete() {
	ItemType item;
	if (!HeapList->IsEmpty()) {
		cout << "������ ������ MusicNumber�� �Է��ϼ���. ";
		item.GetMusicNumber();
		if (HeapList->Delete(item)) {
			cout << "��������" << endl;
			cout << "----�����������----" << endl;
			HeapList->PrintHeap();
			return 1;
		}
		else
		{
			cout << "��������! ����� ������ϴ�." << endl;
			return 0;
		}
	}
}
	// Heap���� ù��° ��ǰ������ �����ϱ� ���� �Լ�.
	int Application::DequeueItem(){
		if (!HeapList->IsEmpty()) // Heap�� Empty���� �ƴ��� �˻�
		{
			HeapList->Dequeue(); // ù��° ��ǰ���� ����
		}
		else
		{
			cout << "\tEmpty!!!" << endl;
		}
		return 1;
	}

	int Application::MinHeapRetrieve() {
		ItemType item;
		bool found = false;
		if (!HeapList->IsEmpty()) {
			cout << "�˻��� MusicNumber�� �Է��ϼ���.";
			item.GetMusicNumber();
			HeapList->RetrieveItem(item, found);//��ǰ�����˻�
			//Heap���� ��ǰ�� ã�Ҵ��� ��ã�Ҵ��� �Ǵ�
			if (found == true) {
				cout << "---�˻��� ������ ����---" << endl;
				item.DisPlayRecordOnScreen();
				return 1;
			}
			else {
				cout << "�˻�����!" << endl;
				return 0;
			}
		}
	}

