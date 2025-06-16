#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include"device.h"
#include"DeviceContainer.h"
#include"DeviceFactory.h"
#include"User.h"
#include"MyTime.h"
#include"funs.h"
using namespace std;
int main() {
	menu();
	Timechuo();
	int mode = 0;
	cout << "请选择要执行的选项：" << endl;
	cin >> mode;
	switch (mode) {
	case 1:
		init();
		PrintCurrentUser();
		break;
	case 2:
		 InputFromFile();
		break;
	case 3:
		InputFromKeyboard();
		break;
	case 4:
		ListAllDevice();
		break;
	case 5:
		FindDeviceByID();
		break;
	case 6:
		DeleteDeviceByID();
		break;
	case 7:
		SaveAllDeviceToFile();
		break;
	case 8:
		SceneSimulation();
		break;
	case 9:
		return 0;
	}
}  


// 获取当前时间戳（秒级）
