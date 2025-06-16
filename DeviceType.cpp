#include"DeviceType.h"
#include<string>
#include<iostream>
using namespace std;

void params::ParamsShow_DeviceID()
{
	cout << "DeviceID: " << DeviceID << endl;
}
void params::ParamsShow_DegreeImportance()
{
	cout << "DegreeImportance: " << DegreeImportance << endl;
}
void params::ParamsShow_name()
{
	cout << "name: " << name << endl;
}
void params::ParamsShow_type()
{
	switch (t)
	{
	case DeviceType::Sensor:
		cout << "Sensor" << endl;
		break;
	case DeviceType::Light:
		cout << "Light" << endl;
		break;
	case DeviceType::AC:
		cout << "AC" << endl;
		break;
	default:
		break;
	}
}
void params::ParamsShow_EnergyConsumption()
{
	cout << "EnergyConsumption: " << EnergyConsumption << endl;
}
void params::ParamsSet_DeviceID(int x)
{
	DeviceID = x;
}
void params::ParamsSet_DegreeImportance(int x)
{
	DegreeImportance = x;
}
void params::ParamsSet_name(string x)
{
	name = x;
}
void params::ParamsSet_type(DeviceType x)
{
	t = x;
}
void params::ParamsSet_EnergyConsumption(int x)
{
	EnergyConsumption = x;
}

int params::ParamsGet_DeviceID() {
	return DeviceID;
}
int params::ParamsGet_DegreeImportance() {
	return DegreeImportance;
}
string params::ParamsGet_name() {
	return name;
}
DeviceType params::ParamsGet_type() {
	return t;

}
int params::ParamsGet_EnergyConsumption() {
	return EnergyConsumption;
}