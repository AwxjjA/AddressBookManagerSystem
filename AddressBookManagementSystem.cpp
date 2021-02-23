#include<iostream>
#include<string>

#define MAXN 1000 //ͨѶ¼���������

using namespace std;

//�����ϵ�˽ṹ��
struct Person
{
	string p_name;        //����

	int p_sex;           //�Ա�

	int p_age;           //����

	string p_phone;      //�绰

	string p_address;   //��ַ
};

//ͨѶ¼�ṹ��
struct AddressBook
{
	struct Person PersonArray[MAXN];  //ͨѶ¼�б������ϵ������    

    int M_size;   //ͨѶ¼�е�ǰ��¼����ϵ�˸���
};


//��ʾ�˵�����
void showMenu() {
	cout << "************************" << endl;
	cout << "  ----1.�����ϵ��----" << endl;
	cout << endl;
	cout << "  ----2.��ʾ��ϵ��----" << endl;
	cout << endl;
	cout << "  ----3.ɾ����ϵ��----" << endl;
	cout << endl;
	cout << "  ----4.������ϵ��----" << endl;
	cout << endl;
	cout << "  ----5.�޸���ϵ��----" << endl;
	cout << endl;
	cout << "  ----6.�����ϵ��----" << endl;
	cout << endl;
	cout << "  ----0.�˳�ͨѶ¼----" << endl;
	cout << "************************" << endl;
	cout << endl;
}

//�����ϵ�˹���
void addPerson(AddressBook * abs)
{
	//�ж�ͨѶ¼�������Ƿ�����
	if (abs->M_size == MAXN) {
		cout << "ͨѶ¼���������������" << endl;
		return;
	}
	else {
		//�����ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cout << endl;
		cin >> name;
		abs->PersonArray[abs->M_size].p_name = name;
		cout << endl;

		//����Ա�
		cout << "�������Ա�" << endl;
		cout << endl;
		cout << "1 ---> �� " << endl;
		cout << "2 ---> Ů" << endl;
		cout << "3 ---> LGBT" << endl;
		cout << endl;

		int sex = 0;

		while (true) {
			//����1��2��3�����˳�ѭ������������������������
			cin >> sex;
			if (sex == 1 || sex == 2 || sex == 3) {
				abs->PersonArray[abs->M_size].p_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << endl;
		int age = 0;
		cout << "���������䣺" << endl;
		cout << endl;
	
		while (true) {
			//������ʵ����䷶Χ���˳�ѭ����������������
			cin >> age;
			if (age > 0 && age < 150) {
				abs->PersonArray[abs->M_size].p_age = age;
				break;
			}
			cout << "������������������" << endl;
		}

		//�绰
		cout << endl;
		cout << "������绰��" << endl;
		cout << endl;
		string phone;
		cin >> phone;
        abs->PersonArray[abs->M_size].p_phone = phone;

		//סַ
		cout << endl;
		cout << "������סַ��" << endl;
		cout << endl;
		string address;
		cin >> address;
		abs->PersonArray[abs->M_size].p_address = address;

		//����ͨѶ¼����
		abs->M_size++;

		cout << endl;
		cout << "����ϵ������ӳɹ�!" << endl;
		cout << endl;

		system("pause");
		system("cls");

	}
}
  
//��ʾ������ϵ��
void showPerson(AddressBook * abs) {
	//�жϵ�ǰͨѶ���������Ƿ�Ϊ0
	//��Ϊ0����ʾ��¼Ϊ�գ�
	if (abs->M_size == 0) {
		cout << "��ǰ��¼Ϊ�գ�" << endl;
		cout << endl;
	}
	//������ʾ�Ѽ�¼����ϵ����Ϣ
	else {
		for (int i = 0; i < abs->M_size; i++) {

			cout << "������ " << abs->PersonArray[i].p_name << "\t";
			cout << "�Ա� " << (abs->PersonArray[i].p_sex == 1 ? "��" : (abs->PersonArray[i].p_sex == 2 ? "Ů" : "LGBT")) << "\t";  //!!!!!!!!!!
			cout << "���䣺 " << abs->PersonArray[i].p_age << "\t";
			cout << "�绰�� " << abs->PersonArray[i].p_phone << "\t";
			cout << "סַ�� " << abs->PersonArray[i].p_address << endl;
			cout << endl;
		}
	}
	

	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ������ڣ�������ϵ����������ľ���λ�ã������ڷ���-1
int isExist(AddressBook * abs, string name) {
	for (int i = 0; i < abs->M_size; i++) {
		if (abs->PersonArray[i].p_name == name) {
			return i;
		}
	}
	return -1;

}

//ɾ����ϵ��
void deletePerson(AddressBook * abs) {
	cout << "��������Ҫɾ������ϵ��" << endl;
	cout << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {   //�������
		for (int i = ret; i < abs->M_size; i++) {
			abs->PersonArray[i] = abs->PersonArray[i + 1];  //����
		}
		abs->M_size--;  //�����С��С
		cout << "ɾ������ϵ�˳ɹ�!" << endl;
		cout << endl;
	}
	else {  //�������
		cout << endl;
		cout << "���޴���" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(AddressBook * abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	cout << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1) {   //�������
		cout << endl;
		cout << "������" << abs->PersonArray[ret].p_name << "\t";
		cout << "�Ա�" << (abs->PersonArray[ret].p_sex == 1 ? "��" : (abs->PersonArray[ret].p_sex == 2 ? "Ů" : "LGBT")) << "\t";
		cout << "���䣺" << abs->PersonArray[ret].p_age << "\t";
		cout << "�绰�� " << abs->PersonArray[ret].p_phone << "\t";
		cout << "סַ��" << abs->PersonArray[ret].p_address << endl;
		cout << endl;
	}
	else {  //�������
		cout << endl;
		cout << "���޴���" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
}

//�޸���ϵ��
void changePerson(AddressBook * abs) {
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������" << endl;
	cout << endl;
	string name;
	cin >> name;
	cout << endl;

	int ret = isExist(abs, name);

	if (ret != -1) {   //�������
		cout << endl;
		
		//�޸�����
		string name;
		cout << "�������޸ĺ����ϵ�˵�������" << endl;
		cin >> name;
		abs->PersonArray[ret].p_name = name;
		cout << endl;

		//�޸��Ա�
		cout << "��������Ҫ�޸ĵ���ϵ�˵��Ա�" << endl;
		cout << endl;
		cout << "1 ---> �� " << endl;
		cout << "2 ---> Ů" << endl;
		cout << "3 ---> LGBT" << endl;
		cout << endl;
		int sex = 0;
		while (true) {
			//����1��2��3�����˳�ѭ������������������������
			cin >> sex;
			if (sex == 1 || sex == 2 || sex == 3) {
				abs->PersonArray[ret].p_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << endl;

		//�޸�����
		cout << "��������Ҫ�޸ĵ���ϵ�˵����䣺" << endl;
		cout << endl;
		int age = 0;
		while (true) {
			//������ʵ����䷶Χ���˳�ѭ����������������
			cin >> age;
			if (age > 0 && age < 150) {
				abs->PersonArray[ret].p_age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		cout << endl;

		//�޸ĵ绰
		cout << "��������Ҫ�޸ĵ���ϵ�˵ĵ绰��" << endl;
		cout << endl;
		string phone;
		cin >> phone;
		abs->PersonArray[ret].p_phone = phone;
		cout << endl;

		//�޸�סַ
		cout << "��������Ҫ�޸ĵ���ϵ�˵�סַ��" << endl;
		cout << endl;
		string address;
		cin >> address;
		abs->PersonArray[ret].p_address = address;
		cout << endl;
		
		cout << "�޸ĳɹ�" << endl;
		cout << endl;
	}
	else {  //�������
		cout << "���޴���" << endl;
	}
	cout << endl;
	system("pause");
	system("cls");

}

//�����ϵ��
void cleanAllPerson(AddressBook * abs) {
	abs->M_size = 0;
	cout << "��ϵ������գ�" << endl;
	cout << endl;
	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	AddressBook abs;

	//��ʼ��ͨѶ¼�е�ǰ����
	abs.M_size = 0;

	int select = 0;

	while (true) {
		showMenu();

		cout << "����������ѡ��";
		cin >>  select;

		switch (select) 
		{
		case 1:  //1.�����ϵ��
			cout << endl;
			addPerson(&abs);  //���õ�ַ���ݣ������޸�ʵ��
			break;
		case 2:  //2.��ʾ��ϵ��
			cout << endl;
			showPerson(&abs);
			break;
		case 3:  //3.ɾ����ϵ��
			cout << endl;
			deletePerson(&abs);
			break;
		case 4:  //4.������ϵ��
			cout << endl;
			findPerson(&abs);
			break;
		case 5:  //5.�޸���ϵ��
			cout << endl;
			changePerson(&abs);
			break;
		case 6:  //6.�����ϵ��
			cout << endl;
			cleanAllPerson(&abs);
			break;
		case 0:  //0.�˳�ͨѶ¼
			cout << endl;
			
			cout << "��ӭ�´�ʹ�ã�" << endl;
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