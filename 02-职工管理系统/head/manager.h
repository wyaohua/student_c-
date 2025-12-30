/**
 *声明：经理类
 */
#pragma once
#include <iostream>
#include "worker.h"


//声明
class Manager: public Worker {
public:
    Manager(int id,std::string name,int did);

     void showInfo() override;

     std::string getDeptName() override;
};

