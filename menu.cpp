#include<iostream>
using namespace std;
void menu() {
	cout << "=========主菜单=========" << endl;
	cout << "1 ---- 初始化并打印当前用户" << endl;
	cout << "2 ---- 从文件导入设备" << endl;
	cout << "3 ---- 从键盘添加设备" << endl;
	cout << "4 ---- 列表显示当前所有设备" << endl;
	cout << "5 ---- 按指定ID查找设备" << endl;
	cout << "6 ---- 删除指定ID的设备" << endl;
	cout << "7 ---- 保存所有设备信息至文件中" << endl;
	cout << "8 --- 智能场景模拟" << endl;
	cout << "Q ---- 退出" << endl;
	cout << "==========================" << endl;
	cout << "请选择：" << endl;
}