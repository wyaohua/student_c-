#include <iostream>

#include "../head/boss.h"


Boss::Boss(int id, std::string name, int departmentId) {
    this->id_ = id;
    this->name_ = name;
    this->departmentId_ = departmentId;
}


std::string Boss::getDeptName() {
    return std::string("老板");
}


void Boss::showInfo() {
    std::cout << "职工编号：" << this->id_
     << "\t职工姓名：" << this->name_
     << "\t岗位：" <<this->getDeptName()
     << "\t岗位职责：" << "给经理安排任务~"
     <<std::endl;
}
