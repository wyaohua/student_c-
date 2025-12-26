#include<iostream>
#include "../head/workerManager.h"
#include<cstdlib>






int main() {
    //设置编码
    system("chcp 65001");
    int select = 0;
    //创建管理系统的实例
    WorkerManager wm;

    while (true) {
        //菜单展示
        wm.Show_Menu();

        std::cout << "请输入您的选择: "<< std::endl;
        //等待用户输入
        std::cin >> select;

        switch (select) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                wm.Exit_System();
                break;
            default:
                system("cls");
                break;
        }
    }
}
