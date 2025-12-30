#include <iostream>

#include "../head/employee.h"


//构造函数的实现
Employee::Employee(int id ,std::string name ,int departmentId) {
        this->id_ = id ;
        this->name_ = name;
        this->departmentId_ =departmentId;

}


void Employee::showInfo() {
        std::cout << "职工编号：" << this->id_
        << "\t职工姓名：" << this->name_
        << "\t岗位：" <<this->getDeptName()
        << "\t岗位职责：" << "完成经理分配的任务~"
        <<std::endl;
}


std::string Employee::getDeptName() {
        return std::string("普通员工");
}



