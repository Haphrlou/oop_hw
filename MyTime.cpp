#include"MyTime.h"
string timestampToBeijingTime(long long timestamp) {
    // ����UTC+8��ʱ�������������UTC��8Сʱ��
    long long beijingTimestamp = timestamp + 8 * 3600;  // 8Сʱ = 8*3600��

    // ת��Ϊtm�ṹ��
    time_t t = beijingTimestamp;
    tm* tm = gmtime(&t);  // ʹ��gmtime����localtime

    ostringstream oss;
    oss << put_time(tm, "[%Y-%m-%d %H:%M:%S]") ;
    return oss.str();
}
void  Timechuo() {
    // ��ȡ��ǰʱ���
    long long currentTimestamp = getTimestampSeconds();

    // ���ʱ����ͱ���ʱ��
   // cout << "��ǰʱ���: " << currentTimestamp << std::endl;
    cout<< timestampToBeijingTime(currentTimestamp) << std::endl;
}

long long getTimestampSeconds() {
    return static_cast<long long>(std::time(nullptr));
}