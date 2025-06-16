#pragma once
#include <iostream>
#include <string>
#include "DeviceType.h"
using namespace std;

// DeviceType转换辅助函数
DeviceType stringToDeviceType(const string& str);

string deviceTypeToString(DeviceType type);

class device
{
protected:
	params a;
	bool urgent;

public:
	device();
	device(params, bool);
	~device();
	virtual void displayInfo() = 0;
	void DeviceSet_params(params);
	void DeviceSet_urgent(bool);
	params DeviceGet_params();
	bool DeviceGet_urgent();
};
class Sensor : public device // 环境传感器
{
protected:
	double tempuature;
	double humidity;
	double CO2_concentration;

public:
	Sensor();
	Sensor(params, bool, double, double, double);
	virtual void displayInfo() override;
	void SensorSet_tempuature(double);
	void SensorSet_humidity(double);
	void SensorSet_CO2_concentration(double);
	double SensorGet_tempuature();
	double SensorGet_humidity();
	double SensorGet_CO2_concentration();
};
class Light : public device // 智能灯具
{
protected:
	int Brightness;
	bool states;

public:
	Light();
	Light(params, bool, int, bool);
	virtual void displayInfo() override;
	void LightSet_Brightness(int);
	void LightSet_states(bool);
	int LightGet_Brightness();
	bool LightGet_states();
};
class AC : public device // 空调
{
protected:
	int TempuatureSet;
	int AirVol;

public:
public:
	AC();
	AC(params, bool, int, int);
	virtual void displayInfo() override;
	void ACSet_TempuatureSet(int);
	void ACSet_AirVol(int);
	int ACGet_TempuatureSet();
	int ACGet_AirVol();
};
