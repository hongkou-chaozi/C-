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
		case '1': //���ͼ��
			sm.borrowBook();
			break;
		case '2'://�黹ͼ��
			sm.returnBook();
			break;
		case '3'://ͼ�鶪ʧ
			sm.BookLost();
			break;
		case '4'://�鿴����ͼ��
			sm.scanallbooks();
			break;
		case '5'://����ͼ��
			sm.searchbooks();
			break;
		case '6'://�û�ע��
			sm.regist();
			break;
		case '7'://����ԱȨ��
			sm.coreManager();
			break;
		case '8'://������֪
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
