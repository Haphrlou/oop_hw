#pragma once
#include<string>
using namespace std;
enum class DeviceType
{
	Sensor,
	Light,
	AC
};
class params
{
protected:
    int DeviceID;
    int DegreeImportance;
    string name;
    DeviceType t;
    int EnergyConsumption;

public:
    params()
    {
        DeviceID = 0;
        DegreeImportance = 0;
        name = " ";
        EnergyConsumption = 1;
    }
    void SetParams_type(DeviceType x)
    {
        t = x;
    }
    params(int DeviceID, int DegreeImportance, string name, DeviceType x) : DeviceID(DeviceID), DegreeImportance(DegreeImportance), name(name), t(x) {};
    void ParamsShow_DeviceID();
    void ParamsShow_DegreeImportance();
    void ParamsShow_name();
    void ParamsShow_type();
    void ParamsShow_EnergyConsumption();
    void ParamsSet_DeviceID(int);
    void ParamsSet_DegreeImportance(int);
    void ParamsSet_name(string);
    void ParamsSet_type(DeviceType);
    void ParamsSet_EnergyConsumption(int);
    int ParamsGet_DeviceID();
    int ParamsGet_DegreeImportance();
    string ParamsGet_name();
    DeviceType ParamsGet_type();
    int ParamsGet_EnergyConsumption();
};