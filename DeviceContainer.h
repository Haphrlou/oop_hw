#pragma once
#include "device.h"
#include <string>
#include <fstream>
#include <sstream>
#include "DeviceFactory.h"
using namespace std;
istringstream &operator>>(istringstream &in, Sensor &d);
ostringstream &operator<<(ostream &out, Sensor &d);
ostringstream &operator<<(ostream &out, Light &d);
istringstream &operator>>(istringstream &in, Light &d);
ostringstream &operator<<(ostream &out, AC &d);
istringstream &operator>>(istringstream &in, AC &d);
// Template class for managing devices
template <typename T>
class DeviceContainer
{
protected:
    T **devices;  // Array of device pointers
    int size;     // Number of devices currently stored
    int capacity; // Capacity of the devices array

    // Expands the array when capacity is full
    void expand();

public:
    DeviceContainer();  // Constructor
    ~DeviceContainer(); // Destructor

    void addDevice(T *Device);            // Adds a device to the container
    T *getDevice(int index);              // Gets a device by index
    int getSize() const;                  // Returns the current number of devices
    virtual void displayInfo() = 0; // Displays all devices 纯虚函数
    void LoadData(string);                // 加载数据
    void SaveData(string);                // 保存数据
    void OrderDevice();
    int GetSize();
};

class SensorContainer : public DeviceContainer<Sensor>
{
public:
    void displayInfo() override;

    friend ostringstream &operator<<(ostream &out, Sensor &d);
    friend istringstream &operator>>(istringstream &in, Sensor &d);
};
class LightContainer : public DeviceContainer<Light>
{
public:
    void displayInfo() override;
    friend ostringstream &operator<<(ostream &out, Light &d);
    friend istringstream &operator>>(istringstream &in, Light &d);
};
class ACContainer : public DeviceContainer<AC>
{
public:
    void displayInfo() override;
    friend ostringstream &operator<<(ostream &out, AC &d);
    friend istringstream &operator>>(istringstream &in, AC &d);
};

class FactoryNotFoundException : public std::exception
{
};
class InvalidParameterException : public std::exception
{
};
