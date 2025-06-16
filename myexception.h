#pragma once
#pragma once
#include <exception>
#include <string>

// 基础自定义异常类
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

// 工厂未找到异常
class FactoryNotFoundException : public DeviceException {
public:
    explicit FactoryNotFoundException(const std::string& factoryType)
        : DeviceException("Factory not found: " + factoryType) {}

    explicit FactoryNotFoundException(const std::string& factoryType, const std::string& details)
        : DeviceException("Factory not found: " + factoryType + ". Details: " + details) {}
};

// 设备参数无效异常
class InvalidParameterException : public DeviceException {
public:
    explicit InvalidParameterException(const std::string& paramName)
        : DeviceException("Invalid parameter: " + paramName) {}

    explicit InvalidParameterException(const std::string& paramName, const std::string& expectedValue)
        : DeviceException("Invalid parameter: " + paramName + ". Expected: " + expectedValue) {}

    explicit InvalidParameterException(const std::string& paramName, const std::string& actualValue, const std::string& expectedValue)
        : DeviceException("Invalid parameter: " + paramName + ". Got: " + actualValue + ", Expected: " + expectedValue) {}
};

// 使用示例
/*
// 在工厂类中使用
Device* DeviceFactory::createDevice(const std::string& deviceType) {
    if (deviceType == "smartphone") {
        return new Smartphone();
    } else if (deviceType == "tablet") {
        return new Tablet();
    } else {
        throw FactoryNotFoundException(deviceType);
    }
}

// 在设备参数验证中使用
void Device::setScreenSize(double size) {
    if (size <= 0) {
        throw InvalidParameterException("screenSize", std::to_string(size), "positive number");
    }
    if (size > 50.0) {
        throw InvalidParameterException("screenSize", "Screen size too large (max: 50 inches)");
    }
    screenSize = size;
}

// 异常处理示例
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