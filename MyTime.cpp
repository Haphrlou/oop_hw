#include"MyTime.h"
string timestampToBeijingTime(long long timestamp) {
    // 计算UTC+8的时间戳（东八区比UTC快8小时）
    long long beijingTimestamp = timestamp + 8 * 3600;  // 8小时 = 8*3600秒

    // 转换为tm结构体
    time_t t = beijingTimestamp;
    tm* tm = gmtime(&t);  // 使用gmtime而非localtime

    ostringstream oss;
    oss << put_time(tm, "[%Y-%m-%d %H:%M:%S]") ;
    return oss.str();
}
void  Timechuo() {
    // 获取当前时间戳
    long long currentTimestamp = getTimestampSeconds();

    // 输出时间戳和北京时间
   // cout << "当前时间戳: " << currentTimestamp << std::endl;
    cout<< timestampToBeijingTime(currentTimestamp) << std::endl;
}

long long getTimestampSeconds() {
    return static_cast<long long>(std::time(nullptr));
}