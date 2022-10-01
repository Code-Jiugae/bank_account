#ifndef BANK_H
#define BANK_H

// #pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

const int NAME_LEN = 20;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
typedef struct
{
    int accID;      // 계좌번호
    int balance;    // 잔    액
    char cusName[NAME_LEN];   // 고객이름
} Account;


class bank
{
private:
    Account s_account;   // Account 저장을 위한 배열
    vector<Account> v_account;// [100] ;
    //fstream dataFile;
    int accNum = 0;        // 저장된 Account 수
public:
    int choice = 0;

    bank();
    ~bank();
    void CheckData();
    void ShowMenu(void);       // 메뉴출력
    void MakeAccount(void);    // 계좌개설을 위한 함수
    void DepositMoney(void);       // 입    금
    void WithdrawMoney(void);      // 출    금
    void ShowAllAccInfo(void);     // 잔액조회
    void SaveData(void);

};

#endif