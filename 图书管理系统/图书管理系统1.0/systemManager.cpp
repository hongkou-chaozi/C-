#include"systemManager.h"	
SystemManager::SystemManager()
{
	this->m_index = 0;

}

void SystemManager::showMenu()
{
	cout << "                         ************************************************************" << endl;
	cout << "                         ***                   ��ӭʹ��ͼ�����ϵͳ               ***" << endl;
	cout << "                         ************************************************************" << endl;
	cout << "                         ***           1.���ͼ��                 2.�黹ͼ��      ***" << endl;
	cout << "                         ***           3.ͼ�鶪ʧ                 4.�鿴����ͼ��  ***" << endl;
	cout << "                         ***           5.����ͼ��                 6.�û�ע��      ***" << endl;
	cout << "                         ***           7.����ԱȨ��               8.������֪      ***" << endl;
	cout << "                         ************************************************************" << endl;
}

void SystemManager::coreManager()
{
	this->ManagerLogin();

	if (this->m_index == -1) 
	{

		this->m_index = 0;
		return;
	}

	while (1)
	{
		this->ManagerMenu();

		switch (getchar())
		{
		case '1': //���ͼ��
			this->Addbooks();
			break;
		case '2'://�¼�ͼ��
			this->bookRemove();
			break;
		case '3'://�鿴��������Ϣ
			this->searchUserinfo();
			break;
		case '4'://���ز˵�
			return;
		case '5'://�˳�ϵͳ
			cout << "��ӭ�´�ʹ�á�" << endl;
		
			exit(0);
		}
	}

	
	system("pause");
	
}

void SystemManager::ManagerLogin()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                   ���ѽ������Ա��¼����                ***" << endl;
	cout << "                         ***************************************************************" << endl;

	//��ȡ����Ա�����ļ�

	ifstream ifs;
	ifs.open("ManagerData.txt", ios::in);
	
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		return;
	}

	vector<string> v;

	string data;

	while (ifs >> data)
	{
		int pos = data.find(",");
		if (pos != string::npos) {
			string name = data.substr(0, pos);
			string password = data.substr(pos + 1);
			v.push_back(name);
			v.push_back(password);
		}
	}

	string name;
	char words[50];
	cout << "���������Ա�˺ţ�" << endl;
	cin >> name;

	int i = 0;
	cout << "���������Ա���룺" << endl;

	while (i < 9 && (words[i] = _getch()) && words[i] != '\r')
	{
		printf("*");
		i++;
	}

	cout << endl;
	words[i] = 0;
	string password(words);

	if (name == v[0] && password == v[1])
	{
		cout << "��¼�ɹ�" << endl;
		system("pause");

		return;
	}
	else
	{
		cout << "��¼ʧ��" << endl;
		system("pause");
		this->m_index = -1;

		return;
	}

	system("pause");
}

void SystemManager::ManagerMenu()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                   ���ѽ������Ա��������                ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***           1.���ͼ��                2.�¼�ͼ��          ***" << endl;
	cout << "                         ***                                                         ***" << endl;
	cout << "                         ***           3.�鿴�������            4.�������˵�        ***" << endl;
	cout << "                         ***                                                         ***" << endl;
	cout << "                         ***                          5�˳�ϵͳ                      ***" << endl;
	cout << "                         ***************************************************************" << endl;
}

//ͼ�鶪ʧ
void SystemManager::BookLost()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***          ͼ�鶪ʧ��ͨ�����·�ʽ��ϵͼ�����Ա           ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                 ͼ�����Ա�绰;10086                    ***" << endl;
	cout << "                         ***************************************************************" << endl;
	system("pause");
}

void SystemManager::regist()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***             ���û�ʹ�ñ�ϵͳǰ����ע���˺�              ***" << endl;
	cout << "                         ***************************************************************" << endl;

	cout << "����������ʹ�õ��˻����ƣ�����ʹ��8λ��ĸ����" << endl;

	string identity;
	cin >> identity;

	
	if (identity.length() != 8 || !isAlpha(identity))
	{
		cout << "��Ч���˻����ƣ����������롣" << endl;
		system("pause");
		return;
	}

	ifstream userfile("UserData.txt");
 
	if (!userfile) {
		cout << "�޷����ļ�." << endl;
		system("pause");
		return;
	}

	string Dataline;
	bool usernameExists = false;

	while (getline(userfile, Dataline)) {
		
		if (Dataline == identity) {
			cout << "�û����Ѵ��ڣ�" << endl;
			usernameExists = true;
			break; 
		}
	}

	if (usernameExists) {
		system("pause");
		system("cls");
		return;
	}

	string userpassword_1;
	string userpassword_2;

	int p_1 = 0;
	char p_1_words[50];
	cout << "����������ʹ�õ�6λ���룺" << endl;

	while (p_1 < 9 && (p_1_words[p_1] = _getch()) && p_1_words[p_1] != '\r')
	{
		printf("*");
		p_1++;
	}

	cout << endl;
	p_1_words[p_1] = 0;
	string Ruserpassword_1(p_1_words);

	if (Ruserpassword_1.length() != 6)
	{
		cout << "������Ч��������ע�ᡣ" << endl;
		system("pause");
		return;
	}

	cout << "���ٴ���������ʹ�õ����룺" << endl;
	int p_2 = 0;
	char p_2_words[50];

	while (p_2 < 9 && (p_2_words[p_2] = _getch()) && p_2_words[p_2] != '\r')
	{
		printf("*");
		p_2++;
	}

	cout << endl;
	p_2_words[p_2] = 0;
	string Ruserpassword_2(p_2_words);


	if (Ruserpassword_1 != Ruserpassword_2)
	{
		cout << "������������벻һ�£�������ע�ᣡ" << endl;
		system("pause");
		system("cls");
		return;
	}

	
	ofstream ofs;
	ofs.open("UserData.txt", ios::in | ios::app);
	ofs << identity << endl << Ruserpassword_2 << endl << endl;

	ofs.close();

	cout << "ע��ɹ���ע����Ϣ�ѱ��������أ�" << endl;
	system("pause");

}

bool SystemManager::isAlpha(const string& str)
{
	for (char c : str)
	{
		if (!isalpha(c))
			return false;
	}
	return true;
}

void SystemManager::knowledagement()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                          ������֪                       ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***               �黹ʱ����黹�����ѽ��ĵ�ͼ��            ***" << endl;
	cout << "                         ***            ��ѧC++��׾����������ĵط����ຣ��          ***" << endl;
	cout << "                         ***************************************************************" << endl;
	system("pause");
}

void SystemManager::Addbooks()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                          ���ͼ��                       ***" << endl;
	cout << "                         ***************************************************************" << endl;

	string bookname;
	int num = 0;
	int bookid;
	string type; //���ͣ� 1����ѧ  2������ѧ  3����ѧ 4������  5����ʷ  6������  7����ѧ  8����ѧ
	Books book;

	cout << "�����뱾����ӵ�ͼ��������";
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "�������" << i + 1 << "ͼ�����λ���ֱ��:" << endl;

		while (1)
		{
			cin >> bookid;
			if (bookid < 1000 || bookid > 9999)
			{
				cout << "�����ŷǷ�!" << endl;
				system("pause");
				return;
			}

			ifstream file;
			string fileline;
			file.open("BookData.txt", ios::in);

			while (getline(file, fileline))
			{
				string str = to_string(bookid);
				if (fileline == str)
				{
					cout << "��ͼ�����Ѵ���!" << endl;
					system("pause");
					return;
				}
			}
			break;
		}
		cout << "�������" << i + 1 << "ͼ�������:" << endl;
		while (1)
		{
			cin >> type;
			if (!(type == "��ѧ" || type == "����ѧ" || type == "��ѧ" || type == "����ѧ" || type == "��ʷѧ" || type == "����ѧ" || type == "��ѧ" || type == "��ѧ"))
			{
				cout << "�������Ƿ�!" << endl;
				system("pause");
				return;
			}
			else {
				break;
			}
		}
		cout << "�������" << i + 1 << "ͼ�������:" << endl;
		while (1)
		{
			cin >> bookname;
			ifstream file;
			string fileline;
			file.open("BookData.txt", ios::in);
				while (getline(file, fileline)) 
				{
					if (fileline == bookname)
					{
						cout << "��ͼ���Ѵ���!" << endl;
						system("pause");
						return;
					}
			    }
			break;
		}

		book.m_Name = bookname;
		book.m_type = type;

		this->m_Book.insert(pair<int, Books>(bookid, book));

		this->saveData();
		this->m_Book.clear();

		cout << "ͼ����ӳɹ�" << endl;

	}
	
	system("pause");
	system("cls");

 }

void SystemManager::saveData()
{
	ofstream ofs;
	ofs.open("BookData.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cout << "ͼ����ļ���ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (map<int, Books>::iterator it = this->m_Book.begin(); it != this->m_Book.end(); it++)
	{
		ofs << it->first << endl;
		ofs << it->second.m_type << endl;
		ofs << it->second.m_Name << endl;
		ofs << endl;
		
	}

	ofs.close();
}

void SystemManager::scanallbooks()
{
	system("pause");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                      ϵͳ��¼���ͼ��                   ***" << endl;
	cout << "                         ***************************************************************" << endl;
	
	ifstream ifs;
	ifs.open("BookData.txt", ios::in);

	string bookdata;
	
	while (getline(ifs, bookdata)) {

		cout << bookdata << endl;
	}

	system("pause");
	system("cls");
}

void SystemManager::searchbooks()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***               ����1��ͨ����λ���ֱ�Ų���               ***" << endl;
	cout << "                         ***               ����2��ͨ�����Ʋ���                       ***" << endl;
	cout << "                         ***************************************************************" << endl;

	char input1 = _getch();

	if (input1 != '1' && input1 != '2') {
		cout << "�Ƿ����룡";
		system("pause");
	}
		
	else if (input1 == '1')
	{
		cout << "������������ҵ�ͼ��ı�ţ�" << endl;

		ifstream file("BookData.txt");  // �滻Ϊ����ļ�·��

		string target;
		cin >> target;

		if (file.is_open()) {
			string line;
			bool foundTarget = false;

			while (getline(file, line)) {
				if (line == target) {
					foundTarget = true;
					cout << "����д��ڸ�ͼ�顣" << endl << endl;
				
					// ���Ŀ���ַ����������
					for (int i = 0; i < 2; i++) {
						if (getline(file, line))
							cout << line << endl;
					}

					break;  // �ҵ�Ŀ���ַ������˳�ѭ��
				}
			}
			if (!foundTarget) {
				cout << " " << "δ��������ҵ�����Ҫ�鼮����Ϣ��" << endl;
			}
			file.close();
		}
		else {
			cout << "�޷���ͼ����ļ���" << endl;
		}
	}
	else if (input1 == '2')
	{
		ifstream file("BookData.txt");  // �滻Ϊ����ļ�·��

		cout << "������������ҵ�ͼ������ƣ�" << endl;

		string target;
		cin >> target;

		bool found = false;  // ����Ƿ��ҵ�Ŀ���ַ���

		if (file.is_open()) {
			string line;
			string previousLines[2];  // ���ڴ洢ǰ�������ݵĻ�����
			int linesBeforeTarget = 2;
			int targetLineCount = 0;

			while (getline(file, line)) {
				if (line == target) {
					cout << "����д��ڸ�ͼ�顣" << endl << endl;
					
					cout << previousLines[(targetLineCount - 2) % 2] << endl;
					cout << previousLines[(targetLineCount - 1) % 2] << endl;
					
					found = true;  // �ҵ�Ŀ���ַ���
					break;  // �ҵ�Ŀ���ַ������˳�ѭ��
				}

				previousLines[targetLineCount % 2] = line;
				targetLineCount++;
			}
			file.close();
		}

		if (!found) {
			cout << "δ��������ҵ�����Ҫ�鼮����Ϣ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void removeLinesAfterTarget(vector<string>& lines, int targetIndex)
{
	lines.erase(lines.begin() + targetIndex, lines.begin() + targetIndex + 3);
}

void SystemManager::bookRemove()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                         ͼ���¼�                        ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                    ͨ����λ���ֱ���¼�                 ***" << endl;
	cout << "                         ***************************************************************" << endl;

	cout << "����������ɾ����ͼ��ı�ţ�";

	string bookid;
	cin >> bookid;
	string filename = "BookData.txt"; 
	vector<string> lines;

	// ��ȡ�ļ�
	ifstream inputFile(filename);

	string line;
	while (getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();

	// ����ÿһ��
	for (int i = 0; i < lines.size(); i++) {
		if (lines[i] == bookid) { // �滻Ϊ���Ŀ��������
			removeLinesAfterTarget(lines, i);
			break;
		}
	}
	// �����д���ļ�
	ofstream outputFile(filename);

	for (const auto& line : lines) {
		outputFile << line << std::endl;
	}

	outputFile.close();

	cout << "ͼ���¼ܳɹ���" << endl;
	system("pause");
	system("cls");
	
}

void SystemManager::borrowBook()
{
	//����ע����Ϣ
	string identity;
	cout << "�����������û�����:" << endl;
	while (1)
	{
		cin >> identity;
		ifstream file;
		string fileline;
		file.open("UserData.txt", ios::in);
		bool UserExist = false;
		while (getline(file, fileline))
		{
			if (fileline == identity)
			{
				UserExist = true;
				break;
			}
		}
		if (UserExist == false)
		{
			cout << "�û��������ڣ�����ע��!" << endl;
			system("pause");
			return;
		}
		else
		{
			break;
		}
	}
	cout << "�����������û�����:" << endl;

	while (1)
	{
		int p_2 = 0;
		char p_2_words[50];

		while (p_2 < 9 && (p_2_words[p_2] = _getch()) && p_2_words[p_2] != '\r')
		{
			printf("*");
			p_2++;
		}

		cout << endl;
		p_2_words[p_2] = 0;
		string Ruserpassword_2(p_2_words);
		ifstream file;
		string line;
		string target = identity;
		string NextLine;
		file.open("UserData.txt", ios::in);
		while (getline(file, line))
		{
			if (line == target)
			{
				if (getline(file, line))   //��ȡ�û�������һ�С�������
				{
					NextLine = line;
				}
				break;
			}
		}
		if (NextLine == Ruserpassword_2)
		{
			break;
		}
		else
		{
			cout << "�������!" << endl;
			system("pause");
			return;
		}
	}
	//�ȶԳɹ���չʾ����ͼ��
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***           �����˻���¼�ɹ������������п��ͼ��          ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***             ���ס��Ҫ����ͼ�����λ���ֱ��            ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***               ��������������鼮���Ľ���                ***" << endl;
	cout << "                         ***************************************************************" << endl;
	ifstream ifs;
	ifs.open("BookData.txt", ios::in);

	string bookdata;

	while (getline(ifs, bookdata)) {

		cout << bookdata << endl;
	}
	system("pause");
	//������Ҫ���ĵ�ͼ��ı��
	system("cls");

	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                    ��������λ���ֱ��:                  ***" << endl;
	cout << "                         ***************************************************************" << endl;

	string bookid;
	cin >> bookid;

	ifstream inputFile("BookData.txt");
	ofstream outputFile("Borrow.txt");
	vector<string> linesToMove;

	string targetLine = bookid; // �滻Ϊ��Ҫ���ҵ�Ŀ����

	if (inputFile.is_open() && outputFile.is_open()) {
		string line;
		bool targetFound = false;
		int count = 0;

		// ����BookData.txt�ļ���ÿһ��
		while (getline(inputFile, line)) 
		{
			// ����ҵ�Ŀ����
			if (line == targetLine) 
			{
				targetFound = true;
			}

			// ���Ŀ�����Ѿ��ҵ�����Ŀ���к�Ŀ���к����з���vector������
			if (targetFound) 
			{
				linesToMove.push_back(line);
				count++;

				if (count > 3)
				{
					break;
				}
			}
			// �ռ�����Ŀ���к�Ŀ���к�����
			for (const string& lineToWrite : linesToMove)
			{
				outputFile << lineToWrite << endl;
			}
			// ���vector����
			linesToMove.clear();
		}

		inputFile.close();
		outputFile.close();

		// ������targetLine�ַ���Ϊ���Ƶ��ļ���
		filesystem::create_directory(identity);

		// ��Borrow.txt�ļ��ƶ����´������ļ�����
		filesystem::rename("Borrow.txt", identity + "/Borrow.txt");
		

		cout << "���ĳɹ���" << std::endl;
	}
	
		system("pause");
		return;
}

void SystemManager::searchUserinfo()
{
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***             ������������ҵĽ������û�����:             ***" << endl;
	cout << "                         ***************************************************************" << endl;

	string identity;
	cin >> identity;

	string targetFolderName = identity;

	for (const auto& entry : std::filesystem::directory_iterator(".")) 
	{
		if (entry.is_directory() && entry.path().filename().string() == targetFolderName) 
		{
			string borrowTxtPath = entry.path().string() + "/Borrow.txt";
			ifstream borrowTxtFile(borrowTxtPath);

			if (borrowTxtFile.is_open()) 
			{
				string line;
				while (getline(borrowTxtFile, line)) {
					cout << line << endl;
				}
				borrowTxtFile.close();
			}
		}
	}
	system("pause");
	return;
}

void SystemManager::returnBook()
{
	//����ע����Ϣ
	string identity;
	cout << "�����������û�����:" << endl;
	while (1)
	{
		cin >> identity;
		ifstream file;
		string fileline;
		file.open("UserData.txt", ios::in);
		bool UserExist = false;
		while (getline(file, fileline))
		{
			if (fileline == identity)
			{
				UserExist = true;
				break;
			}
		}
		if (UserExist == false)
		{
			cout << "�û��������ڣ�����ע��!" << endl;
			system("pause");
			return;
		}
		else
		{
			break;
		}
	}
	cout << "�����������û�����:" << endl;

	while (1)
	{
		int p_2 = 0;
		char p_2_words[50];

		while (p_2 < 9 && (p_2_words[p_2] = _getch()) && p_2_words[p_2] != '\r')
		{
			printf("*");
			p_2++;
		}

		cout << endl;
		p_2_words[p_2] = 0;
		string Ruserpassword_2(p_2_words);
		ifstream file;
		string line;
		string target = identity;
		string NextLine;
		file.open("UserData.txt", ios::in);
		while (getline(file, line))
		{
			if (line == target)
			{
				if (getline(file, line))   //��ȡ�û�������һ�С�������
				{
					NextLine = line;
				}
				break;
			}
		}
		if (NextLine == Ruserpassword_2)
		{
			break;
		}
		else
		{
			cout << "�������!" << endl;
			system("pause");
			return;
		}
	}
	system("cls");
	cout << "ֻ��һ���Թ黹����ͼ�飬��ȷ��Ҫ���ڹ黹��?" << endl;
	cout << "ȷ���밴 1 ���� 2 �򷵻����˵���" << endl;

	int a;
	cin >> a;
	if (a == 1)
	{
		string targetFolderName = identity;

		for (const auto& entry : std::filesystem::directory_iterator("."))
		{
			if (entry.is_directory() && entry.path().filename().string() == targetFolderName)
			{
				string borrowTxtPath = entry.path().string() + "/Borrow.txt";

				if (filesystem::exists(borrowTxtPath))
				{
					filesystem::remove(borrowTxtPath);
					cout << "�黹�ɹ���" <<endl;
				}
				system("pause");
				return;
			}
		}
	}
	else if (a == 2)
	{
		return;
	}
}