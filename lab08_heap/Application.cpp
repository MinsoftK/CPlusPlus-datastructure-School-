/*
 *	@brief	어플리케이션 클래스의 멤버 함수 선언부
 *	@date	2019.10.06
 *	@author	김민성
 */



#include "Application.h"
//메인 실행 목록
void Application::Run()
{
	
		while (1)
		{
			m_Command = GetCommand();

			switch (m_Command)
			{
			case 1:
				AddMusic();	// 곡 정보를 입력 받아 리스트에 추가					AddMusic();
				break;
			case 2:
				DeleteMusic();
				// 곡의 고유번호를 입력 받아 리스트에서 삭제					DeleteMusic();
				break;
			case 3:
				RetrieveMusic();
				break;
				//RetrieveMusic();
				//가수의 이름이나 장르로 해당하는 곡들 찾기.				
			case 4:
				ReplaceMusic();// 곡 MusicNumber 정보를 입력 받아서 리스트에서 해당 곡 정보를 갱신			ReplaceMusic();
				break;

			case 5:		// 리스트에 저장된 모든 곡을 화면에 출력
				DisPlayAllMusic();
				break;
			case 6:
				MasterList.MakeEmpty();// 리스트에 입력된 모든 곡을 삭제

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
				PlayInsertOrder();//PlayList 의 목록 보여주고 재생 ASK
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


//메인에 명령어 받는 부분 
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
	cout << "\t------더블링크드 리스트 기능들----" << endl;
	cout<<  "\t	12 : AddSongToPL() "<<endl;
	cout << "\t	13 : DeleteSongFrPL();" << endl;
	cout << "\t	14 : PlayOAddTime()" << endl;
	cout << "\t	15 : PlayIOFreq();" << endl;
	cout << "\t------이진서치트리 기능들----" << endl;
	cout << "\t	16 : 이진트리를 이용한 Add" << endl;
	cout << "\t	17 : 이진트리를 이용한 Delete" << endl;
	cout << "\t	18 : 이진트리를 이용한 Search" << endl;
	cout << "\t	19 : 이진트리를 이용한 Update" << endl;
	cout << "\t------MinHeap 기능들----" << endl;
	cout << "\t	20 : MaxHeap MinHeap을 선택하세요" << endl;
	cout << "\t	21 : Heap 이용한 Add" << endl;
	cout << "\t	22 : Heap 이용한 Delete" << endl;
	cout << "\t	23 : Heap 첫번째 노드 Delete" << endl;
	cout << "\t	24 : Heap 이용한 Update" << endl;
	cout << "\t	25 : Heap 이용한 Retrieve" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;


	return command;
}

//음악 정보를 Sorted 하게 입력.
int Application::AddMusic() {

	ItemType item;
	item.SetRecordFromKB();
	MasterList.Add(item);//Sorted 과정
	DisPlayAllMusic();

	return 1;
}

//Sorted 의 Delete 이용 Song Name 비교
int Application::DeleteMusic() {
	int pre = MasterList.GetLength();//이전 item개수를 받아온다.
	
	ItemType item;
	item.SetMusicNumberFromKB();
	MasterList.Delete(item);

	if (pre > MasterList.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << "<========DELETE SUCCESS !===========>" << endl << endl;
		cout << "\t Current List" << endl;
		this->DisPlayAllMusic();
		return 1;
	}

	cout << "<========DELETE FAIL !=======>" << endl;
	return 0;
}

//입력받은 정보로 해당 곡들 모두 출력하기
int Application::RetrieveMusic() {
	int getN;
	string MusicNumber, SingerName, genre, SongName;

	while (true) {
		cout << "\t\t어떤 키워드로 검색할건지 고르세요." << endl;
		cout << "\t\t1.음원 고유번호" << endl;
		cout << "\t\t2.음원 가수" << endl;
		cout << "\t\t3.음원 장르" << endl;
		cout << "\t\t4.음원 제목" << endl;
		cout << "\t\t5.exit" << endl;

		cout << "\t\t Choose one. (1~5) : ";
		cin >> getN;
		if (getN != 1 && getN != 2 && getN != 3 && getN != 4 &&getN!=5) { ///getN != 3 
			cout << "Wrong Input!" << endl;
			continue;
		}
		if (getN == 1) {
			cout << "찾을 음원의 고유번호를(Primary Key) 입력하세요 : ";
			cin >> MusicNumber;
			ItemType item;
			item.SetMusicNumber(MusicNumber);
			MasterList.RetrieveByBS(item);//이진검색 사용
			//item2.SetRecord(item.GetMusicNumber(), item.GetSongName(), item.GetSongMaker(), item.GetSinger(), item.Getgenre(), item.GetPlaynum(), item.GetInTime());
			//item2.DisPlayRecordOnScreen();
			
		}
		else if (getN == 2) {//2:Singer일때 연산자 오버로딩
			cout << "찾을 음원의 가수 이름을 입력하세요 : ";
			cin >> SingerName;
			ItemType item, item2;
			item.SetSinger(SingerName);
			MasterList.RetrieveBySinger(item);
			//item2.SetRecord(item.GetMusicNumber(), item.GetSongName(), item.GetSongMaker(), item.GetSinger(), item.Getgenre(), item.GetPlaynum(), item.GetInTime());
			item.DisPlayRecordOnScreen();
			
		}
		else if (getN == 3) {//3:Genre일때의 연산자 오버로딩
			cout << "찾을 음원의 장르를 입력하세요 : ";
			cin >> genre;
			ItemType item;
			item.SetSinger(genre);
			MasterList.RetrieveBygenre(item);
			//item2.SetRecord(item.GetMusicNumber(), item.GetSongName(), item.GetSongMaker(), item.GetSinger(), item.Getgenre(), item.GetPlaynum(), item.GetInTime());
			item.DisPlayRecordOnScreen();// Retrieve에서 출력
			
		}
		else if (getN == 4) {
			cout << "찾을 음원의 제목을 입력하세요: ";
			cin >> SongName;
			ItemType item;
			item.SetSongName(SongName);
			MasterList.RetrieveBySongName(item);
			item.DisPlayRecordOnScreen();//item에 저장된 정보 출력
		}
		else if (getN == 5)
			break;
	}
	return 0;
}
	
//Sorted 의 replace 이용
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



//list의 모든 데이터를 화면에 출력.
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
		MasterList.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
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

//Play List 등록 Circular Queue 이용.
int Application::AddToPlayList() {
	//들어온 순서대로 표시
	PlayItem play;
	ItemType item;
	play.SetMusicNumberFromKB();
	item.SetMusicNumber(play.GetMusicNumber());
	MasterList.RetrieveByMusicNumber(item);
	item.SetInTime(++Order);
	play.SetRecord(item.GetMusicNumber(),item.GetPlaynum(),item.GetInTime());
	
	if (!(PlayList.IsFull())) {
		//List가 Full이 아닐경우
		
		if (MasterList.RetrieveByMusicNumber(item)) {//Id가 Master에 존재할때 return 1
			//item에 master 정보 저장.
			
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
	else { //List가 Full일경우
		PlayItem check;
		PlayList.DeQueue(check);//check에 삭제된 정보 저장
	
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
	int count[30] = { 0 };//Play Count item별로 기록하기위한 배열
	int count2 = 0; //Play Count item별로 기록하기 위한 변수
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
		count2=atoi(num.c_str());//string을 int 로 변환시키기 위한 함수
		cout << endl << endl;
		if (num == "0")
			break;
		if (num == "-1") {
			for(int i=0;i<30;i++)
			count[i] = 0;
			item.SetPlaynum(0);
		}
		play.SetMusicNumber(num);//PlayItem 객체에 MN 받음
		item.SetMusicNumber(num);//masterList와 비교할 key 입력
		MasterList.RetrieveByMusicNumber(item);//item객체에 MusicNumber가 일치하는 정보저장
		int a = ++count[count2 - 1];
		item.SetPlaynum(a);//현재 재생횟수를 item객체에 저장 count++
		item.SetInTime(Order);
		play.SetRecord(item.GetMusicNumber(), item.GetPlaynum(), item.GetInTime());

		//item에는 MusicNumber 일치하는 
		//maseter 정보 입력되어있음
		//입력받은 num을 Playcount++ 해준다.
		cout << "\t==============================================" << endl;
		cout << "\t Choosen Music Information is:" << endl;
		//masterList의 정보 입력.
		item.DisPlayRecordOnScreen();//Master 정보출력
		cout << "\t==============================================" << endl;
	}
}

void Application::DeletePlayList() {
	//플레이리스트의 내용 삭제
	PlayItem play;//item 객체에 MN 저장
	ItemType item; //master List와 비교를 위한 객체 생성
	play.SetMusicNumberFromKB();
	item.SetMusicNumber(play.GetMusicNumber());
	MasterList.RetrieveByMusicNumber(item);

	if (!(PlayList.IsEmpty())) {
		//List가 empty가 아닐경우
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
//----------------------더블링크드 리스트 ------
int Application::AddSongToPL() {
	ItemType data;
	cout << "플레이리스트에 넣을 MusicNumber를 입력해주세요." << endl;
	data.SetMusicNumberFromKB();//플레이 리스트에 집어넣을 음악의
	if (MasterList.RetrieveByMusicNumber(data)) {
		TempList.Add(data);
		data.SetInTime(++Order);
		cout << "성공적으로 등록되었습니다." << endl;
	}
	return 0;
}
int Application::DeleteSongFrPL() {
	ItemType data;
	cout << "delete하고자 하는 곡의 MusicNumber : ";
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

		cout << "다음 곡을 재생하시겠습니까? 계속 들으려면 아무키나, 정지하려면 n" << endl;
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


		cout << "다음 곡을 재생하려면 아무키나, 정지하려면 x" << endl;
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
	item.SetRecordFromKB();				// Tree에 추가할 item 값을 키보드로부터 입력받음

	MasterList2.Add(item);						// Add함수를 통해서 item을 Tree에 추가함
	DisPlayTree();						// 현재 Tree의 node를 모두 출력함
	return 1;
}

int Application::BTSDelete() {
	ItemType item;
	cout << "Input MusicNumber to delete item : " << endl;
	item.SetMusicNumberFromKB();		// Tree에서 지우려고 하는 item의 MusicNumber값을 키보드로부터 입력받음

	bool found;							// 검색여부에 따른 결과를 저장할 found
	MasterList2.RetrieveItem(item, found);		// RetrieveItem 함수를 통해서 Tree에서 검색

	if (found == true)					// Tree에 item이 있으면
	{
		MasterList2.DeleteItem(item);			// DeleteItem함수를 통해서 Tree에서 item값에 해당하는 노드를 삭제함
		DisPlayTree();
		return 1;// 지우고 나서의 Tree를 출력
	}
	else {
		cout << "No item to delete" << endl;	// 지우려고 하는 값의 node가 없을 경우 
		return 0;
	}
	
}
int Application::BTSSearch() {
	ItemType item;
	cout << "Input MusicNumber to search item : " << endl;
	item.SetMusicNumberFromKB();								// 검색하고자 하는 값(Id)을 키보드로부터 입력받음

	bool found;										// 겁색여부를 저장할 found
	MasterList2.RetrieveItem(item, found);					// RetrieveItem 함수를 통해 Tree에서 검색
	if (found == true)								// 찾으면 찾았다는 문구와 함께, 관련 정보까지 출력
	{
		cout << "Target item exists in the list." << endl;
		item.DisPlayRecordOnScreen();
		return 1;
	}
	else
		cout << "Target item is not in the list." << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	return 0;
}
int	Application::BTSUpdate() {
	ItemType GetItem,SetItem;
	bool Check; //Update 에 성공했으면 True 
	cout << "Input MusicNumber to Update item : " << endl;
	GetItem.SetMusicNumberFromKB();
	cout << "Input Information to Update Music information" << endl;
	SetItem.SetRecordFromKB();
	MasterList2.UpdateItem(GetItem, SetItem, Check);
	return 0;
}


///////////////////////Heap 기능////////////
// MaxHeap와 MinHeap 둘 중 하나를 선택하는 함수.
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
	case 0:		// 종료
		return;
	default:	// 그 외
		cout << "\tIllegal sellection...\n";
		break;
	}

}



int Application::MinHeapAdd() {
	ItemType item;
	cout << "추가할 음원의 정보를 입력하세요: ";
	item.SetRecordFromKB();	//추가할 음원의 정보 입력
	
	if (!HeapList->IsFull()) {
		HeapList->Add(item);		//Heap에 데이터 추가
		cout << "----추가 성공! 현재음원목록----" << endl;
		HeapList->PrintHeap();
		cout << endl;
		return 1;
	}
	else {
		cout << "추가 실패!" << endl;
		return 0;
	}
}
int Application::MinHeapUpdate() {
	ItemType item;
	bool found = false;
	cout << "갱신할 음원의 MusicNumber를 입력하세요. ";
	item.GetMusicNumber();
	HeapList->RetrieveItem(item,found);
	if (found == true) {
		ItemType item2;
		cout << "새로운 정보를 입력하세요." << endl;
		item2.SetRecordFromKB();
		HeapList->UpdateItem(item,item2,found);
		cout << "----현재음원목록----" << endl;
		HeapList->PrintHeap();
		return 1;
	}
	else {
		cout << "갱신 실패!"<<endl<<endl;
		return 0;
	}
}
int Application::MinHeapDelete() {
	ItemType item;
	if (!HeapList->IsEmpty()) {
		cout << "삭제할 음원의 MusicNumber를 입력하세요. ";
		item.GetMusicNumber();
		if (HeapList->Delete(item)) {
			cout << "삭제성공" << endl;
			cout << "----현재음원목록----" << endl;
			HeapList->PrintHeap();
			return 1;
		}
		else
		{
			cout << "삭제실패! 목록이 비었습니다." << endl;
			return 0;
		}
	}
}
	// Heap에서 첫번째 제품정보를 삭제하기 위한 함수.
	int Application::DequeueItem(){
		if (!HeapList->IsEmpty()) // Heap가 Empty인지 아닌지 검사
		{
			HeapList->Dequeue(); // 첫번째 제품정보 삭제
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
			cout << "검색할 MusicNumber를 입력하세요.";
			item.GetMusicNumber();
			HeapList->RetrieveItem(item, found);//제품정보검색
			//Heap에서 제품을 찾았는지 못찾았는지 판단
			if (found == true) {
				cout << "---검색한 음원의 정보---" << endl;
				item.DisPlayRecordOnScreen();
				return 1;
			}
			else {
				cout << "검색실패!" << endl;
				return 0;
			}
		}
	}

