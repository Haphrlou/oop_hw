#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
long long getTimestampSeconds();
// ��ʱ���ת��Ϊ����ʱ�䣨UTC+8��
string timestampToBeijingTime(long long timestamp);
void  Timechuo();
