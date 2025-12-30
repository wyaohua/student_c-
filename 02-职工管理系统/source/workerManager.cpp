#include "../head/workerManager.h"

#include <tuple>


/**
 *  构造函数的实现
 */
WorkerManager::WorkerManager() {
    std::cout << "WorkerManager 构造函数执行了~ 开始初始化属性" << std::endl;

    //情况1：文件不存在
    std::ifstream ifs;
    ifs.open(FILE_NAME, std::ios::in);
    if (!ifs.is_open()) {
        std::cout << "文件不存在；\n";
        //初始化属性
        this->workNum_ = 0;
        this->workerArray_ = nullptr;
        this->fileIsEmpty_ = true;
        return;
    }
    //情况2：文件存在 但是没有数据 [读一个字符，是不是文件的结束符，是的话就代表文件没有任何内容]
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        std::cout << "文件存在，内容为空；\n";
        //初始化属性
        this->workNum_ = 0;
        this->workerArray_ = nullptr;
        this->fileIsEmpty_ = true;
        return;
    }

    //情况3：文件存在 ，数据也有；
    this->fileIsEmpty_ = false;
    int num = this->getWorkNum();
    this->workNum_ = num;
    this->workerArray_ = new Worker *[this->workNum_];
    this->initWork();
    std::cout << "职工人数 初始化：" << num << std::endl;
}


WorkerManager::~WorkerManager() {
    std::cout << "WorkerManager 析构函数执行了~ 释放堆区" << std::endl;
    if (this ->workerArray_ !=nullptr) {
        for (int i = 0 ; i <this->workNum_ ; i++) {
            delete this->workerArray_[i];
            this ->workerArray_[i] = nullptr;
        }
        this->workerArray_ = nullptr;
    }
}

/**
 *  展示菜单的功能
 */
void WorkerManager::showMenu() {
    std::cout << "*************************" << std::endl;
    std::cout << "*****欢迎使用职工管理系统*****" << std::endl;
    std::cout << "*****0. 退出管理系统*****" << std::endl;
    std::cout << "*****1. 添加职工信息*****" << std::endl;
    std::cout << "*****2. 显示职工信息*****" << std::endl;
    std::cout << "*****3. 删除职工信息*****" << std::endl;
    std::cout << "*****4. 修改职工信息*****" << std::endl;
    std::cout << "*****5. 查找职工信息*****" << std::endl;
    std::cout << "*****6. 按照编号排序*****" << std::endl;
    std::cout << "*****7. 清空所有职工*****" << std::endl;
    std::cout << "*************************" << std::endl;
}


/**
 *  退出功能
 */
void WorkerManager::exitSystem() {
    std::cout << "欢迎下次使用~" << std::endl;
    system("pause");
    exit(0);
}

/**
 *  添加职工的功能
 */
void WorkerManager::addWork() {
    std::cout << "请输入添加职工的数量";
    int addNum = 0;

    std::cin >> addNum;
    if (addNum <= 0) {
        std::cout << "输入的数据有误";

        return;
    }

    //开始添加

    //1.计算新的数组大小
    int newSize = this->workNum_ + addNum;

    //2.创建新的数组
    Worker **newspace = new Worker *[newSize];

    //将原来的数据拷贝到新的空间中
    if (this->workerArray_ != nullptr) {
        for (int i = 0; i < this->workNum_; i++) {
            newspace[i] = this->workerArray_[i];
        }
    }

    for (int i = 0; i < addNum; i++) {
        int id;
        std::string name;
        int departmentId;

        std::cout << "请输入第" << i + 1 << "个新员工的编号：" << std::endl;
        std::cin >> id;
        std::cout << "请输入第" << i + 1 << "个新员工的姓名：" << std::endl;
        std::cin >> name;
        std::cout << "请选择该职工的岗位：" << std::endl;
        std::cout << "1 : 老板" << std::endl;
        std::cout << "2 : 经理" << std::endl;
        std::cout << "3 : 普通员工" << std::endl;
        std::cin >> departmentId;


        Worker *worker = nullptr;
        switch (departmentId) {
            case 1:
                worker = new Boss(id, name, departmentId);
                break;
            case 2:
                worker = new Manager(id, name, departmentId);
                break;
            case 3:
                worker = new Employee(id, name, departmentId);
                break;
            default:
                std::cout << "输入有误,退出添加" << std::endl;
                system("pause");
                system("cls");
                return;
                break;
        }

        newspace[this->workNum_ + i] = worker;
    }
    //释放原有的空间
    delete [] this->workerArray_;
    //更新指向
    this->workerArray_ = newspace;
    //重置数组大小
    this->workNum_ = newSize;

    //成功的添加后， 持久化到磁盘
    this->save();

    //将文件是否为空的标志 修改；
    this->fileIsEmpty_ = false;

    std::cout << "添加完毕! 成功添加了" << addNum << "名员工" << std::endl;
}

/**
 * 保存文件的功能
 */
void WorkerManager::save() {
    std::ofstream ofs;
    ofs.open(FILE_NAME, std::ios::out | std::ios::trunc); //默认方式打开文件 | 明确指定清空内容写
    if (!ofs.is_open()) {
        std::cout << "文件打开失败\n";
        return;
    }
    for (int i = 0; i < this->workNum_; i++) {
        ofs << this->workerArray_[i]->id_ << " "
                << this->workerArray_[i]->name_ << " "
                << this->workerArray_[i]->departmentId_ << " "
                << std::endl;
    }


    //关闭文件
    ofs.close();
}


/**
 * 读取持久化文件，初始化人员
 */

void WorkerManager::initWork() {
    std::ifstream ifs;
    ifs.open(FILE_NAME, std::ios::in);

    int id;
    std::string name;
    int did;
    int index = 0;
    while (ifs >> id >> name >> did) {
        Worker *worker = nullptr;
        if (did == 1) {
            worker = new Boss(id, name, did);
        }
        if (did == 2) {
            worker = new Manager(id, name, did);
        }
        if (did == 3) {
            worker = new Employee(id, name, did);
        }
        this->workerArray_[index] = worker;
        index++;
    }

    ifs.close();
}

/**
 * 读取持久化文件， 统计人数
 */
int WorkerManager::getWorkNum() {
    std::ifstream ifs;
    ifs.open(FILE_NAME, std::ios::in); //读文件方式 打开文件
    int id;
    std::string name;
    int did;

    int num = 0; //统计人数
    while (ifs >> id && ifs >> name && ifs >> did) {
        num++;
    }
    ifs.close();

    return num;
}

/**
 * 显示职工信息
 */
void WorkerManager::showAllWork() {
    if (this->fileIsEmpty_) {
        std::cout << "当前没有任何职工~" << std::endl;
        return;
    }


    for (int i = 0; i < this->workNum_; i++) {
        this->workerArray_[i]->showInfo();
    }
}


/**
 * 判断职工 是否存在，返回索引
 */
int WorkerManager::isExist(int id) {
    int index = -1;
    for (int i = 0; i < this->workNum_; i++) {
        if (this->workerArray_[i]->id_ == id) {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * 删除职工
 */
void WorkerManager::deleteWork() {
    if (this->fileIsEmpty_) {
        std::cout << "当前员工系统中，没有员工~" << std::endl;
        return;
    }


    std::cout << "请输入要删除的职编号：" << std::endl;
    int id;
    std::cin >> id;
    int index = isExist(id);
    if (id == -1) {
        std::cout << "您要删除的职工不存在~" << std::endl;
        return;
    }

    //删除职工就是 让后面的元素都前移，覆盖
    for (int i = index; i < this->workNum_ - 1; i++) {
        this->workerArray_[i] = this->workerArray_[i + 1];
    }
    this->workNum_--;
    this->save();
    std::cout << "完成删除职工" << std::endl;
}

/**
 * 修改职工
 */

void WorkerManager::updateWork() {
    if (this->fileIsEmpty_) {
        std::cout << "当前员工系统中，没有员工~" << std::endl;
        return;
    }

    std::cout << "请输入要修改的职工编号：" << std::endl;
    int id;
    std::cin >> id;
    int index = isExist(id);
    if (id == -1) {
        std::cout << "您要修改的职工不存在~" << std::endl;
        return;
    }

    //先删除
    delete [] this->workerArray_[index];

    int newId;
    std::string newName;
    int newDid;
    std::cout << "请输入新的编号" << std::endl;
    std::cin >> newId;
    std::cout << "请输入新的姓名" << std::endl;
    std::cin >> newName;
    std::cout << "请输入新的部门编号" << std::endl;
    std::cin >> newDid;


    Worker *worker = nullptr;
    switch (newDid) {
        case 1:
            worker = new Boss(newId, newName, newDid);
            break;
        case 2:
            worker = new Manager(newId, newName, newDid);
            break;
        case 3:
            worker = new Employee(newId, newName, newDid);
            break;
        default:
            std::cout << "输入有误,退出添加" << std::endl;
            system("pause");
            system("cls");
            return;
            break;
    }
    this->workerArray_[index] = worker;

    this->save();
    std::cout << "修改完成~" << std::endl;
}

/**
 * 按照编号 查找员工
 */
void WorkerManager::findWork() {
    if (this->fileIsEmpty_) {
        std::cout << "当前员工系统中，没有员工~" << std::endl;
        return;
    }

    std::cout << "请输入职工的编号" <<std::endl;
    int id ;
    std::cin  >> id;
    int index = this->isExist(id);
    if (id == -1) {
        std::cout << "您要查找的员工不存在~" << std::endl;
        return;
    }

    this->workerArray_[index]->showInfo();

}


/**
 * 排序,升序
 */


void WorkerManager::sortWork() {
    if (this->fileIsEmpty_) {
        std::cout << "当前员工系统中，没有员工~" << std::endl;
        return;
    }



    for (int i =0 ; i <this->workNum_; i++) {
        int minIndex = i;
        for (int j = i+1; j <this -> workNum_ ; j ++) {
            if (this->workerArray_[minIndex]->id_ > this->workerArray_[j]->id_) {
                minIndex =j;
            }
        }
        if (i != minIndex) {
            Worker * temp = this ->workerArray_[i];
            this ->workerArray_[i] = this ->workerArray_[minIndex];
            this ->workerArray_[minIndex] = temp;
        }

    }
        this->save();
    std::cout << "排序完成" << std::endl;


}

/**
 * 清空文件
 */


void WorkerManager::clearAllWork() {
    std::cout << "您确定要清空所有的职工吗?" <<std::endl;
    std::cout << "1: 确定" <<std::endl;
    std::cout << "2: 返回" <<std::endl;
    int select ;
    std::cin >> select;
    if (select == 2) {
        return;
    }
    std::ofstream ofs(FILE_NAME,std::ios::trunc); //删除文件后再创建文件;
    ofs.close();



    //清除堆数据
    if (this ->workerArray_ !=nullptr) {
        for (int i = 0 ; i <this->workNum_ ; i++) {
            delete this->workerArray_[i];
            this ->workerArray_[i] = nullptr;
        }
        this->workerArray_ = nullptr;
    }





}
