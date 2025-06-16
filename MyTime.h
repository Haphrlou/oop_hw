#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;
long long getTimestampSeconds();
// 将时间戳转换为北京时间（UTC+8）
string timestampToBeijingTime(long long timestamp);
void  Timechuo();
