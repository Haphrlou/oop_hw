#include "device.h"
device::device()
{
	params b;
	a = b;
}
device::device(params a1, bool b1) : a(a1), urgent(b1) {}
device::~device()
{
}
void device::DeviceSet_params(params a1)
{
	a = a1;
}
params device::DeviceGet_params()
{
	return a;
}
bool device::DeviceGet_urgent()
{
	return urgent;
}
void device::DeviceSet_urgent(bool b1)
{
	urgent = b1;
}
Sensor::Sensor() : device()
{
	a.SetParams_type(DeviceType::Sensor);
}
Sensor::Sensor(params a, bool b, double c, double d, double e) : device(a, b), tempuature(c), humidity(d), CO2_concentration(e)
{
}
Light::Light() : device()
{
	a.SetParams_type(DeviceType::Light);
}
Light::Light(params a, bool b, int c, bool d) : device(a, b), Brightness(c), states(d) {}
AC::AC() : device()
{
	a.SetParams_type(DeviceType::AC);
}
AC::AC(params a, bool b, int c, int d) : device(a, b), TempuatureSet(c), AirVol(d) {} // 构造函数

void Sensor::displayInfo()
{
	a.ParamsShow_DeviceID();
	a.ParamsShow_DegreeImportance();
	a.ParamsShow_name();
	a.ParamsShow_type();
	cout << "Sensor tempuature: " << tempuature << endl;
	cout << "Sensor humidity: " << humidity << endl;
	cout << "Sensor CO2_concentration: " << CO2_concentration << endl;
}
void Light::displayInfo()
{
	a.ParamsShow_DeviceID();
	a.ParamsShow_DegreeImportance();
	a.ParamsShow_name();
	a.ParamsShow_type();
	cout << "Light Brightness: " << Brightness << endl;
	cout << "Light states: " << states << endl;
}
void AC::displayInfo()
{
	a.ParamsShow_DeviceID();
	a.ParamsShow_DegreeImportance();
	a.ParamsShow_name();
	a.ParamsShow_type();
	cout << "AC TempuatureSet: " << TempuatureSet << endl;
	cout << "AC AirVol: " << AirVol << endl;
} // 显示函数
void Sensor::SensorSet_tempuature(double x)
{
	tempuature = x;
}
void Sensor::SensorSet_humidity(double x)
{
	humidity = x;
}
void Sensor::SensorSet_CO2_concentration(double x)
{
	CO2_concentration = x;
}
double Sensor::SensorGet_tempuature()
{
	return tempuature;
}
double Sensor::SensorGet_humidity()
{
	return humidity;
}
double Sensor::SensorGet_CO2_concentration()
{
	return CO2_concentration;
}
void Light::LightSet_Brightness(int x)
{
	Brightness = x;
}
void Light::LightSet_states(bool x)
{
	states = x;
}
int Light::LightGet_Brightness()
{
	return Brightness;
}
bool Light::LightGet_states()
{
	return states;
}
void AC::ACSet_TempuatureSet(int x)
{
	TempuatureSet = x;
}
void AC::ACSet_AirVol(int x)
{
	AirVol = x;
} // 设置函数
int AC::ACGet_TempuatureSet()
{
	return TempuatureSet;
}
int AC::ACGet_AirVol()
{
	return AirVol;
}


DeviceType stringToDeviceType(const string& str)
{
	if (str == "Sensor")
		return DeviceType::Sensor;
	if (str == "Light")
		return DeviceType::Light;
	if (str == "AC")
		return DeviceType::AC;
	// 根据你的枚举值调整
	return DeviceType::Sensor; // 默认值
}
string deviceTypeToString(DeviceType type)
{
	switch (type)
	{
	case DeviceType::Sensor:
		return "Sensor";
	case DeviceType::Light:
		return "Light";
	case DeviceType::AC:
		return "AC";
	default:
		return "Sensor";
	}
}//两个转换函数