/**
 * 声明 boss老板类
 */
#pragma once

#include <iostream>

#include "worker.h"

class Boss: public Worker {
public:
    Boss(int id ,std::string name , int departmentId);
    void showInfo() override;
    std::string getDeptName() override;
};