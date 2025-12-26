//声明：：职工抽象类
#pragma once
#include<iostream>
#include<string>


//职工抽象类
class Worker {
public:
    //职工编号
    int w_Id;
    //职工姓名
    std::string w_Name;
    //部门编号
    int w_d_Id;

    //显示个人信息功能,纯虚函数
    virtual void showInfo() =0;

    //获取岗位,纯虚函数
    virtual std::string getDeptName() = 0;
};
