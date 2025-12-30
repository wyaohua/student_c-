
/**
 *
 * 声明：职工管理系统类
 */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"




#define FILE_NAME "workPersonFile.txt"

class WorkerManager {
public:
    //记录职工人数
    int workNum_;

    //职工数组指针  (指向指针的指针)
    Worker **workerArray_;

    //判断磁盘文件是否为空
    bool fileIsEmpty_;


    //构造函数声明
    WorkerManager();

    //析构函数声明
    ~WorkerManager();


    //展示菜单共生
    void showMenu();

    //退出系统功能
    void exitSystem();

    //添加联系人功能

    void addWork();


    //持久化磁盘
    void save();

    //统计磁盘文件，初始化员工
    void initWork();

    //统计磁盘文件中 人数
    int getWorkNum();

    //显示职工信息
    void showAllWork();

    //清空文件
    void clearAllWork();




    //判断职工是否存在 ,返回索引
    int isExist(int id);
    //删除职工
    void deleteWork();


    //修改职工
    void updateWork();

    //查找职工
    void findWork();

    //排序功能
    void sortWork();







};
