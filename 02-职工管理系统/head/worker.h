/**
 *
 * 声明：职工抽象类，员工，老板，经理都要实现它；
 */
#pragma once
#include<iostream>
#include<string>


//职工抽象类
class Worker {
public:
    //职工编号
    int id_;
    //职工姓名
    std::string name_;
    //部门编号
    int departmentId_;

    //显示个人信息功能,纯虚函数
    virtual void showInfo() =0;

    //获取岗位,纯虚函数
    virtual std::string getDeptName() = 0;
};
