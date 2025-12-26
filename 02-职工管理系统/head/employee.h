//声明：：普通职工类，继承实现职抽象类
#pragma once
#include <iostream>
#include "worker.h"

//继承Employee,也算是 实现了Worker
class Employee : public Worker {
public:
    //构造函数
    Employee(int id, std::string name ,int dId);

    //显示个人信息功能,声明
    virtual void showInfo();

    //获取岗位,
    virtual std::string getDeptName() ;
};