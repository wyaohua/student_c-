#include<iostream>
#include "../head/workerManager.h"
#include<cstdlib>

#include "boss.h"
#include "employee.h"
#include "manager.h"
#include "worker.h"


int main() {
    //设置编码
    system("chcp 65001");



    //创建管理系统的实例
    WorkerManager wm;
    int select = 0;
    while (true) {
        //菜单展示
        wm.showMenu();

        std::cout << "请输入您的选择: "<< std::endl;
        //等待用户输入
        std::cin >> select;

        switch (select) {
            case 1:
                wm.addWork();
                break;
            case 2:
                wm.showAllWork();
                break;
            case 3:
                wm.deleteWork();
                break;
            case 4:
                wm.updateWork();
                break;
            case 5:
                wm.findWork();
                break;
            case 6:
                wm.sortWork();
                break;
            case 7:
                wm.clearAllWork();
                break;
            case 0:
                wm.exitSystem();
                break;
            default:
                std::cout << "输入有误~"<<std::endl;
                system("pause");
                system("cls");
                break;
        }
        system("pause");
        system("cls");

    }
}
