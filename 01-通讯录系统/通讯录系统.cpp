#include <iostream>
#include <cstdlib> // 引入 system 函数的头文件

#include <string>

using namespace std;

//宏定义
#define MAX 1000

/**
联系人的结构体
*/
struct Person {
    string m_name; //姓名
    int m_sex; //性别
    int m_age; //年龄
    string m_phone; //电话
    string m_address; //家庭住址
};

/**
 * 通讯录的结构体
 */
struct AddressBooks {
    Person personArray[MAX]; //通讯录中保存的联系人数组
    int m_size; //通讯录中实际保存的联系人数
};


/**
 * 显示菜单函数
 */
void showMenu() {
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人 *****" << endl;
    cout << "*****  2.显示联系人 *****" << endl;
    cout << "*****  3.删除联系人 *****" << endl;
    cout << "*****  4.查找联系人 *****" << endl;
    cout << "*****  5.修改联系人 *****" << endl;
    cout << "*****  6.清空联系人 *****" << endl;
    cout << "*****  0.退出通讯录 *****" << endl;
    cout << "**************************" << endl;
}

/**
 *1. 添加联系人
 */
void addPerson(AddressBooks *abs) {
    //判断通讯录是否满了？
    if (abs->m_size == MAX) {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }


    //姓名
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->personArray[abs->m_size].m_name = name;

    //性别
    int sex;
    cout << "请输入性别：1.男 2.女" << endl;
    while (true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[abs->m_size].m_sex = sex;
            break;
        }
        cout << "输入错误，请重新输入：" << endl;
    }

    //年纪
    int age;
    cout << "请输入年龄：" << endl;
    cin >> age;
    abs->personArray[abs->m_size].m_age = age;


    //电话号码
    string phone;
    cout << "请输入电话号码：" << endl;
    cin >> phone;
    abs->personArray[abs->m_size].m_phone = phone;

    //地址
    string address;
    cout << "请输入地址：" << endl;
    cin >> address;
    abs->personArray[abs->m_size].m_address = address;


    cout << "添加成功" << endl;
    abs->m_size++;
    system("pause"); //系统函数 按任意键继续
    system("cls"); //系统函数：清屏
}

/**
 *2. 显示联系人
 */
void showPerson(AddressBooks *abs) {
    //判断通讯录人数
    if (abs->m_size == 0) {
        cout << "没有联系人" << endl;
        return;
    }

    //显示联系人信息
    for (int i = 0; i < abs->m_size; i++) {
        cout << "姓名：" << abs->personArray[i].m_name << "\t";
        cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[i].m_age << "\t";
        cout << "电话：" << abs->personArray[i].m_phone << "\t";
        cout << "地址：" << abs->personArray[i].m_address << endl;
        cout << "--------------------------" << endl;
        cout << "--------------------------" << endl;
        cout << "--------------------------" << endl;
    }
    system("pause");
    system("cls");
}


int isExist(AddressBooks *abs, string name) {
    for (int i = 0; i < abs->m_size; i++) {
        if (abs->personArray[i].m_name == name) {
            return i;
        }
    }

    return -1;
}

/**
 * 删除联系人
 */

void deletePerson(AddressBooks *abs) {
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);
    if (res == -1) {
        cout << "没有找到该联系人" << endl;
        system("pause"); //系统函数 按任意键继续
        return;
    }


    for (int i = res; i < abs->m_size - 1; i++) {
        abs->personArray[i] = abs->personArray[i + 1];
    }

    abs->m_size--;

    cout << "删除成功！" << endl;

    system("pause"); //系统函数 按任意键继续
    system("cls"); //系统函数：清屏
}

/**
 * 查找指定联系人
 */
void findPerson(AddressBooks *abs) {
    cout << "请输入要查找的联系人" << endl;
    string name;
    cin >> name;

    //判断指定联系人是否存在
    int res = isExist(abs, name);
    if (res == -1) {
        cout << "没有找到联系人！" << endl;
        system("pause"); //系统函数 按任意键继续
        return;
    }

    cout << "姓名：" << abs->personArray[res].m_name << "\t";
    cout << "性别：" << (abs->personArray[res].m_sex == 1 ? "男" : "女") << "\t";
    cout << "年龄：" << abs->personArray[res].m_age << "\t";
    cout << "电话：" << abs->personArray[res].m_phone << "\t";
    cout << "地址：" << abs->personArray[res].m_address << endl;

    system("pause"); //系统函数 按任意键继续
    system("cls"); //系统函数：清屏
}

/**
 * 修改联系人
 */
void updatePerson(AddressBooks *abs) {
    cout << "请输入要修改的姓名：" << endl;
    cout << "请输入要修改的姓名：" << endl;
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if (res == -1) {
        cout << "没有找到联系人！" << endl;
        system("pause"); //系统函数 按任意键继续
        return;
    }

    //姓名
    string newName;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->personArray[res].m_name = newName;

    //性别
    int sex;
    cout << "请输入性别：1.男 2.女" << endl;
    while (true) {
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[res].m_sex = sex;
            break;
        }
        cout << "输入错误，请重新输入：" << endl;
    }

    //年纪
    int age;
    cout << "请输入年龄：" << endl;
    cin >> age;
    abs->personArray[res].m_age = age;


    //电话号码
    string phone;
    cout << "请输入电话号码：" << endl;
    cin >> phone;
    abs->personArray[res].m_phone = phone;

    //地址
    string address;
    cout << "请输入地址：" << endl;
    cin >> address;
    abs->personArray[res].m_address = address;

    cout << "修改成功！" << endl;
    system("pause");
    system("cls");
}

/**
 * 清空联系人
 */
void clearPerson(AddressBooks *abs) {
    abs->m_size =0;

    cout << "清空成功！" << endl;
    system("pause");
    system("cls");

}


int main() {
    // 设置控制台输入/输出为 UTF-8（解决中文乱码）
    system("chcp 65001");


    //创建通讯录的机构提
    AddressBooks abs;
    abs.m_size = 0;


    int select = 0; // 用户输入选项

    while (true) {
        showMenu();
        cin >> select;

        switch (select) {
            case 1: // 添加联系人
                addPerson(&abs);
                break;

            case 2: // 显示联系人
                showPerson(&abs);
                break;

            case 3: // 删除联系人
                deletePerson(&abs);
                break;

            case 4: // 查找联系人
                findPerson(&abs);
                break;

            case 5: // 修改联系人
                updatePerson(&abs);
                break;

            case 6: // 清空联系人
                clearPerson(&abs);
                break;

            case 0: // 退出通讯录
                cout << "欢迎下次使用" << endl;
                system("pause"); //系统函数 按任意键继续
                return 0;

            default:
                cout << "输入无效，请重新选择！" << endl;
                break;
        }
    }
}
