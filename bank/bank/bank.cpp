#include "bank.h"

bank::bank()
{

}

bank::~bank()
{

}

void bank::CheckData()
{
	ifstream fin("saveData.txt");
	char line[100];
	int i = 0;
	if (fin.fail())
	{
		cerr << "파일을 찾을 수 없음" << endl;
		cout << "파일 생성" << endl;
		ofstream fout("saveData.txt");
		fout.close();
	}
	while (fin.getline(line, sizeof(line)))
	{
		//cout << i << endl;
		//cout << line << endl;
		switch (i % 3)
		{
		case 0:
			s_account.accID = atoi(line);
			break;
		case 1:
			s_account.balance = atoi(line);
			break;
		case 2:
			strcpy(s_account.cusName, line);
			v_account.push_back(s_account);
			break;

		default:
			break;
		}
		i++;
	}
		

	fin.close();
}


void bank::ShowMenu(void)
{
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void bank::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이  름: ";	cin >> name;
	cout << "입금액: ";	cin >> balance;
	cout << endl;

	s_account.accID = id;
	s_account.balance = balance;
	strcpy(s_account.cusName, name);
	v_account.push_back(s_account);

	accNum++;
}

void bank::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "입금액: ";	cin >> money;

	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		if (v_account[i].accID == id)
		{
			v_account[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
		i++;
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void bank::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출    금]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "출금액: ";	cin >> money;

	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		if (v_account[i].accID == id)
		{
			if (v_account[i].balance < money)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			v_account[i].balance -= money;
			cout << "출금완료" << endl << endl;
			return;
		}
		i++;
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void bank::ShowAllAccInfo(void)
{
	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		cout << "계좌ID: " << v_account[i].accID << endl;
		cout << "이  름: " << v_account[i].cusName << endl;
		cout << "잔  액: " << v_account[i].balance << endl << endl;
		i++;
	}
}

void bank::SaveData()
{
	ofstream fout("saveData.txt");
	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		fout << v_account[i].accID << endl;
		fout << v_account[i].balance << endl;
		fout << v_account[i].cusName << endl;
		i++;
	}
	

	fout.close();
}