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
    int accID;      // ���¹�ȣ
    int balance;    // ��    ��
    char cusName[NAME_LEN];   // ���̸�
} Account;


class bank
{
private:
    Account s_account;   // Account ������ ���� �迭
    vector<Account> v_account;// [100] ;
    //fstream dataFile;
    int accNum = 0;        // ����� Account ��
public:
    int choice = 0;

    bank();
    ~bank();
    void CheckData();
    void ShowMenu(void);       // �޴����
    void MakeAccount(void);    // ���°����� ���� �Լ�
    void DepositMoney(void);       // ��    ��
    void WithdrawMoney(void);      // ��    ��
    void ShowAllAccInfo(void);     // �ܾ���ȸ
    void SaveData(void);

};

#endif