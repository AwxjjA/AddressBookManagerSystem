#include<iostream>
#include<string>

#define MAXN 1000  //通讯录的最大人数

using namespace std;

//设计联系人结构体
struct Person
{
	string p_name;        //姓名

	int p_sex;           //性别

	int p_age;           //年龄

	string p_phone;      //电话

	string p_address;   //地址
};

//通讯录结构体
struct AddressBook
{
	struct Person PersonArray[MAXN];  //通讯录中保存的联系人数组    

    int M_size;   //通讯录中当前记录的联系人个数
};


//显示菜单功能
void showMenu() {
	cout << "************************" << endl;
	cout << "  ----1.添加联系人----" << endl;
	cout << endl;
	cout << "  ----2.显示联系人----" << endl;
	cout << endl;
	cout << "  ----3.删除联系人----" << endl;
	cout << endl;
	cout << "  ----4.查找联系人----" << endl;
	cout << endl;
	cout << "  ----5.修改联系人----" << endl;
	cout << endl;
	cout << "  ----6.清空联系人----" << endl;
	cout << endl;
	cout << "  ----0.退出通讯录----" << endl;
	cout << "************************" << endl;
	cout << endl;
}

//添加联系人功能
void addPerson(AddressBook * abs)
{
	//判断通讯录中人数是否已满
	if (abs->M_size == MAXN) {
		cout << "通讯录已满，不可添加了" << endl;
		return;
	}
	else {
		//添加联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cout << endl;
		cin >> name;
		abs->PersonArray[abs->M_size].p_name = name;
		cout << endl;

		//添加性别
		cout << "请输入性别：" << endl;
		cout << endl;
		cout << "1 ---> 男 " << endl;
		cout << "2 ---> 女" << endl;
		cout << "3 ---> LGBT" << endl;
		cout << endl;

		int sex = 0;

		while (true) {
			//输入1，2，3可以退出循环；若输入其他则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2 || sex == 3) {
				abs->PersonArray[abs->M_size].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << endl;
		int age = 0;
		cout << "请输入年龄：" << endl;
		cout << endl;
	
		while (true) {
			//输入合适的年龄范围可退出循环；否则重新输入
			cin >> age;
			if (age > 0 && age < 150) {
				abs->PersonArray[abs->M_size].p_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//电话
		cout << endl;
		cout << "请输入电话：" << endl;
		cout << endl;
		string phone;
		cin >> phone;
        abs->PersonArray[abs->M_size].p_phone = phone;

		//住址
		cout << endl;
		cout << "请输入住址：" << endl;
		cout << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->M_size].p_address = address;

		//更新通讯录人数
		abs->M_size++;

		cout << endl;
		cout << "此联系人已添加成功!" << endl;
		cout << endl;

		system("pause");
		system("cls");

	}
}
  
//显示所有联系人
void showPerson(AddressBook * abs) {
	//判断当前通讯库中人数是否为0
	//若为0，提示记录为空；
	if (abs->M_size == 0) {
		cout << "当前记录为空！" << endl;
		cout << endl;
	}
	//否则显示已记录的联系人信息
	else {
		for (int i = 0; i < abs->M_size; i++) {

			cout << "姓名： " << abs->PersonArray[i].p_name << "\t";
			cout << "性别： " << (abs->PersonArray[i].p_sex == 1 ? "男" : (abs->PersonArray[i].p_sex == 2 ? "女" : "LGBT")) << "\t";  //!!!!!!!!!!
			cout << "年龄： " << abs->PersonArray[i].p_age << "\t";
			cout << "电话： " << abs->PersonArray[i].p_phone << "\t";
			cout << "住址： " << abs->PersonArray[i].p_address << endl;
			cout << endl;
		}
	}
	

	system("pause");
	system("cls");
}

//检测联系人是否存在；若存在，返回联系人所在数组的具体位置，不存在返回-1
int isExist(AddressBook * abs, string name) {
	for (int i = 0; i < abs->M_size; i++) {
		if (abs->PersonArray[i].p_name == name) {
			return i;
		}
	}
	return -1;

}

//删除联系人
void deletePerson(AddressBook * abs) {
	cout << "请输入您要删除的联系人" << endl;
	cout << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {   //有这个人
		for (int i = ret; i < abs->M_size; i++) {
			abs->PersonArray[i] = abs->PersonArray[i + 1];  //覆盖
		}
		abs->M_size--;  //数组大小减小
		cout << "删除此联系人成功!" << endl;
		cout << endl;
	}
	else {  //无这个人
		cout << endl;
		cout << "查无此人" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(AddressBook * abs) {
	cout << "请输入您要查找的联系人" << endl;
	cout << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {   //有这个人
		cout << endl;
		cout << "姓名：" << abs->PersonArray[ret].p_name << "\t";
		cout << "性别：" << (abs->PersonArray[ret].p_sex == 1 ? "男" : (abs->PersonArray[ret].p_sex == 2 ? "女" : "LGBT")) << "\t";
		cout << "年龄：" << abs->PersonArray[ret].p_age << "\t";
		cout << "电话： " << abs->PersonArray[ret].p_phone << "\t";
		cout << "住址：" << abs->PersonArray[ret].p_address << endl;
		cout << endl;
	}
	else {  //无这个人
		cout << endl;
		cout << "查无此人" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//修改联系人
void changePerson(AddressBook * abs) {
	cout << "请输入您要修改的联系人的姓名：" << endl;
	cout << endl;
	string name;
	cin >> name;
	cout << endl;

	int ret = isExist(abs, name);

	if (ret != -1) {   //有这个人
		cout << endl;
		
		//修改姓名
		string name;
		cout << "请输入修改后的联系人的姓名：" << endl;
		cin >> name;
		abs->PersonArray[ret].p_name = name;
		cout << endl;

		//修改性别
		cout << "请输入您要修改的联系人的性别：" << endl;
		cout << endl;
		cout << "1 ---> 男 " << endl;
		cout << "2 ---> 女" << endl;
		cout << "3 ---> LGBT" << endl;
		cout << endl;
		int sex = 0;
		while (true) {
			//输入1，2，3可以退出循环；若输入其他则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2 || sex == 3) {
				abs->PersonArray[ret].p_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << endl;

		//修改年龄
		cout << "请输入您要修改的联系人的年龄：" << endl;
		cout << endl;
		int age = 0;
		while (true) {
			//输入合适的年龄范围可退出循环；否则重新输入
			cin >> age;
			if (age > 0 && age < 150) {
				abs->PersonArray[ret].p_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << endl;

		//修改电话
		cout << "请输入您要修改的联系人的电话：" << endl;
		cout << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[ret].p_phone = phone;
		cout << endl;

		//修改住址
		cout << "请输入您要修改的联系人的住址：" << endl;
		cout << endl;
		string address;
		cin >> address;
		abs->PersonArray[ret].p_address = address;
		cout << endl;
		
		cout << "修改成功" << endl;
		cout << endl;
	}
	else {  //无这个人
		cout << "查无此人" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");

}

//清空联系人
void cleanAllPerson(AddressBook * abs) {
	abs->M_size = 0;
	cout << "联系人已清空！" << endl;
	cout << endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	AddressBook abs;

	//初始化通讯录中当前人数
	abs.M_size = 0;

	int select = 0;

	while (true) {
		showMenu();

		cout << "请输入您的选择：";
		cin >>  select;

		switch (select) 
		{
		case 1:  //1.添加联系人
			cout << endl;
			addPerson(&abs);  //利用地址传递，可以修改实参
			break;
		case 2:  //2.显示联系人
			cout << endl;
			showPerson(&abs);
			break;
		case 3:  //3.删除联系人
			cout << endl;
			deletePerson(&abs);
			break;
		case 4:  //4.查找联系人
			cout << endl;
			findPerson(&abs);
			break;
		case 5:  //5.修改联系人
			cout << endl;
			changePerson(&abs);
			break;
		case 6:  //6.清空联系人
			cout << endl;
			cleanAllPerson(&abs);
			break;
		case 0:  //0.退出通讯录
			cout << endl;
			
			cout << "欢迎下次使用！" << endl;
			cout << endl;
			system("pause");
			return 0;
			
			break;
		default:
			break;
		}
	}

	//cout << endl;

	system("pause");
	return 0;
}
