#pragma once
#include "DeviceContainer.h"
void menu();
class User
{
protected:
    SensorContainer *S;
    LightContainer *L;
    ACContainer *AC;

public:
    virtual void setDegreeImportance(int degreeImportance) = 0;
};
class Admin : public User
{
protected:
public:
    void setDegreeImportance(int degreeImportance);
};
class Visitor : public User
{
protected:
public:
    void setDegreeImportance(int degreeImportance);
};
