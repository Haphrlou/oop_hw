#pragma once
#include <iostream>
#include <string>
#include"device.h"
#include"DeviceType.h"
using namespace std;
class DeviceFactory
{
protected:
public:
    DeviceFactory();
    ~DeviceFactory();
    virtual device* createDevice() = 0;
    virtual device* createDeviceWithParams(params, string) = 0;
};

class SensorFactory : public DeviceFactory
{
protected:
public:
    device* createDevice() override;
    device* createDeviceWithParams(params, string) override;
};
class LightFactory : public DeviceFactory
{
protected:
public:
    device* createDevice() override;
    device* createDeviceWithParams(params, string) override;
};
class ACFactory : public DeviceFactory
{
protected:
public:
    device* createDevice() override;
    device* createDeviceWithParams(params, string) override;
};
