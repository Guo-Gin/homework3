#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include <ctime>
#pragma warning(disable:4996)//编译时出现error C4996 解决方法
#define Maxsize 100
int total = 0;
typedef struct House {//房屋
	char roomnumber[Maxsize];//门牌号
	double square;//面积
	int storey;//楼层
	char building;//楼栋
};
typedef struct Parking {//车位
	int parkingnumber;//编号
	char parkingtype[Maxsize];//类别
};
typedef struct Node {//业主
	char name[Maxsize];//业主姓名
	char telephone[Maxsize];//业主联系方式
	char id[Maxsize];//业主身份证号
	House house;//房屋
	Parking parking;//车位
	double fee;//物业费余额
	double monfee;//每月需缴纳的物业费
	Node* next;
}*HouseholeList, * Person;
HouseholeList houselist = new Node[Maxsize];
void Showmenu();//展示总菜单
void Feemenu();//展示物业信息菜单
void Ownermenu();//业主信息管理菜单
void Statistical();//统计查询菜单
void Payment();//查询缴费信息
void Checkfeemenu();//查询物业费信息菜单
void Enterinfo();//导出业主信息
void add();//业主信息录入
void revise();//业主信息修改
void deleteinfo();//业主信息删除
void Getfee();//缴纳物业费
void Checkperson();//查询个人信息
void CheckfeeBui();//查询物业费信息（按照整个楼栋的的住户从一楼到顶楼）,快速排序
void CheckfeeFe();//查询物业费信息（按照物业费余额，升序），归并排序
void CheckfeeRnum();//查询物业费信息（按照姓名，字符串的升序），堆排序
void Heart();//爱心
void Showmenu() {//展示总菜单
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************欢迎进入小区物业费管理系统******************" << endl << endl;
	cout << "               * * * * * * * * * &此系统已开发如下业务供您选择& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.物业信息管理系统   *" << endl << endl;
	cout << "                                   * 2.统计查询系统       *" << endl << endl;
	cout << "                                   * 3.退出程序           *" << endl << endl;
	while (true) {
		cout << "请您输入您想要进入的系统前的编号：" << endl;
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
			cout << "成功退出系统！期待您再来哟！" << endl;
			Heart();
			exit(0);
		default:
			cout << "该业务还没有开发哟！请重新输入：" << endl;
			break;
		}
	}
}
void Feemenu() {//展示物业信息菜单
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************欢迎进入物业信息管理系统******************" << endl << endl;
	cout << "               * * * * * * * * * &此系统已开发如下业务供您选择& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.小区业主信息管理系统 *" << endl << endl;
	cout << "                                   * 2.缴纳物业费管理系统   *" << endl << endl;
	cout << "                                   * 3.返回主菜单           *" << endl << endl;
	cout << "                                   * 4.退出程序             *" << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "请您输入您想要进入的系统前的编号：" << endl;
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
		cout << "成功退出系统！期待您再来哟！" << endl;
		Heart();
		exit(0);
	}
}
void Ownermenu() {//业主信息管理菜单
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************欢迎进入业主信息管理系统******************" << endl << endl;
	cout << "               * * * * * * * * * &此系统已开发如下业务供您选择& * * * * * * * * *" << endl << endl;
	cout << "                                    * 1.业主信息录入 *" << endl << endl;
	cout << "                                    * 2.业主信息修改 *" << endl << endl;
	cout << "                                    * 3.业主信息删除 *" << endl << endl;
	cout << "                                    * 4.返回上层菜单 *" << endl << endl;
	cout << "                                    * 5.退出程序     *" << endl << endl;
	cout << "请您输入您想要进入的业务前的编号：" << endl;
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
		cout << "成功退出系统！期待您再来哟！" << endl;
		Heart();
		exit(0);
	}
}
void Statistical() {//统计查询菜单
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************欢迎进入统计查询系统******************" << endl << endl;
	cout << "               * * * * * * * * * &此系统已开发如下业务供您选择& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.查询缴费信息   *" << endl << endl;
	cout << "                                   * 2.查询个人信息   *" << endl << endl;
	cout << "                                   * 3.查询物业费信息 *" << endl << endl;
	cout << "                                   * 4.返回上层菜单   *" << endl << endl;
	cout << "                                   * 5.退出程序       *" << endl << endl;
	cout << "请您输入您想要进入的业务前的编号：" << endl;
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
		cout << "成功退出系统！期待您再来哟！" << endl;
		Heart();
		exit(0);
	}
}
void Checkfeemenu() {//查询物业费信息菜单
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                 ******************欢迎进入查询物业费信息系统******************" << endl << endl;
	cout << "               * * * * * * * * * &此系统已开发如下业务供您选择& * * * * * * * * *" << endl << endl;
	cout << "                                   * 1.按照楼栋以及门牌号查询 *" << endl << endl;
	cout << "                                   * 2.按照物业费余额查询     *" << endl << endl;
	cout << "                                   * 3.按照姓名查询           *" << endl << endl;
	cout << "                                   * 4.返回上层菜单           *" << endl << endl;
	cout << "                                   * 5.退出程序               *" << endl << endl;
	cout << "请您输入您想要进入的业务前的编号：" << endl;
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
		cout << "成功退出系统！期待您再来哟！" << endl;
		Heart();
		exit(0);
	}
}
void Enterinfo() {//导出业主信息
	FILE* fp1;
	int i = 1;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
	while (fscanf(fp1, "%s %s %s %c %d %s %lf %d %s %lf %lf", houselist[i].name, houselist[i].telephone, houselist[i].id, &houselist[i].house.building, &houselist[i].house.storey, houselist[i].house.roomnumber, &houselist[i].house.square, &houselist[i].parking.parkingnumber, houselist[i].parking.parkingtype, &houselist[i].fee, &houselist[i].monfee) == 11) {
		i++;
	}
	total = i - 1;
	fclose(fp1);
}
double Payablefee(double sq, char ty[], int hei) {//计算应缴纳的物业费
	double sum = 0;
	if (strcmp(ty, "#") == 0) {
		sum += 0;
	}
	else if (strcmp(ty, "小") == 0) {
		sum += 80;
	}
	else if (strcmp(ty, "中") == 0) {
		sum += 100;
	}
	else if (strcmp(ty, "大") == 0) {
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
void add() {//业主信息录入
	FILE* fp1;
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char name1[100], id1[100];
	char bui;
loop:
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "a+");
	cout << "******请分别输入您想要录入的业主的如下信息******" << endl;
	cout << "* 姓名：";
	cin >> name;
	cout << endl;
	cout << "* 联系方式：";
	cin >> tele;
	cout << endl;
	cout << "* 身份证号：";
	cin >> id;
	cout << endl;
	cout << "******请输入房屋信息******" << endl;
	cout << "* 楼栋：";
	cin >> bui;
	cout << endl;
	cout << "* 楼层：";
	cin >> hei;
	cout << endl;
	cout << "* 门牌号：";
	cin >> rnum;
	cout << endl;
	cout << "* 面积：";
	cin >> sq;
	cout << endl;
	cout << "******请输入车位信息******" << endl;
	cout << "--如果有车位信息，请按1，否则请按0--" << endl;
	int jud;
	cin >> jud;
	if (jud == 1) {
		cout << "* * * * 请输入如下信息 * * * *" << endl;
		cout << "* 编号：";
		cin >> number;
		cout << endl;
		cout << "* 类别：";
		cin >> ctype;
		cout << endl;
	}
	else {
		number = 0;
		strcpy(ctype, "#");
	}
	cout << "* 物业费余额：";
	cin >> fee;
	cout << endl;
	monfee = Payablefee(sq, ctype, hei);
	cout << "* 由以上信息可得每月需缴纳物业费为：" << monfee << endl;
	fprintf(fp1, "%s %s %s %c %d %s %.1lf %d %s %.1lf %.1lf\n", name, tele, id, bui, hei, rnum, sq, number, ctype, fee, monfee);
	fclose(fp1);
	cout << "添加成功!!" << endl;
	cout << "是否继续添加，（是）按1，（否）按0" << endl;
	int jude;
	cin >> jude;
	if (jude == 1) {
		system("cls");
		goto loop;
	}
	else {
		cout << "* * * * 操作成功返回业主信息管理系统 * *" << endl;
		system("pause");
		system("cls");
		Ownermenu();
	}
}
void changemenu() {//修改用户信息的菜单
	cout << "                          ******用户信息修改******" << endl;
	cout << "* 1.姓名 *" << endl;
	cout << "* 2.联系方式 *" << endl;
	cout << "* 3.身份证号 *" << endl;
	cout << "* 4.车位编号 *" << endl;
	cout << "* 5.车位类型 *" << endl;
	cout << "* 6.每月应缴纳物业费 *" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "请输入您想要修改的信息前的编号：" << endl;
}
void revise() {//业主信息修改
	FILE* fp1;
	char rnum1[100];
	cout << "                    ******请输入您想要修改的业主的门牌号******" << endl;
	cout << "* 请输入门牌号：";
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
			cout << "                       --输出修改前的业主的各项信息--" << endl << endl;
			cout << "* 姓名：" << p1->name << "\t" << "* 联系方式：" << p1->telephone << "\t" << "* 身份证号：" << p1->id << endl;
			cout << "--房屋信息--" << endl;
			cout << "* 楼栋：" << p1->house.building << "\t" << "* 楼层：" << p1->house.storey << "\t" << "* 门牌号：" << p1->house.roomnumber << "\t" << "* 面积：" << p1->house.square << endl;
			cout << "--车位信息--" << endl;
			cout << "* 编号：" << p1->parking.parkingnumber << "\t" << "* 类别：" << p1->parking.parkingtype << endl;
			cout << "--物业费信息--" << endl;
			cout << "* 物业费余额：" << p1->fee << "\t" << "* 每月应缴物业费：" << p1->monfee << endl;
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
	if (choose == 1) {//修改姓名
		char na[100];
		cout << "--请输入修改后的姓名：";
		cin >> na;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->name, na);
				cout << "姓名修改成功！！" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 2) {//修改联系方式
		char te[100];
		cout << "--请输入修改后的联系方式：";
		cin >> te;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->telephone, te);
				cout << "联系方式修改成功！！" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 3) {//修改身份证号
		char idd[100];
		cout << "--请输入修改后的身份证号：";
		cin >> idd;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->id, idd);
				cout << "身份证号修改成功！！" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 4) {//修改车位编号
		int nu;;
		cout << "--请输入修改后的车位编号：";
		cin >> nu;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				head2->parking.parkingnumber = nu;
				cout << "车位编号修改成功！！" << endl;
				system("pause");
				system("cls");
				break;
			}
			head2 = head2->next;
		}
	}
	if (choose == 5) {//修改车位类型
		char ty[100];
		cout << "--请输入修改后的车位类型：";
		cin >> ty;
		while (head2 != NULL) {
			if (strcmp(head2->house.roomnumber, rnum1) == 0) {
				strcpy(head2->parking.parkingtype, ty);
				head2->monfee = Payablefee(head2->house.square, ty, head2->house.storey);
				cout << "车位类型修改成功！！" << endl;
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
			cout << "                       --输出修改后的业主的各项信息--" << endl;
			cout << "* 姓名：" << head2->name << "\t" << "* 联系方式：" << head2->telephone << "\t" << "* 身份证号：" << head2->id << endl;
			cout << "--房屋信息--" << endl;
			cout << "* 楼栋：" << head2->house.building << "\t" << "* 楼层：" << head2->house.storey << "\t" << "* 门牌号：" << head2->house.roomnumber << "\t" << "* 面积：" << head2->house.square << endl;
			cout << "--车位信息--" << endl;
			cout << "* 编号：" << head2->parking.parkingnumber << "\t" << "* 类别：" << head2->parking.parkingtype << endl;
			cout << "--物业费信息--" << endl;
			cout << "* 物业费余额：" << head2->fee << "\t" << "* 每月应缴物业费：" << head2->monfee << endl;
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
	cout << "---是否继续修改信息，（是）输入--1，（否）输入--0" << endl;
	int judg;
	cin >> judg;
	if (judg == 1) {
		system("cls");
		goto loop1;
	}
	else {
		cout << "------返回业主信息管理系统------" << endl;
		system("cls");
		Ownermenu();
	}
}
Node* Creatlist() {//创建信息链表
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
void deleteinfo() {//业主信息删除
loop:
	Person head = new Node;
	head = Creatlist();
	Person p = head->next;
	cout << "                             * * * 原业主的信息如下 * * *" << endl;
	while (p) {
		cout << "* 姓名：" << p->name << "\t " << "* 联系方式：" << p->telephone << "\t" << "* 身份证号：" << p->id << "\t" << "* 门牌号：" << p->house.roomnumber << endl;
		p = p->next;
	}
	cout << "* * * * * 请分别输入您想要删除的业主的姓名、身份证号和门牌号 * * * * *" << endl;
	char na[100], idd[100], rnumm[100];
	cout << "* 请输入姓名：";
	cin >> na;
	cout << endl;
	cout << "* 请输入身份证号：";
	cin >> idd;
	cout << endl;
	cout << "* 请输入门牌号：";
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
	cout << "业主信息删除成功！！" << endl;
	int jud;
	cout << "是否继续删除，（是）按1，（否）按0" << endl;
	cin >> jud;
	if (jud == 1) {
		system("pause");
		system("cls");
		goto loop;
	}
	else {
		cout << "                               ------返回业主信息管理系统------" << endl;
		system("pause");
		system("cls");
		Ownermenu();
	}
}
void Getfee() {//缴纳物业费
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
	cout << "* 请输入您想要缴纳物业费的门牌号：" << endl;
	cin >> rnumm;
	fp1 = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "w");
	while (p) {
		if (strcmp(p->house.roomnumber, rnumm) == 0) {
			cout << "您现在的物业费余额为：" << p->fee << endl;
			cout << "请输入您想要缴纳的物业费：";
			cin >> fe;
			p->fee += fe;
			cout << "充值后的物业费余额为：" << p->fee << endl << endl;
			flag1 = 1;
		}
		fprintf(fp1, "%s %s %s %c %d %s %.1lf %d %s %.1lf %.1lf\n", p->name, p->telephone, p->id, p->house.building, p->house.storey, p->house.roomnumber, p->house.square, p->parking.parkingnumber, p->parking.parkingtype, p->fee, p->monfee);
		p = p->next;
	}
	fclose(fp1);
	if (flag1 == 0) {
		cout << endl;
		cout << "没有查到此门牌号的业主！！" << endl;
		cout << "是否要重新输入门牌号，（是）按1，（否）按0" << endl;
		int jud;
		cin >> jud;
		if (jud == 1) {
			goto loop;
		}
		else {
			cout << "                             ******返回物业信息管理系统页面******" << endl;
		}
	}
	else {
		cout << "                            ******操作成功返回物业信息管理系统页面******" << endl;
	}
}
void Checkperson() {//查询个人信息
loop:
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char name1[100], id1[100];
	char bui;
	FILE* fp;
	int flag = 0;
	fp = fopen("D:\\adatafile\\My Code collection\\devcode\\data.txt", "r");
	cout << "* 请输入您想要查找的业主的姓名和身份证号 *" << endl;
	cout << "* 请输入业主姓名：" << endl;
	cin >> name1;
	cout << "* 请输入业主身份证号：" << endl;
	cin >> id1;
	while (fscanf(fp, "%s %s %s %c %d %s %lf %d %s %lf %lf", name, tele, id, &bui, &hei, rnum, &sq, &number, ctype, &fee, &monfee) == 11) {
		if (strcmp(name, name1) == 0 && strcmp(id, id1) == 0) {
			cout << "           " << name1 << "的个人信息如下所示：" << endl;
			cout << "* 姓名：" << name << "\t" << "* 联系方式：" << tele << "\t" << "* 身份证号：" << id << endl << endl;
			cout << "* 房屋信息：" << endl;
			cout << "* 楼栋： " << bui << "\t" << "* 楼层：" << hei << "\t" << " * 门牌号：" << rnum << "\t" << " * 面积：" << sq << endl << endl;
			if (number == 0) {
				cout << "该业主的该房子没有车位信息奥！！" << endl << endl;
			}
			else {
				cout << "* 车位信息：" << endl;
				cout << "* 编号：" << number << "\t" << "* 类型：" << ctype << endl << endl;
			}
			cout << "* 物业费信息：" << endl;
			cout << "* 每月需缴纳物业费：" << monfee << "\t" << "* 物业费余额：" << fee << endl;
			if (fee <= 0) {
				cout << "需要缴纳物业费啦！" << endl;
				cout << "如果想要缴纳物业费，请前往物业费信息管理系统！" << endl;
			}
			cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
			flag = 1;
		}
	}
	fclose(fp);
	if (flag == 1) {
		cout << "                              **********查询成功返回统计查询系统**********" << endl;
		system("pause");
		system("cls");
		Statistical();
	}
	else {
		cout << "                            *****该业主不是本小区的呀！！******" << endl;
		cout << "是否想要继续查找，（是）按1，（否）按0" << endl;
		int jud;
		cin >> jud;
		if (jud == 1) {
			goto loop;
		}
		else {
			cout << "                              **********返回统计查询系统**********" << endl;
			system("pause");
			system("cls");
			Statistical();
		}
	}
}
void Payment() {//查询缴费信息
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                            * * * * 小区的物业费收费制度 * * * *" << endl << endl;
	cout << "* 1.房屋每平方米收费2元/月，所以房屋的物业费为：房屋的面积*2" << endl;
	cout << "* 2.车位每个月的收费根据车的类别，大型：120元/月；中型：100元/月；小型：80元/月" << endl;
	cout << "* 3.总的物业费=房屋物业费+车位物业费" << endl;
	cout << "* 4.注意：一楼业主的物业费需要额为添加4m^2的小花园的费用，按照0.5元/m^2收费" << endl;
	cout << "          顶楼（即9楼）业主需要额外添加10m^2的阁楼的费用，按照1元/m^2收费" << endl << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "                      -------------查询成功返回统计查询系统-------------" << endl;
	system("pause");
	system("cls");
	Statistical();
}
void quickSort(HouseholeList houselist1, int low, int high, char ch) {//快速排序
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
void CheckfeeBui() {//查询物业费信息（按照整个楼栋的的住户从一楼到顶楼）,快速排序
	FILE* fp1;
loop1:
	char name[100], tele[100], id[100], rnum[100], ctype[100];
	double sq, fee, monfee;
	int hei, number;
	char bui;
	int i;
	char ch;
	cout << "请输入您想要查询的物业费信息的楼栋号：" << endl;
	cin >> ch;
	if (ch == 'A') {
		i = 1;
		cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
		cout << "A栋楼的业主的物业费信息如下：" << endl << endl;
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
				cout << "* 姓名：" << houselist[j].name << "\t* 联系方式：" << houselist[j].telephone << " \t* 身份证号：" << houselist[j].id << "\t* 门牌号：" << houselist[j].house.roomnumber << endl;
				cout << "* 物业费余额：" << houselist[j].fee << "\t* 每月需缴纳的物业费：" << houselist[j].monfee << endl;
				cout << endl;
			}
		}
	}
	if (ch == 'B') {
		i = 1;
		cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
		cout << "B栋楼的业主的物业费信息如下：" << endl << endl;
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
				cout << "* 姓名：" << houselist[j].name << "\t* 联系方式：" << houselist[j].telephone << " \t* 身份证号：" << houselist[j].id << "\t* 门牌号：" << houselist[j].house.roomnumber << endl;
				cout << "* 物业费余额：" << houselist[j].fee << "\t* 每月需缴纳的物业费：" << houselist[j].monfee << endl;
				cout << endl;
			}
		}
	}
	cout << "---是否要继续查询，（是）按1，（否）按0---" << endl;
	int jud;
	cin >> jud;
	if (jud == 1) {
		goto loop1;
	}
	else {
		cout << "        ********查询成功！返回查询物业费信息页面********" << endl;
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
void mergesort(int x, int y) {//归并排序
	if (x >= y) return;
	int mid = (x + y) / 2;
	mergesort(x, mid);
	mergesort(mid + 1, y);
	merge(x, mid, y);
}
void CheckfeeFe() {//查询物业费信息（按照物业费余额，升序），归并排序
	Enterinfo();
	mergesort(1, total);
	cout << "                            ----全部住户的物业费信息如下----" << endl << endl;
	for (int i = 1; i <= total; i++) {
		cout << "  *姓名：" << houselist[i].name << "  *身份证号：" << houselist[i].id << "  *门牌号：" << houselist[i].house.roomnumber;
		cout<<"  *物业费金额：" << houselist[i].fee << "  *每月应缴纳物业费：" << houselist[i].monfee << endl;
	}
	cout << "      * * * 查询成功返回查询物业费信息页面!! * * *" << endl;
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
void HeapSort() {//堆排序（大顶堆）
	for (int i = total / 2; i > 0; i--) {
		HeapAdjust(i, total);
	}
	for (int i = total; i > 1; i--) {
		swap(houselist[i], houselist[1]);
		HeapAdjust(1, i - 1);
	}
}
void CheckfeeRnum() {//查询物业费信息（按照姓名，字符串的升序），堆排序
	Enterinfo();
	HeapSort();
	for (int i = 1; i <= total; i++) {
		cout << "*姓名：" << houselist[i].name << "\t*联系方式：" << houselist[i].telephone << "\t*身份证号：" << houselist[i].id << endl;
		cout << "*楼栋：" << houselist[i].house.building << "\t*楼层：" << houselist[i].house.storey << "\t*门牌号：" << houselist[i].house.roomnumber << "\t*面积：" << houselist[i].house.square << endl;
		cout << "*车位编号：" << houselist[i].parking.parkingnumber << "\t*车位类别：" << houselist[i].parking.parkingtype << "\t*物业费余额：" << houselist[i].fee << "\t*每月应缴物业费：" << houselist[i].monfee << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "      * * * 查询成功返回查询物业费信息页面!! * * *" << endl;
	system("pause");
	system("cls");
	Checkfeemenu();
}
void Password() {//密码判定
	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "              * *为保证小区内住户的信息安全，请输入账号和密码登录哦！* *" << endl << endl;
	string account1, key1;
	account1 = "SAU123456";
	key1 = "5892718";
loop1:
	string account2, key2;
	cout << "* 请输入您的账号：" << endl << endl;
	cin >> account2;
	cout << "* 请输入您的密码：" << endl << endl;
	cin >> key2;
	if (account2 == account1 && key2 == key1) {
		cout << "账号和密码正确！！成功进入系统！" << endl;
		system("pause");
		system("cls");
		Showmenu();
	}
	else {
		cout << "账号或密码输入错误！" << endl;
		cout << "是否要重新输入，（是）按1，（否）按0" << endl;
		int jud;
		cin >> jud;
		if (jud == 1) {
			goto loop1;
		}
		else {
			cout << "期待您的下次进入！！！" << endl;
			exit(0);
		}
	}
}
void Heart() {
	float x, y, a;//创建xiu心心
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
