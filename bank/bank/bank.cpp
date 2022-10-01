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
		cerr << "������ ã�� �� ����" << endl;
		cout << "���� ����" << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void bank::MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��  ��: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> balance;
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
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�Աݾ�: ";	cin >> money;

	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		if (v_account[i].accID == id)
		{
			v_account[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
		i++;
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void bank::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "��ݾ�: ";	cin >> money;

	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		if (v_account[i].accID == id)
		{
			if (v_account[i].balance < money)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			v_account[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
		i++;
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void bank::ShowAllAccInfo(void)
{
	int i = 0;
	for (auto iter = v_account.begin(); iter < v_account.end(); iter++)
	{
		cout << "����ID: " << v_account[i].accID << endl;
		cout << "��  ��: " << v_account[i].cusName << endl;
		cout << "��  ��: " << v_account[i].balance << endl << endl;
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