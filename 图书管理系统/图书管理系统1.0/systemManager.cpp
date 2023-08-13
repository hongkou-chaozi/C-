#include"systemManager.h"	
SystemManager::SystemManager()
{
	this->m_index = 0;

}

void SystemManager::showMenu()
{
	cout << "                         ************************************************************" << endl;
	cout << "                         ***                   欢迎使用图书管理系统               ***" << endl;
	cout << "                         ************************************************************" << endl;
	cout << "                         ***           1.租借图书                 2.归还图书      ***" << endl;
	cout << "                         ***           3.图书丢失                 4.查看所有图书  ***" << endl;
	cout << "                         ***           5.查找图书                 6.用户注册      ***" << endl;
	cout << "                         ***           7.管理员权限               8.借阅须知      ***" << endl;
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
		case '1': //添加图书
			this->Addbooks();
			break;
		case '2'://下架图书
			this->bookRemove();
			break;
		case '3'://查看借书人信息
			this->searchUserinfo();
			break;
		case '4'://返回菜单
			return;
		case '5'://退出系统
			cout << "欢迎下次使用。" << endl;
		
			exit(0);
		}
	}

	
	system("pause");
	
}

void SystemManager::ManagerLogin()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                   您已进入管理员登录界面                ***" << endl;
	cout << "                         ***************************************************************" << endl;

	//读取管理员数据文件

	ifstream ifs;
	ifs.open("ManagerData.txt", ios::in);
	
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
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
	cout << "请输入管理员账号：" << endl;
	cin >> name;

	int i = 0;
	cout << "请输入管理员密码：" << endl;

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
		cout << "登录成功" << endl;
		system("pause");

		return;
	}
	else
	{
		cout << "登录失败" << endl;
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
	cout << "                         ***                   您已进入管理员操作界面                ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***           1.添加图书                2.下架图书          ***" << endl;
	cout << "                         ***                                                         ***" << endl;
	cout << "                         ***           3.查看借阅情况            4.返回主菜单        ***" << endl;
	cout << "                         ***                                                         ***" << endl;
	cout << "                         ***                          5退出系统                      ***" << endl;
	cout << "                         ***************************************************************" << endl;
}

//图书丢失
void SystemManager::BookLost()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***          图书丢失请通过以下方式联系图书管理员           ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                 图书管理员电话;10086                    ***" << endl;
	cout << "                         ***************************************************************" << endl;
	system("pause");
}

void SystemManager::regist()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***             新用户使用本系统前请先注册账号              ***" << endl;
	cout << "                         ***************************************************************" << endl;

	cout << "请输入您想使用的账户名称（仅可使用8位字母）：" << endl;

	string identity;
	cin >> identity;

	
	if (identity.length() != 8 || !isAlpha(identity))
	{
		cout << "无效的账户名称！请重新输入。" << endl;
		system("pause");
		return;
	}

	ifstream userfile("UserData.txt");
 
	if (!userfile) {
		cout << "无法打开文件." << endl;
		system("pause");
		return;
	}

	string Dataline;
	bool usernameExists = false;

	while (getline(userfile, Dataline)) {
		
		if (Dataline == identity) {
			cout << "用户名已存在！" << endl;
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
	cout << "请输入您想使用的6位密码：" << endl;

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
		cout << "密码无效！请重新注册。" << endl;
		system("pause");
		return;
	}

	cout << "请再次输入您想使用的密码：" << endl;
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
		cout << "两次输入的密码不一致，请重新注册！" << endl;
		system("pause");
		system("cls");
		return;
	}

	
	ofstream ofs;
	ofs.open("UserData.txt", ios::in | ios::app);
	ofs << identity << endl << Ruserpassword_2 << endl << endl;

	ofs.close();

	cout << "注册成功，注册信息已保存至本地！" << endl;
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
	cout << "                         ***                          借书须知                       ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***               归还时必须归还所有已借阅的图书            ***" << endl;
	cout << "                         ***            初学C++的拙作，有问题的地方望多海涵          ***" << endl;
	cout << "                         ***************************************************************" << endl;
	system("pause");
}

void SystemManager::Addbooks()
{
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                          添加图书                       ***" << endl;
	cout << "                         ***************************************************************" << endl;

	string bookname;
	int num = 0;
	int bookid;
	string type; //类型： 1，哲学  2，政治学  3，文学 4，艺术  5，历史  6，地理  7，数学  8，工学
	Books book;

	cout << "请输入本次添加的图书数量：";
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "图书的四位数字编号:" << endl;

		while (1)
		{
			cin >> bookid;
			if (bookid < 1000 || bookid > 9999)
			{
				cout << "输入编号非法!" << endl;
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
					cout << "该图书编号已存在!" << endl;
					system("pause");
					return;
				}
			}
			break;
		}
		cout << "请输入第" << i + 1 << "图书的类型:" << endl;
		while (1)
		{
			cin >> type;
			if (!(type == "哲学" || type == "政治学" || type == "文学" || type == "艺术学" || type == "历史学" || type == "地理学" || type == "理学" || type == "工学"))
			{
				cout << "输入类别非法!" << endl;
				system("pause");
				return;
			}
			else {
				break;
			}
		}
		cout << "请输入第" << i + 1 << "图书的名称:" << endl;
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
						cout << "该图书已存在!" << endl;
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

		cout << "图书添加成功" << endl;

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
		cout << "图书库文件打开失败！" << endl;
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
	cout << "                         ***                      系统已录入的图书                   ***" << endl;
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
	cout << "                         ***               输入1：通过四位数字编号查找               ***" << endl;
	cout << "                         ***               输入2：通过名称查找                       ***" << endl;
	cout << "                         ***************************************************************" << endl;

	char input1 = _getch();

	if (input1 != '1' && input1 != '2') {
		cout << "非法输入！";
		system("pause");
	}
		
	else if (input1 == '1')
	{
		cout << "请输入您想查找的图书的编号：" << endl;

		ifstream file("BookData.txt");  // 替换为你的文件路径

		string target;
		cin >> target;

		if (file.is_open()) {
			string line;
			bool foundTarget = false;

			while (getline(file, line)) {
				if (line == target) {
					foundTarget = true;
					cout << "书库中存在该图书。" << endl << endl;
				
					// 输出目标字符串后的两行
					for (int i = 0; i < 2; i++) {
						if (getline(file, line))
							cout << line << endl;
					}

					break;  // 找到目标字符串后退出循环
				}
			}
			if (!foundTarget) {
				cout << " " << "未从书库中找到您需要书籍的信息。" << endl;
			}
			file.close();
		}
		else {
			cout << "无法打开图书库文件。" << endl;
		}
	}
	else if (input1 == '2')
	{
		ifstream file("BookData.txt");  // 替换为你的文件路径

		cout << "请输入您想查找的图书的名称：" << endl;

		string target;
		cin >> target;

		bool found = false;  // 标记是否找到目标字符串

		if (file.is_open()) {
			string line;
			string previousLines[2];  // 用于存储前两行内容的缓冲区
			int linesBeforeTarget = 2;
			int targetLineCount = 0;

			while (getline(file, line)) {
				if (line == target) {
					cout << "书库中存在该图书。" << endl << endl;
					
					cout << previousLines[(targetLineCount - 2) % 2] << endl;
					cout << previousLines[(targetLineCount - 1) % 2] << endl;
					
					found = true;  // 找到目标字符串
					break;  // 找到目标字符串后退出循环
				}

				previousLines[targetLineCount % 2] = line;
				targetLineCount++;
			}
			file.close();
		}

		if (!found) {
			cout << "未从书库中找到您需要书籍的信息。" << endl;
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
	cout << "                         ***                         图书下架                        ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                    通过四位数字编号下架                 ***" << endl;
	cout << "                         ***************************************************************" << endl;

	cout << "请输入您想删除的图书的编号：";

	string bookid;
	cin >> bookid;
	string filename = "BookData.txt"; 
	vector<string> lines;

	// 读取文件
	ifstream inputFile(filename);

	string line;
	while (getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();

	// 遍历每一行
	for (int i = 0; i < lines.size(); i++) {
		if (lines[i] == bookid) { // 替换为你的目标行内容
			removeLinesAfterTarget(lines, i);
			break;
		}
	}
	// 将结果写回文件
	ofstream outputFile(filename);

	for (const auto& line : lines) {
		outputFile << line << std::endl;
	}

	outputFile.close();

	cout << "图书下架成功。" << endl;
	system("pause");
	system("cls");
	
}

void SystemManager::borrowBook()
{
	//输入注册信息
	string identity;
	cout << "请输入您的用户名称:" << endl;
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
			cout << "用户名不存在，请先注册!" << endl;
			system("pause");
			return;
		}
		else
		{
			break;
		}
	}
	cout << "请输入您的用户密码:" << endl;

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
				if (getline(file, line))   //读取用户名的下一行——密码
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
			cout << "密码错误!" << endl;
			system("pause");
			return;
		}
	}
	//比对成功，展示所有图书
	system("cls");
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***           您的账户登录成功，下面是所有库存图书          ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***             请记住您要借阅图书的四位数字编号            ***" << endl;
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***               按下任意键进入书籍借阅界面                ***" << endl;
	cout << "                         ***************************************************************" << endl;
	ifstream ifs;
	ifs.open("BookData.txt", ios::in);

	string bookdata;

	while (getline(ifs, bookdata)) {

		cout << bookdata << endl;
	}
	system("pause");
	//输入想要借阅的图书的编号
	system("cls");

	cout << "                         ***************************************************************" << endl;
	cout << "                         ***                    请输入四位数字编号:                  ***" << endl;
	cout << "                         ***************************************************************" << endl;

	string bookid;
	cin >> bookid;

	ifstream inputFile("BookData.txt");
	ofstream outputFile("Borrow.txt");
	vector<string> linesToMove;

	string targetLine = bookid; // 替换为你要查找的目标行

	if (inputFile.is_open() && outputFile.is_open()) {
		string line;
		bool targetFound = false;
		int count = 0;

		// 遍历BookData.txt文件的每一行
		while (getline(inputFile, line)) 
		{
			// 如果找到目标行
			if (line == targetLine) 
			{
				targetFound = true;
			}

			// 如果目标行已经找到，则将目标行和目标行后两行放入vector容器内
			if (targetFound) 
			{
				linesToMove.push_back(line);
				count++;

				if (count > 3)
				{
					break;
				}
			}
			// 收集到了目标行和目标行后两行
			for (const string& lineToWrite : linesToMove)
			{
				outputFile << lineToWrite << endl;
			}
			// 清空vector容器
			linesToMove.clear();
		}

		inputFile.close();
		outputFile.close();

		// 创建以targetLine字符串为名称的文件夹
		filesystem::create_directory(identity);

		// 将Borrow.txt文件移动到新创建的文件夹中
		filesystem::rename("Borrow.txt", identity + "/Borrow.txt");
		

		cout << "借阅成功！" << std::endl;
	}
	
		system("pause");
		return;
}

void SystemManager::searchUserinfo()
{
	cout << "                         ***************************************************************" << endl;
	cout << "                         ***             请输入您想查找的借书人用户名称:             ***" << endl;
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
	//输入注册信息
	string identity;
	cout << "请输入您的用户名称:" << endl;
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
			cout << "用户名不存在，请先注册!" << endl;
			system("pause");
			return;
		}
		else
		{
			break;
		}
	}
	cout << "请输入您的用户密码:" << endl;

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
				if (getline(file, line))   //读取用户名的下一行——密码
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
			cout << "密码错误!" << endl;
			system("pause");
			return;
		}
	}
	system("cls");
	cout << "只能一次性归还所有图书，您确定要现在归还吗?" << endl;
	cout << "确定请按 1 ，按 2 则返回主菜单。" << endl;

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
					cout << "归还成功：" <<endl;
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