#include <iostream>
#include <string>
#include "../head/manager.h"


Manager::Manager(int id, std::string name, int departmentId) {
    this->id_ =id;
    this->name_ = name;
    this->departmentId_ = departmentId;
}


void Manager::showInfo() {
    std::cout << "职工编号：" << this->id_
          << "\t职工姓名：" << this->name_
          << "\t岗位：" <<this->getDeptName()
          << "\t岗位职责：" << "接受老板的命令，统筹分配给普通员工~"
          <<std::endl;
}

std::string Manager::getDeptName() {
    return std::string("经理");
}
