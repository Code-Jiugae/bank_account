// 1. 첨부 화일은 c언어로 작성된 program이다. 프로그램을 compile하여
//    실행하여 동작 시나리오를 확인 해 본 후
// 2. c++ 기법(class, 구조체, 상속등)을 최대한 동원하여 작성 하되,
// 3. 현재의 프로그램은 array 구조로 별도의 db나 화일로 처리를 하지 않아서
//    프로그램의 실행을 종료 하면 작업한 내용이 다 삭제되어 기존의 작업내용이
//    유지 되지 않는다.
// 4. 이러한 문제점을 해결 하기 위해서 계좌계설, 입금, 출금 처리시
//    c++의 vertor 처리로 프로그램이 실행 된뒤에도 작업 내용이 화일 형태로 유지되어
//    다음 실행시 기존에 작업된 내용을 볼 수 있도록 프로그램을 작성 하시오.

#include <iostream>
#include <cstring>
#include <fstream>
#include "bank.h"

using namespace std;

int main(void)
{
	bank b;
	b.CheckData();
	while (1)
	{
		b.ShowMenu();
		cout << "선택: ";
		cin >> b.choice;
		cout << endl;

		switch (b.choice)
		{
		case MAKE:
			b.MakeAccount();
			break;
		case DEPOSIT:
			b.DepositMoney();
			break;
		case WITHDRAW:
			b.WithdrawMoney();
			break;
		case INQUIRE:
			b.ShowAllAccInfo();
			break;
		case EXIT:
			b.~bank();
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
		b.choice = 0;
		b.SaveData();

	}
	return 0;
}
