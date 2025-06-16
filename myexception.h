#pragma once
#pragma once
#include <exception>
#include <string>

// �����Զ����쳣��
class DeviceException : public std::exception {
protected:
    std::string message;

public:
    explicit DeviceException(const std::string& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }

    virtual ~DeviceException() noexcept = default;
};

// ����δ�ҵ��쳣
class FactoryNotFoundException : public DeviceException {
public:
    explicit FactoryNotFoundException(const std::string& factoryType)
        : DeviceException("Factory not found: " + factoryType) {}

    explicit FactoryNotFoundException(const std::string& factoryType, const std::string& details)
        : DeviceException("Factory not found: " + factoryType + ". Details: " + details) {}
};

// �豸������Ч�쳣
class InvalidParameterException : public DeviceException {
public:
    explicit InvalidParameterException(const std::string& paramName)
        : DeviceException("Invalid parameter: " + paramName) {}

    explicit InvalidParameterException(const std::string& paramName, const std::string& expectedValue)
        : DeviceException("Invalid parameter: " + paramName + ". Expected: " + expectedValue) {}

    explicit InvalidParameterException(const std::string& paramName, const std::string& actualValue, const std::string& expectedValue)
        : DeviceException("Invalid parameter: " + paramName + ". Got: " + actualValue + ", Expected: " + expectedValue) {}
};

// ʹ��ʾ��
/*
// �ڹ�������ʹ��
Device* DeviceFactory::createDevice(const std::string& deviceType) {
    if (deviceType == "smartphone") {
        return new Smartphone();
    } else if (deviceType == "tablet") {
        return new Tablet();
    } else {
        throw FactoryNotFoundException(deviceType);
    }
}

// ���豸������֤��ʹ��
void Device::setScreenSize(double size) {
    if (size <= 0) {
        throw InvalidParameterException("screenSize", std::to_string(size), "positive number");
    }
    if (size > 50.0) {
        throw InvalidParameterException("screenSize", "Screen size too large (max: 50 inches)");
    }
    screenSize = size;
}

// �쳣����ʾ��
try {
    DeviceFactory* factory = getFactory("unknown_type");
    Device* device = factory->createDevice("invalid_device");
    device->setScreenSize(-5.0);
} catch (const FactoryNotFoundException& e) {
    std::cerr << "Factory error: " << e.what() << std::endl;
} catch (const InvalidParameterException& e) {
    std::cerr << "Parameter error: " << e.what() << std::endl;
} catch (const DeviceException& e) {
    std::cerr << "Device error: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "General error: " << e.what() << std::endl;
}
*/