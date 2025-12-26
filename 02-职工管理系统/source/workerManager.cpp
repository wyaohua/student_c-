#include "../head/workerManager.h"



//作用域：：构造函数的实现
WorkerManager::WorkerManager() {
    std::cout << "WorkerManager 构造函数执行了~" << std::endl;
}


WorkerManager::~WorkerManager() {
    std::cout << "WorkerManager 析构函数执行了~" << std::endl;
}

//展示菜单的功能
void WorkerManager::Show_Menu() {
    std::cout << "*************************" <<std::endl;
    std::cout << "*****欢迎使用职工管理系统*****" <<std::endl;
    std::cout << "*****0. 退出管理系统*****" <<std::endl;
    std::cout << "*****1. 添加职工信息*****" <<std::endl;
    std::cout << "*****2. 显示职工信息*****" <<std::endl;
    std::cout << "*****3. 删除职工信息*****" <<std::endl;
    std::cout << "*****4. 修改职工信息*****" <<std::endl;
    std::cout << "*****5. 查找职工信息*****" <<std::endl;
    std::cout << "*****6. 按照编号排序*****" <<std::endl;
    std::cout << "*****7. 清空所有职工*****" <<std::endl;
    std::cout << "*************************" <<std::endl;
}


//退出功能
void WorkerManager::Exit_System() {
    std::cout << "欢迎下次使用~" <<std::endl;
    system("pause");
    exit(0);

}
