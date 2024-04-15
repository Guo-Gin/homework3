#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include <ctime>
#pragma warning(disable:4996)//����ʱ����error C4996 �������
#define Maxsize 100
int total = 0;
typedef struct House {//����
	char roomnumber[Maxsize];//���ƺ�
	double square;//���
	int storey;//¥��
	char building;//¥��
};
typedef struct Parking {//��λ
	int parkingnumber;//���
	char parkingtype[Maxsize];//���
};
typedef struct Node {//ҵ��
	char name[Maxsize];//ҵ������
	char telephone[Maxsize];//ҵ����ϵ��ʽ
	char id[Maxsize];//ҵ�����֤��
	House house;//����
	Parking parking;//��λ
	double fee;//��ҵ�����
	double monfee;//ÿ������ɵ���ҵ��
	Node* next;
}*HouseholeList, * Person;
HouseholeList houselist = new Node[Maxsize];
void Showmenu();//չʾ�ܲ˵�
void Feemenu();//չʾ��ҵ��Ϣ�˵�
void Ownermenu();//ҵ����Ϣ����˵�
void Statistical();//ͳ�Ʋ�ѯ�˵�
void Payment();//��ѯ�ɷ���Ϣ
void Checkfeemenu();//��ѯ��ҵ����Ϣ�˵�
void Enterinfo();//����ҵ����Ϣ
void add();//ҵ����Ϣ¼��
void revise();//ҵ����Ϣ�޸�
void deleteinfo();//ҵ����Ϣɾ��
void Getfee();//������ҵ��
void Checkperson();//��ѯ������Ϣ
void CheckfeeBui();//��ѯ��ҵ����Ϣ����������¥���ĵ�ס����һ¥����¥��,��������
void CheckfeeFe();//��ѯ��ҵ����Ϣ��������ҵ�������򣩣��鲢����
void CheckfeeRnum();//��ѯ��ҵ����Ϣ�������������ַ��������򣩣�������
void Heart();//����
void Showmenu() {//չʾ�ܲ˵�
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************��ӭ����С����ҵ�ѹ���ϵͳ******************" << endl << endl;
	cout << "               * * * * * * * * * &��ϵͳ�ѿ�������ҵ����ѡ��& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.��ҵ��Ϣ����ϵͳ   *" << endl << endl;
	cout << "                                   * 2.ͳ�Ʋ�ѯϵͳ       *" << endl << endl;
	cout << "                                   * 3.�˳�����           *" << endl << endl;
	while (true) {
		cout << "������������Ҫ�����ϵͳǰ�ı�ţ�" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
			system("cls");
			Feemenu();
			break;
		case 2:
			system("cls");
			Statistical();
			break;
		case 3:
			system("cls");
			cout << "�ɹ��˳�ϵͳ���ڴ�������Ӵ��" << endl;
			Heart();
			exit(0);
		default:
			cout << "��ҵ��û�п���Ӵ�����������룺" << endl;
			break;
		}
	}
}
void Feemenu() {//չʾ��ҵ��Ϣ�˵�
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************��ӭ������ҵ��Ϣ����ϵͳ******************" << endl << endl;
	cout << "               * * * * * * * * * &��ϵͳ�ѿ�������ҵ����ѡ��& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.С��ҵ����Ϣ����ϵͳ *" << endl << endl;
	cout << "                                   * 2.������ҵ�ѹ���ϵͳ   *" << endl << endl;
	cout << "                                   * 3.�������˵�           *" << endl << endl;
	cout << "                                   * 4.�˳�����             *" << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "������������Ҫ�����ϵͳǰ�ı�ţ�" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
		system("cls");
		Ownermenu();
		break;
	case 2:
		Getfee();
		system("pause");
		system("cls");
		Feemenu();
		break;
	case 3:
		system("cls");
		Showmenu();
		break;
	case 4:
		system("cls");
		cout << "�ɹ��˳�ϵͳ���ڴ�������Ӵ��" << endl;
		Heart();
		exit(0);
	}
}
void Ownermenu() {//ҵ����Ϣ����˵�
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************��ӭ����ҵ����Ϣ����ϵͳ******************" << endl << endl;
	cout << "               * * * * * * * * * &��ϵͳ�ѿ�������ҵ����ѡ��& * * * * * * * * *" << endl << endl;
	cout << "                                    * 1.ҵ����Ϣ¼�� *" << endl << endl;
	cout << "                                    * 2.ҵ����Ϣ�޸� *" << endl << endl;
	cout << "                                    * 3.ҵ����Ϣɾ�� *" << endl << endl;
	cout << "                                    * 4.�����ϲ�˵� *" << endl << endl;
	cout << "                                    * 5.�˳�����     *" << endl << endl;
	cout << "������������Ҫ�����ҵ��ǰ�ı�ţ�" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
		add();
		break;
	case 2:
		revise();
		break;
	case 3:
		deleteinfo();
		break;
	case 4:
		system("cls");
		Feemenu();
		break;
	case 5:
		system("cls");
		cout << "�ɹ��˳�ϵͳ���ڴ�������Ӵ��" << endl;
		Heart();
		exit(0);
	}
}
void Statistical() {//ͳ�Ʋ�ѯ�˵�
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************��ӭ����ͳ�Ʋ�ѯϵͳ******************" << endl << endl;
	cout << "               * * * * * * * * * &��ϵͳ�ѿ�������ҵ����ѡ��& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.��ѯ�ɷ���Ϣ   *" << endl << endl;
	cout << "                                   * 2.��ѯ������Ϣ   *" << endl << endl;
	cout << "                                   * 3.��ѯ��ҵ����Ϣ *" << endl << endl;
	cout << "                                   * 4.�����ϲ�˵�   *" << endl << endl;
	cout << "                                   * 5.�˳�����       *" << endl << endl;
	cout << "������������Ҫ�����ҵ��ǰ�ı�ţ�" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
		system("cls");
		Payment();
		break;
	case 2:
		Checkperson();
		break;
	case 3:
		system("cls");
		Checkfeemenu();
		break;
	case 4:
		system("cls");
		Showmenu();
		break;
	case 5:
		system("cls");
		cout << "�ɹ��˳�ϵͳ���ڴ�������Ӵ��" << endl;
		Heart();
		exit(0);
	}
}
void Checkfeemenu() {//��ѯ��ҵ����Ϣ�˵�
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************��ӭ�����ѯ��ҵ����Ϣϵͳ******************" << endl << endl;
	cout << "               * * * * * * * * * &��ϵͳ�ѿ�������ҵ����ѡ��& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.����¥���Լ����ƺŲ�ѯ *" << endl << endl;
	cout << "                                   * 2.������ҵ������ѯ     *" << endl << endl;
	cout << "                                   * 3.����������ѯ           *" << endl << endl;
	cout << "                                   * 4.�����ϲ�˵�           *" << endl << endl;
	cout << "                                   * 5.�˳�����               *" << endl << endl;
	cout << "������������Ҫ�����ҵ��ǰ�ı�ţ�" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
		CheckfeeBui();
		break;
	case 2:
		CheckfeeFe();
		break;
	case 3:
		CheckfeeRnum();
		break;
	case 4:
		system("cls");
		Statistical();
		break;
	case 5:
		system("cls");
		cout << "�ɹ��˳�ϵͳ���ڴ�������Ӵ��" << endl;
		Heart();
		exit(0);
	}
}
void Enterinfo() {//����ҵ����Ϣ
	FILE* fp1;
	int i = 1;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
	while (fscanf(fp1, "%s %s %s %c %d %s %lf %d %s %lf %lf", houselist[i].name, houselist[i].telephone, houselist[i].id, &houselist[i].house.building, &houselist[i].house.storey, houselist[i].house.roomnumber, &houselist[i].house.square, &houselist[i].parking.parkingnumber, houselist[i].parking.parkingtype, &houselist[i].fee, &houselist[i].monfee) == 11) {
		i++;
	}
	total = i - 1;
	fclose(fp1);
}
double Payablefee(double sq, char ty[], int hei) {//����Ӧ���ɵ���ҵ��
	double sum = 0;
	if (strcmp(ty, "#") == 0) {
		sum += 0;
	}
	else if (strcmp(ty, "С") == 0) {
		sum += 80;
	}
	else if (strcmp(ty, "��") == 0) {
		sum += 100;
	}
	else if (strcmp(ty, "��") == 0) {
		sum += 120;
	}
	sum += sq * 2;
	if (hei == 1) {
		sum += (4 * 0.5);
	}
	if (hei == 9) {
		sum += (1 * 10);
	}
	return sum;
}
void add() {//ҵ����Ϣ¼��
	FILE* fp1;
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char name1[100], id1[100];
	char bui;
loop:
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "a+");
	cout << "******��ֱ���������Ҫ¼���ҵ����������Ϣ******" << endl;
	cout << "* ������";
	cin >> name;
	cout << endl;
	cout << "* ��ϵ��ʽ��";
	cin >> tele;
	cout << endl;
	cout << "* ���֤�ţ�";
	cin >> id;
	cout << endl;
	cout << "******�����뷿����Ϣ******" << endl;
	cout << "* ¥����";
	cin >> bui;
	cout << endl;
	cout << "* ¥�㣺";
	cin >> hei;
	cout << endl;
	cout << "* ���ƺţ�";
	cin >> rnum;
	cout << endl;
	cout << "* �����";
	cin >> sq;
	cout << endl;
	cout << "******�����복λ��Ϣ******" << endl;
	cout << "--����г�λ��Ϣ���밴1�������밴0--" << endl;
	int jud;
	cin >> jud;
	if (jud == 1) {
		cout << "* * * * ������������Ϣ * * * *" << endl;
		cout << "* ��ţ�";
		cin >> number;
		cout << endl;
		cout << "* ���";
		cin >> ctype;
		cout << endl;
	}
	else {
		number = 0;
		strcpy(ctype, "#");
	}
	cout << "* ��ҵ����";
	cin >> fee;
	cout << endl;
	monfee = Payablefee(sq, ctype, hei);
	cout << "* ��������Ϣ�ɵ�ÿ���������ҵ��Ϊ��" << monfee << endl;
	fprintf(fp1, "%s %s %s %c %d %s %.1lf %d %s %.1lf %.1lf\n", name, tele, id, bui, hei, rnum, sq, number, ctype, fee, monfee);
	fclose(fp1);
	cout << "��ӳɹ�!!" << endl;
	cout << "�Ƿ������ӣ����ǣ���1�����񣩰�0" << endl;
	int jude;
	cin >> jude;
	if (jude == 1) {
		system("cls");
		goto loop;
	}
	else {
		cout << "* * * * �����ɹ�����ҵ����Ϣ����ϵͳ * *" << endl;
		system("pause");
		system("cls");
		Ownermenu();
	}
}
void changemenu() {//�޸��û���Ϣ�Ĳ˵�
	cout << "                          ******�û���Ϣ�޸�******" << endl;
	cout << "* 1.���� *" << endl;
	cout << "* 2.��ϵ��ʽ *" << endl;
	cout << "* 3.���֤�� *" << endl;
	cout << "* 4.��λ��� *" << endl;
	cout << "* 5.��λ���� *" << endl;
	cout << "* 6.ÿ��Ӧ������ҵ�� *" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "����������Ҫ�޸ĵ���Ϣǰ�ı�ţ�" << endl;
}
void revise() {//ҵ����Ϣ�޸�
	FILE* fp1;
	char rnum1[100];
	cout << "                    ******����������Ҫ�޸ĵ�ҵ�������ƺ�******" << endl;
	cout << "* ���������ƺţ�";
	cin >> rnum1;
loop1:
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char bui;
	Person head = new Node;
	head->next = NULL;
	Person q1 = new Node;
	q1 = head;
	Person p1 = NULL;
	Person  head2 = NULL;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
	while (fscanf(fp1, "%s %s %s %c %d %s %lf %d %s %lf %lf", name, tele, id, &bui, &hei, rnum, &sq, &number, ctype, &fee, &monfee) == 11) {
		p1 = new Node;
		strcpy(p1->name, name);
		strcpy(p1->telephone, tele);
		strcpy(p1->id, id);
		p1->house.building = bui;
		p1->house.storey = hei;
		strcpy(p1->house.roomnumber, rnum);
		p1->house.square = sq;
		p1->parking.parkingnumber = number;
		strcpy(p1->parking.parkingtype, ctype);
		p1->fee = fee;
		p1->monfee = monfee;
		if (strcmp(rnum, rnum1) == 0) {
			cout << "                       --����޸�ǰ��ҵ���ĸ�����Ϣ--" << endl << endl;
			cout << "* ������" << p1->name << "\t" << "* ��ϵ��ʽ��" << p1->telephone << "\t" << "* ���֤�ţ�" << p1->id << endl;
			cout << "--������Ϣ--" << endl;
			cout << "* ¥����" << p1->house.building << "\t" << "* ¥�㣺" << p1->house.storey << "\t" << "* ���ƺţ�" << p1->house.roomnumber << "\t" << "* �����" << p1->house.square << endl;
			cout << "--��λ��Ϣ--" << endl;
			cout << "* ��ţ�" << p1->parking.parkingnumber << "\t" << "* ���" << p1->parking.parkingtype << endl;
			cout << "--��ҵ����Ϣ--" << endl;
			cout << "* ��ҵ����" << p1->fee << "\t" << "* ÿ��Ӧ����ҵ�ѣ�" << p1->monfee << endl;
		}
		q1->next = p1;
		q1 = p1;
		q1->next = NULL;
	}
	fclose(fp1);
	head2 = head->next;
	changemenu();
	int choose;
	cin >> choose;
	if (choose == 1) {//�޸�����
		char na[100];
		cout << "--�������޸ĺ��������";
		cin >> na;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->name, na);
				cout << "�����޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 2) {//�޸���ϵ��ʽ
		char te[100];
		cout << "--�������޸ĺ����ϵ��ʽ��";
		cin >> te;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->telephone, te);
				cout << "��ϵ��ʽ�޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 3) {//�޸����֤��
		char idd[100];
		cout << "--�������޸ĺ�����֤�ţ�";
		cin >> idd;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->id, idd);
				cout << "���֤���޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 4) {//�޸ĳ�λ���
		int nu;;
		cout << "--�������޸ĺ�ĳ�λ��ţ�";
		cin >> nu;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				head2->parking.parkingnumber = nu;
				cout << "��λ����޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 5) {//�޸ĳ�λ����
		char ty[100];
		cout << "--�������޸ĺ�ĳ�λ���ͣ�";
		cin >> ty;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->parking.parkingtype, ty);
				head2->monfee = Payablefee(head2->house.square, ty, head2->house.storey);
				cout << "��λ�����޸ĳɹ�����" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	head2 = head->next;
	while (head2 != NULL) {
		if (strcmp(head2->house.roomnumber, rnum1) == 0) {
			cout << "                       --����޸ĺ��ҵ���ĸ�����Ϣ--" << endl;
			cout << "* ������" << head2->name << "\t" << "* ��ϵ��ʽ��" << head2->telephone << "\t" << "* ���֤�ţ�" << head2->id << endl;
			cout << "--������Ϣ--" << endl;
			cout << "* ¥����" << head2->house.building << "\t" << "* ¥�㣺" << head2->house.storey << "\t" << "* ���ƺţ�" << head2->house.roomnumber << "\t" << "* �����" << head2->house.square << endl;
			cout << "--��λ��Ϣ--" << endl;
			cout << "* ��ţ�" << head2->parking.parkingnumber << "\t" << "* ���" << head2->parking.parkingtype << endl;
			cout << "--��ҵ����Ϣ--" << endl;
			cout << "* ��ҵ����" << head2->fee << "\t" << "* ÿ��Ӧ����ҵ�ѣ�" << head2->monfee << endl;
		}
		head2 = head2->next;
	}
	head2 = head->next;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "w");
	while (head2 != NULL) {
		fprintf(fp1, "%s %s %s %c %d %s %.1lf %d %s %.1lf %.1lf\n", head2->name, head2->telephone, head2->id, head2->house.building, head2->house.storey, head2->house.roomnumber, head2->house.square, head2->parking.parkingnumber, head2->parking.parkingtype, head2->fee, head2->monfee);
		head2 = head2->next;
	}
	fclose(fp1);
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "---�Ƿ�����޸���Ϣ�����ǣ�����--1����������--0" << endl;
	int judg;
	cin >> judg;
	if (judg == 1) {
		system("cls");
		goto loop1;
	}
	else {
		cout << "------����ҵ����Ϣ����ϵͳ------" << endl;
		system("cls");
		Ownermenu();
	}
}
Node* Creatlist() {//������Ϣ����
	FILE* fp1;
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char bui;
	Person head = new Node;
	head->next = NULL;
	Person q1 = new Node;
	q1 = head;
	Person p1 = NULL;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
	while (fscanf(fp1, "%s %s %s %c %d %s %lf %d %s %lf %lf", name, tele, id, &bui, &hei, rnum, &sq, &number, ctype, &fee, &monfee) == 11) {
		p1 = new Node;
		strcpy(p1->name, name);
		strcpy(p1->telephone, tele);
		strcpy(p1->id, id);
		p1->house.building = bui;
		p1->house.storey = hei;
		strcpy(p1->house.roomnumber, rnum);
		p1->house.square = sq;
		p1->parking.parkingnumber = number;
		strcpy(p1->parking.parkingtype, ctype);
		p1->fee = fee;
		p1->monfee = monfee;
		q1->next = p1;
		q1 = p1;
	}
	q1->next = NULL;
	fclose(fp1);
	return head;
}
void deleteinfo() {//ҵ����Ϣɾ��
loop:
	Person head = new Node;
	head = Creatlist();
	Person p = head->next;
	cout << "                             * * * ԭҵ������Ϣ���� * * *" << endl;
	while (p) {
		cout << "* ������" << p->name << "\t " << "* ��ϵ��ʽ��" << p->telephone << "\t" << "* ���֤�ţ�" << p->id << "\t" << "* ���ƺţ�" << p->house.roomnumber << endl;
		p = p->next;
	}
	cout << "* * * * * ��ֱ���������Ҫɾ����ҵ�������������֤�ź����ƺ� * * * * *" << endl;
	char na[100], idd[100], rnumm[100];
	cout << "* ������������";
	cin >> na;
	cout << endl;
	cout << "* ���������֤�ţ�";
	cin >> idd;
	cout << endl;
	cout << "* ���������ƺţ�";
	cin >> rnumm;
	cout << endl;
	FILE* fp1;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "w");
	p = head->next;
	Person q = new Node;
	while (p) {
		if (strcmp(p->name, na) == 0 && strcmp(p->id, idd) == 0 && strcmp(p->house.roomnumber, rnumm) == 0) {
			p = p->next;
			if (p == NULL) {
				break;
			}
		}
		fprintf(fp1, "%s %s %s %c %d %s %.1lf %d %s %.1lf %.1lf\n", p->name, p->telephone, p->id, p->house.building, p->house.storey, p->house.roomnumber, p->house.square, p->parking.parkingnumber, p->parking.parkingtype, p->fee, p->monfee);
		p = p->next;
	}
	p = head->next;
	fclose(fp1);
	cout << "ҵ����Ϣɾ���ɹ�����" << endl;
	int jud;
	cout << "�Ƿ����ɾ�������ǣ���1�����񣩰�0" << endl;
	cin >> jud;
	if (jud == 1) {
		system("pause");
		system("cls");
		goto loop;
	}
	else {
		cout << "                               ------����ҵ����Ϣ����ϵͳ------" << endl;
		system("pause");
		system("cls");
		Ownermenu();
	}
}
void Getfee() {//������ҵ��
loop:
	Person head = new Node;
	head = Creatlist();
	Person p = head->next;
	FILE* fp1;
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char bui;
	char rnumm[100];
	double fe;
	int flag1 = 0;
	cout << "* ����������Ҫ������ҵ�ѵ����ƺţ�" << endl;
	cin >> rnumm;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "w");
	while (p) {
		if (strcmp(p->house.roomnumber, rnumm) == 0) {
			cout << "�����ڵ���ҵ�����Ϊ��" << p->fee << endl;
			cout << "����������Ҫ���ɵ���ҵ�ѣ�";
			cin >> fe;
			p->fee += fe;
			cout << "��ֵ�����ҵ�����Ϊ��" << p->fee << endl << endl;
			flag1 = 1;
		}
		fprintf(fp1, "%s %s %s %c %d %s %.1lf %d %s %.1lf %.1lf\n", p->name, p->telephone, p->id, p->house.building, p->house.storey, p->house.roomnumber, p->house.square, p->parking.parkingnumber, p->parking.parkingtype, p->fee, p->monfee);
		p = p->next;
	}
	fclose(fp1);
	if (flag1 == 0) {
		cout << endl;
		cout << "û�в鵽�����ƺŵ�ҵ������" << endl;
		cout << "�Ƿ�Ҫ�����������ƺţ����ǣ���1�����񣩰�0" << endl;
		int jud;
		cin >> jud;
		if (jud == 1) {
			goto loop;
		}
		else {
			cout << "                             ******������ҵ��Ϣ����ϵͳҳ��******" << endl;
		}
	}
	else {
		cout << "                            ******�����ɹ�������ҵ��Ϣ����ϵͳҳ��******" << endl;
	}
}
void Checkperson() {//��ѯ������Ϣ
loop:
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char name1[100], id1[100];
	char bui;
	FILE* fp;
	int flag = 0;
	fp = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
	cout << "* ����������Ҫ���ҵ�ҵ�������������֤�� *" << endl;
	cout << "* ������ҵ��������" << endl;
	cin >> name1;
	cout << "* ������ҵ�����֤�ţ�" << endl;
	cin >> id1;
	while (fscanf(fp, "%s %s %s %c %d %s %lf %d %s %lf %lf", name, tele, id, &bui, &hei, rnum, &sq, &number, ctype, &fee, &monfee) == 11) {
		if (strcmp(name, name1) == 0 && strcmp(id, id1) == 0) {
			cout << "           " << name1 << "�ĸ�����Ϣ������ʾ��" << endl;
			cout << "* ������" << name << "\t" << "* ��ϵ��ʽ��" << tele << "\t" << "* ���֤�ţ�" << id << endl << endl;
			cout << "* ������Ϣ��" << endl;
			cout << "* ¥���� " << bui << "\t" << "* ¥�㣺" << hei << "\t" << " * ���ƺţ�" << rnum << "\t" << " * �����" << sq << endl << endl;
			if (number == 0) {
				cout << "��ҵ���ĸ÷���û�г�λ��Ϣ�£���" << endl << endl;
			}
			else {
				cout << "* ��λ��Ϣ��" << endl;
				cout << "* ��ţ�" << number << "\t" << "* ���ͣ�" << ctype << endl << endl;
			}
			cout << "* ��ҵ����Ϣ��" << endl;
			cout << "* ÿ���������ҵ�ѣ�" << monfee << "\t" << "* ��ҵ����" << fee << endl;
			if (fee <= 0) {
				cout << "��Ҫ������ҵ������" << endl;
				cout << "�����Ҫ������ҵ�ѣ���ǰ����ҵ����Ϣ����ϵͳ��" << endl;
			}
			cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
			flag = 1;
		}
	}
	fclose(fp);
	if (flag == 1) {
		cout << "                              **********��ѯ�ɹ�����ͳ�Ʋ�ѯϵͳ**********" << endl;
		system("pause");
		system("cls");
		Statistical();
	}
	else {
		cout << "                            *****��ҵ�����Ǳ�С����ѽ����******" << endl;
		cout << "�Ƿ���Ҫ�������ң����ǣ���1�����񣩰�0" << endl;
		int jud;
		cin >> jud;
		if (jud == 1) {
			goto loop;
		}
		else {
			cout << "                              **********����ͳ�Ʋ�ѯϵͳ**********" << endl;
			system("pause");
			system("cls");
			Statistical();
		}
	}
}
void Payment() {//��ѯ�ɷ���Ϣ
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                            * * * * С������ҵ���շ��ƶ� * * * *" << endl << endl;
	cout << "* 1.����ÿƽ�����շ�2Ԫ/�£����Է��ݵ���ҵ��Ϊ�����ݵ����*2" << endl;
	cout << "* 2.��λÿ���µ��շѸ��ݳ�����𣬴��ͣ�120Ԫ/�£����ͣ�100Ԫ/�£�С�ͣ�80Ԫ/��" << endl;
	cout << "* 3.�ܵ���ҵ��=������ҵ��+��λ��ҵ��" << endl;
	cout << "* 4.ע�⣺һ¥ҵ������ҵ����Ҫ��Ϊ���4m^2��С��԰�ķ��ã�����0.5Ԫ/m^2�շ�" << endl;
	cout << "          ��¥����9¥��ҵ����Ҫ�������10m^2�ĸ�¥�ķ��ã�����1Ԫ/m^2�շ�" << endl << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                      -------------��ѯ�ɹ�����ͳ�Ʋ�ѯϵͳ-------------" << endl;
	system("pause");
	system("cls");
	Statistical();
}
void quickSort(HouseholeList houselist1, int low, int high, char ch) {//��������
	if (low < high) {
		int i = low;
		int j = high;
		Node p;
		p = houselist1[low];
		while (i < j) {
			while (i < j && p.house.building == ch && strcmp(p.house.roomnumber, houselist1[j].house.roomnumber) < 0) {
				j--;
			}
			swap(houselist[i], houselist[j]);
			while (i < j && p.house.building == ch && strcmp(p.house.roomnumber, houselist1[i].house.roomnumber) >= 0) {
				i++;
			}
			swap(houselist[i], houselist[j]);
		}
		quickSort(houselist1, low, i - 1, ch);
		quickSort(houselist1, i + 1, high, ch);
	}
	else {
		return;
	}
}
void CheckfeeBui() {//��ѯ��ҵ����Ϣ����������¥���ĵ�ס����һ¥����¥��,��������
	FILE* fp1;
loop1:
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char bui;
	int i;
	char ch;
	cout << "����������Ҫ��ѯ����ҵ����Ϣ��¥���ţ�" << endl;
	cin >> ch;
	if (ch == 'A') {
		i = 1;
		cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
		cout << "A��¥��ҵ������ҵ����Ϣ���£�" << endl << endl;
		fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
		while (fscanf(fp1, "%s %s %s %c %d %s %lf %d %s %lf %lf", name, tele, id, &bui, &hei, rnum, &sq, &number, ctype, &fee, &monfee) == 11) {
			if (bui == 'A') {
				strcpy(houselist[i].name, name);
				strcpy(houselist[i].telephone, tele);
				strcpy(houselist[i].id, id);
				houselist[i].house.building = bui;
				houselist[i].house.storey = hei;
				strcpy(houselist[i].house.roomnumber, rnum);
				houselist[i].house.square = sq;
				houselist[i].parking.parkingnumber = number;
				strcpy(houselist[i].parking.parkingtype, ctype);
				houselist[i].fee = fee;
				houselist[i].monfee = monfee;
				i++;
			}
		}
		total = i - 1;
		fclose(fp1);
		quickSort(houselist, 1, total, 'A');
		for (int j = 1; j <= total; j++) {
			if (houselist[j].house.building == 'A') {
				cout << "* ������" << houselist[j].name << "\t* ��ϵ��ʽ��" << houselist[j].telephone << " \t* ���֤�ţ�" << houselist[j].id << "\t* ���ƺţ�" << houselist[j].house.roomnumber << endl;
				cout << "* ��ҵ����" << houselist[j].fee << "\t* ÿ������ɵ���ҵ�ѣ�" << houselist[j].monfee << endl;
				cout << endl;
			}
		}
	}
	if (ch == 'B') {
		i = 1;
		cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
		cout << "B��¥��ҵ������ҵ����Ϣ���£�" << endl << endl;
		fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
		while (fscanf(fp1, "%s %s %s %c %d %s %lf %d %s %lf %lf", name, tele, id, &bui, &hei, rnum, &sq, &number, ctype, &fee, &monfee) == 11) {
			if (bui == 'B') {
				strcpy(houselist[i].name, name);
				strcpy(houselist[i].telephone, tele);
				strcpy(houselist[i].id, id);
				houselist[i].house.building = bui;
				houselist[i].house.storey = hei;
				strcpy(houselist[i].house.roomnumber, rnum);
				houselist[i].house.square = sq;
				houselist[i].parking.parkingnumber = number;
				strcpy(houselist[i].parking.parkingtype, ctype);
				houselist[i].fee = fee;
				houselist[i].monfee = monfee;
				i++;
			}
		}
		total = i - 1;
		fclose(fp1);
		quickSort(houselist, 1, total, 'B');
		for (int j = 1; j <= total; j++) {
			if (houselist[j].house.building == 'B') {
				cout << "* ������" << houselist[j].name << "\t* ��ϵ��ʽ��" << houselist[j].telephone << " \t* ���֤�ţ�" << houselist[j].id << "\t* ���ƺţ�" << houselist[j].house.roomnumber << endl;
				cout << "* ��ҵ����" << houselist[j].fee << "\t* ÿ������ɵ���ҵ�ѣ�" << houselist[j].monfee << endl;
				cout << endl;
			}
		}
	}
	cout << "---�Ƿ�Ҫ������ѯ�����ǣ���1�����񣩰�0---" << endl;
	int jud;
	cin >> jud;
	if (jud == 1) {
		goto loop1;
	}
	else {
		cout << "        ********��ѯ�ɹ������ز�ѯ��ҵ����Ϣҳ��********" << endl;
		system("pause");
		system("cls");
		Checkfeemenu();
	}
}
HouseholeList holdlist = new Node[Maxsize];
void merge(int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int k = low;
	while (i <= mid && j <= high) {
		if (houselist[i].fee < houselist[j].fee) {
			holdlist[k++] = houselist[i++];
		}
		else {
			holdlist[k++] = houselist[j++];
		}
	}
	while (i <= mid) {
		holdlist[k++] = houselist[i++];
	}
	while (j <= high) {
		holdlist[k++] = houselist[j++];
	}
	for (int i = low; i <= high; i++) {
		houselist[i] = holdlist[i];
	}
}
void mergesort(int x, int y) {//�鲢����
	if (x >= y) return;
	int mid = (x + y) / 2;
	mergesort(x, mid);
	mergesort(mid + 1, y);
	merge(x, mid, y);
}
void CheckfeeFe() {//��ѯ��ҵ����Ϣ��������ҵ�������򣩣��鲢����
	Enterinfo();
	mergesort(1, total);
	cout << "                            ----ȫ��ס������ҵ����Ϣ����----" << endl << endl;
	for (int i = 1; i <= total; i++) {
		cout << "  *������" << houselist[i].name << "  *���֤�ţ�" << houselist[i].id << "  *���ƺţ�" << houselist[i].house.roomnumber;
		cout<<"  *��ҵ�ѽ�" << houselist[i].fee << "  *ÿ��Ӧ������ҵ�ѣ�" << houselist[i].monfee << endl;
	}
	cout << "      * * * ��ѯ�ɹ����ز�ѯ��ҵ����Ϣҳ��!! * * *" << endl;
	system("pause");
	system("cls");
	Checkfeemenu();
}
void HeapAdjust(int s, int m) {
	Node temp;
	temp = houselist[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m&& strcmp(houselist[j].name, houselist[j + 1].name) < 0) {
			j++;
		}
		if (strcmp(temp.name, houselist[j].name) >= 0) {
			break;
		}
		houselist[s] = houselist[j];
		s = j;
	}
	houselist[s] = temp;
}
void HeapSort() {//�����򣨴󶥶ѣ�
	for (int i = total / 2; i > 0; i--) {
		HeapAdjust(i, total);
	}
	for (int i = total; i > 1; i--) {
		swap(houselist[i], houselist[1]);
		HeapAdjust(1, i - 1);
	}
}
void CheckfeeRnum() {//��ѯ��ҵ����Ϣ�������������ַ��������򣩣�������
	Enterinfo();
	HeapSort();
	for (int i = 1; i <= total; i++) {
		cout << "*������" << houselist[i].name << "\t*��ϵ��ʽ��" << houselist[i].telephone << "\t*���֤�ţ�" << houselist[i].id << endl;
		cout << "*¥����" << houselist[i].house.building << "\t*¥�㣺" << houselist[i].house.storey << "\t*���ƺţ�" << houselist[i].house.roomnumber << "\t*�����" << houselist[i].house.square << endl;
		cout << "*��λ��ţ�" << houselist[i].parking.parkingnumber << "\t*��λ���" << houselist[i].parking.parkingtype << "\t*��ҵ����" << houselist[i].fee << "\t*ÿ��Ӧ����ҵ�ѣ�" << houselist[i].monfee << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "      * * * ��ѯ�ɹ����ز�ѯ��ҵ����Ϣҳ��!! * * *" << endl;
	system("pause");
	system("cls");
	Checkfeemenu();
}
void Password() {//�����ж�
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "              * *Ϊ��֤С����ס������Ϣ��ȫ���������˺ź������¼Ŷ��* *" << endl << endl;
	string account1, key1;
	account1 = "SAU123456";
	key1 = "5892718";
loop1:
	string account2, key2;
	cout << "* �����������˺ţ�" << endl << endl;
	cin >> account2;
	cout << "* �������������룺" << endl << endl;
	cin >> key2;
	if (account2 == account1 && key2 == key1) {
		cout << "�˺ź�������ȷ�����ɹ�����ϵͳ��" << endl;
		system("pause");
		system("cls");
		Showmenu();
	}
	else {
		cout << "�˺Ż������������" << endl;
		cout << "�Ƿ�Ҫ�������룬���ǣ���1�����񣩰�0" << endl;
		int jud;
		cin >> jud;
		if (jud == 1) {
			goto loop1;
		}
		else {
			cout << "�ڴ������´ν��룡����" << endl;
			exit(0);
		}
	}
}
void Heart() {
	float x, y, a;//����xiu����
	for (y = 1.5; y > -1.5; y -= 0.1)
	{
		for (x = -1.5; x < 1.5; x += 0.05)
		{
			a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
		}
		system("color f4");
		putchar('\n');
	}
}
int main() {
	system("color f0");
	//deductfee();
	Password();
	return 0;
}
