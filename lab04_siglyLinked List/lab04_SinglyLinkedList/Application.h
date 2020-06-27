//breif 어플리케이션 헤더
// @date	2019.10.14
//@author	김민성



#pragma once

#include <iostream>
using namespace std;

#include "SongList.h"
#include "SingerType.h"
#include "LinkedList.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	LinkedList<SongList> m_List;	///< Linked-list for ItemType.
	LinkedList<SingerType> m_SingerList;// Linked-list for SingerType.
	SongList
	int m_nCurCommand;	///< current command number

public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_nCurCommand = 0;
	}

	/**
	*	destructor.
	*/
	~Application()
	{
	}
	
	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int InsertItem();

	/**
	*	@brief	Delete record into list.
	*	@pre	list should be not empty.
	*	@post	record is deleted into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int DeleteItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();

	/**
	*	@brief	Make empty list.
	*	@pre	none.
	*	@post	Make empty list in this member.
	*/
	int MakeEmpty();

	/**
	*	@brief	Retrieve item in the list.
	*	@pre	none.
	*	@post	none.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	int RetrieveItem();

	/**
	*	@brief	Change item's value in the list.
	*	@pre	none.
	*	@post	target item's value is changed.
	*	@return	1 if succeeded changing item's value, otherwise 0.
	*/
	int Update();

		/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();
	void DisplayAllFromSingerList();
	void AddSinger();//새로운 가수를 추가
	void AddSong();//추가할 곡의 가수를 검색하고 songlist에 추가
					//존재하지 않으면 가수를 추가하고 입력된 곡을 추가
	
	void SearchBySinger();//singerlist에서 가수를 검색하고  해당 가수가 부른 모든 곡의
							//자세한 정보를 화면에 출력

};

