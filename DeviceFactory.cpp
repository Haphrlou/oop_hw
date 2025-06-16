#include "DeviceFactory.h"
using namespace std;
DeviceFactory::DeviceFactory()
{
}
DeviceFactory::~DeviceFactory()
{
}
device *SensorFactory::createDevice()
{
	return (new Sensor());
}
device *SensorFactory::createDeviceWithParams(params data, string type)
{
	return (new Sensor(data, true, type[0], type[1], type[2]));
}
device *LightFactory::createDevice()
{
	return (new Light());
}
device *LightFactory::createDeviceWithParams(params data, string type)
{
	return (new Light(data, true, type[0], type[1]));
}
device *ACFactory::createDevice()
{
	return (new AC());
}
device *ACFactory::createDeviceWithParams(params data, string type)
{
	return (new AC(data, true, type[0], type[1]));
}
