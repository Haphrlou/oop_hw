#include "DeviceContainer.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include"device.h"

// Constructor initializes the devices array and sets the size and capacity
template <typename T>
DeviceContainer<T>::DeviceContainer() : size(0), capacity(2)
{
    devices = new T *[capacity];
}

// Destructor to delete all device objects and the array
template <typename T>
DeviceContainer<T>::~DeviceContainer()
{
    for (int i = 0; i < size; ++i)
    {
        delete devices[i];
    }
    delete[] devices;
}

// Expands the device array by doubling the capacity
template <typename T>
void DeviceContainer<T>::expand()
{
    capacity *= 2;
    T **newDevices = new T *[capacity];

    // Copy the old devices into the new array
    for (int i = 0; i < size; ++i)
    {
        newDevices[i] = devices[i];
    }

    delete[] devices;
    devices = newDevices;
}

// Adds a new device to the container
template <typename T>
void DeviceContainer<T>::addDevice(T *Device)
{
    if (size == capacity)
    {
        expand(); // If the array is full, expand its size
    }
    devices[size++] = device;
}

// Gets a device by index
template <typename T>
T *DeviceContainer<T>::getDevice(int index)
{
    if (index < 0 || index >= size)
    {
        return nullptr; // Return nullptr if the index is out of bounds
    }
    return devices[index];
}

// Returns the current number of devices in the container
template <typename T>
int DeviceContainer<T>::getSize() const
{
    return size;
}

// Displays the information of all devices in the container
template <typename T>
void DeviceContainer<T>::displayAllDevices()
{
    for (int i = 0; i < size; ++i)
    {
        devices[i]->displayInfo(); // Call the displayInfo method of each device
    }
}
template <typename T>
void DeviceContainer<T>::OrderDevice()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (devices[i]->getEnergyConsumption() > devices[j]->getEnergyConsumption())
            {
                T *temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }
}
template <typename T>
void DeviceContainer<T>::LoadData(string m)
{
    ifstream file(m);
    if (file.is_open())
    {
        string line;
        int index = 0; // 如果文件中没有单独的index，使用行号作为index

        while (getline(file, line))
        {
            // 跳过空行
            if (line.empty())
                continue;

            // 检查数组边界
            if (index >= size)
            {
                expand();
            }

            // 检查是否已存在传感器，避免内存泄漏
            if (devices[index] != nullptr)
            {
                delete devices[index];
            }

            devices[index] = new T();

            // 使用istringstream来解析整行数据
            istringstream iss(line);
            if (!(iss >> *(devices[index])))
            {
                // 解析失败时的错误处理
                delete devices[index];
                devices[index] = nullptr;
                cerr << "Error parsing line " << index << ": " << line << endl;
            }

            index++;
        }
        file.close();
    }
    else
    {
        // 文件打开失败的错误处理
        cerr << "Error: Could not open file " << m << endl;
    }
} // 加载数据
template <typename T>
void DeviceContainer<T>::SaveData(string filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            if (devices[i] != nullptr)
            {
                file << *(devices[i]) << endl;
            }
        }
        file.close();
    }
    else
    {
        cerr << "Error: Could not open file " << filename << " for writing" << endl;
    }
}
template<typename T>
int DeviceContainer<T>::GetSize() {
    return size;
}
istringstream &operator>>(istringstream &in, Sensor &d)
{
    string line;
    // 读取整行数据
    if (getline(in, line))
    {
        istringstream lineStream(line);
        string item;
        string data[9]; // 总共9个字段：params(5个) + urgent + temperature + humidity + co2_concentration
        int index = 0;

        // 按逗号分割数据
        while (getline(lineStream, item, ',') && index < 9)
        {
            data[index] = item;
            index++;
        }

        // 解析数据
        try
        {
            // 创建并设置params对象 (前5个字段)
            params p;
            p.ParamsSet_DeviceID(stoi(data[0]));           // ID
            p.ParamsSet_DegreeImportance(stoi(data[1]));   // DegreeImportance
            p.ParamsSet_name(data[2]);                     // name
            p.ParamsSet_type(stringToDeviceType(data[3])); // DeviceType
            p.ParamsSet_EnergyConsumption(stoi(data[4]));  // EnergyConsumption

            // 设置Sensor的参数
            d.DeviceSet_params(p);                                   // params对象
            d.DeviceSet_urgent(data[5] == "true" || data[5] == "1"); // urgent (bool)
            d.SensorSet_tempuature(stod(data[6]));                   // temperature (double)
            d.SensorSet_humidity(stod(data[7]));                     // humidity (double)
            d.SensorSet_CO2_concentration(stod(data[8]));            // co2_concentration (double)
        }
        catch (const exception &e)
        {
            // 数据转换错误处理
            cerr << "Error converting data: " << e.what() << endl;
            in.setstate(ios::failbit);
        }
    }

    return in;
}
// Light的operator>>重载
istringstream &operator>>(istringstream &in, Light &d)
{
    string line;
    if (getline(in, line))
    {
        istringstream lineStream(line);
        string item;
        string data[7]; // Light有7个字段
        int index = 0;

        while (getline(lineStream, item, ',') && index < 7)
        {
            data[index] = item;
            index++;
        }

        try
        {
            params p;
            p.ParamsSet_DeviceID(stoi(data[0]));
            p.ParamsSet_DegreeImportance(stoi(data[1]));
            p.ParamsSet_name(data[2]);
            p.ParamsSet_type(stringToDeviceType(data[3]));
            p.ParamsSet_EnergyConsumption(stoi(data[4]));

            d.DeviceSet_params(p);
            d.DeviceSet_urgent(data[5] == "true" || data[5] == "1");
            d.LightSet_Brightness(stoi(data[6]));
            d.LightSet_states(data[7] == "true" || data[7] == "1");
        }
        catch (const exception &e)
        {
            cerr << "Error converting light data: " << e.what() << endl;
            in.setstate(ios::failbit);
        }
    }
    return in;
}
istringstream &operator>>(istringstream &in, AC &d)
{
    string line;
    if (getline(in, line))
    {
        istringstream lineStream(line);
        string item;
        string data[7]; // AC有7个字段：params(5个) + urgent + TempuratureSet + AirVol
        int index = 0;

        while (getline(lineStream, item, ',') && index < 7)
        {
            data[index] = item;
            index++;
        }

        try
        {
            params p;
            p.ParamsSet_DeviceID(stoi(data[0]));
            p.ParamsSet_DegreeImportance(stoi(data[1]));
            p.ParamsSet_name(data[2]);
            p.ParamsSet_type(stringToDeviceType(data[3]));
            p.ParamsSet_EnergyConsumption(stoi(data[4]));

            d.DeviceSet_params(p);
            d.DeviceSet_urgent(data[5] == "true" || data[5] == "1");
            d.ACSet_TempuatureSet(stoi(data[6]));
            d.ACSet_AirVol(stoi(data[7]));
        }
        catch (const exception &e)
        {
            cerr << "Error converting AC data: " << e.what() << endl;
            in.setstate(ios::failbit);
        }
    }
    return in;
} // 重载三个设备类的输入
ostringstream &operator<<(ostringstream &out, Sensor &d)
{
    params p = d.DeviceGet_params();
    out << p.ParamsGet_DeviceID() << ","
        << p.ParamsGet_DegreeImportance() << ","
        << p.ParamsGet_name() << ",";
    out << deviceTypeToString(p.ParamsGet_type()) << ","
        << p.ParamsGet_EnergyConsumption() << ","
        << d.DeviceGet_urgent() << ","
        << d.SensorGet_tempuature() << ","
        << d.SensorGet_humidity() << ","
        << d.SensorGet_CO2_concentration() << endl;
    return out;
}
ostringstream &operator<<(ostringstream &out, Light &d)
{
    params p = d.DeviceGet_params();
    out << p.ParamsGet_DeviceID() << ","
        << p.ParamsGet_DegreeImportance() << ","
        << p.ParamsGet_name() << ",";
    out << deviceTypeToString(p.ParamsGet_type()) << ","
        << p.ParamsGet_EnergyConsumption() << ","
        << d.DeviceGet_urgent() << ","
        << d.LightGet_Brightness() << endl;
    return out;
}
ostringstream &operator<<(ostringstream &out, AC &d)
{
    params p = d.DeviceGet_params();
    out << p.ParamsGet_DeviceID() << ","
        << p.ParamsGet_DegreeImportance() << ","
        << p.ParamsGet_name() << ",";
    out << deviceTypeToString(p.ParamsGet_type()) << ","
        << p.ParamsGet_EnergyConsumption() << ","
        << d.DeviceGet_urgent() << ","
        << d.ACGet_TempuatureSet() << ","
        << d.ACGet_AirVol() << endl;
    return out;
} // 重载3个设备类的输出
