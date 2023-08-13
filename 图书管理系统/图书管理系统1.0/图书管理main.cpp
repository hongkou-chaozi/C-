#include<iostream>	
#include"systemManager.h"
using namespace std;

int main() {
	
	SystemManager sm;

	while (1)
	{
		sm.showMenu();

		switch (getchar())	
		{	
		case '1': //租借图书
			sm.borrowBook();
			break;
		case '2'://归还图书
			sm.returnBook();
			break;
		case '3'://图书丢失
			sm.BookLost();
			break;
		case '4'://查看所有图书
			sm.scanallbooks();
			break;
		case '5'://查找图书
			sm.searchbooks();
			break;
		case '6'://用户注册
			sm.regist();
			break;
		case '7'://管理员权限
			sm.coreManager();
			break;
		case '8'://借阅须知
			sm.knowledagement();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
