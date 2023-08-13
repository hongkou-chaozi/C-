#pragma once
#include <iostream>	
#include<fstream>
#include<vector>
#include<conio.h>
#include<string>
#include<cstdlib>
#include"books.h"
#include<map>
#include<sstream>
#include <cstdio>
#include<filesystem>

using namespace std;

class SystemManager
{
public:
	SystemManager();

	void showMenu();

	void coreManager();

	void ManagerLogin();

	void ManagerMenu();

	void BookLost();

	void regist();

	bool isAlpha(const string& str);

	void knowledagement();

	void Addbooks();

	map<int, Books> m_Book; //系统添加图书的中间容器

	void saveData();

	void scanallbooks();

	void searchbooks();

	void bookRemove();

	void borrowBook();

	void searchUserinfo();

	void returnBook();

	int m_index;

};