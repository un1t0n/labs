#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ChildGoods.h"

// ChildGoods::ChildGoods(const char* childtype, int age, const char* name, int day, int month, int year, double cost, int amount) : Goods(name,day,month,year,cost,amount)
	//����������� ������ ChildGoods c �����������
	//������� ������, ��������� �� �������� ������ Goods ��������� ���������
	//args: 
	// - const char* childtype -- ��� ������ (��������), - int age -- ���������� ���������

ChildGoods::ChildGoods(const char* childtype, int age, const char* name, int day, int month, int year, double cost, int amount) : Goods(name,day,month,year,cost,amount)
{
	this->childtype = new char;
	this->childtype = _strdup(childtype);
	this->age = age;
}

// ChildGoods::ChildGoods() 
	//����������� ����������� ������ Goods
	//������� ������

ChildGoods::ChildGoods() {
	childtype = NULL;
	age = 0;
}

//ChildGoods::ChildGoods(const ChildGoods& good)
	//����������� �����������
	//args:
	// - const ChildGoods& good -- ������, � �������� ��������� �����

ChildGoods::ChildGoods(const ChildGoods& good) {
	if (good.childtype) {
		childtype = new char[strlen(good.childtype) + 1];
		strcpy(childtype, good.childtype);
	}
	else childtype = (char*)"Notype";
	age = good.age;
}

//void ChildGoods::setAge(int _age)
	//���������� ���������� ���������
	//args:
	// - int _age --������� ���������� ���������
void ChildGoods::setAge(int _age) { //���������� ��������� ������
	try {
	if (_age >= 0) {
		age = _age;
		}
	else {
		throw "Can't set minus age";
		}
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}

//int ChildGoods::getAge()
	//�������� ���������� ���������

int ChildGoods::getAge() {
	return age;
}

//void ChildGoods::setType(const char* newtype)
	//���������� ��� ������
	//args:
	// - const char* newtype --������� ����

void ChildGoods::setType(const char* newtype) {
	int len = 0;
	len = strlen(newtype);
	childtype = new char[len + 1];
	strcpy(childtype, newtype);
}

//int ChildGoods::getAge()
	//�������� ���

char* ChildGoods::getType(){
	return childtype;
}

//char* ChildGoods::strObj()
	//�������� ��������� �������������

char* ChildGoods::strObj() {
	char* type;
	type = getType();
	char buffer1[16];
	int a = getAge();
	sprintf(buffer1, "%d", a);
	const char* age = buffer1;
	int len = 0;
	char* string = new char[len + 1];
	sprintf(string, "%s %s %s", type, age, Goods::strObj());
	return string;
}

//bool operator<=(const ChildGoods &good, int _age)
	//��������� �������� ���������� ���������
	//args:
	// - const ChildGoods &good -- �����, - int _age -- ������� ���������� ���������

bool operator<=(const ChildGoods &good, int _age)
{
    return good.age <= _age;
}

//ChildGoods::~ChildGoods(void)
	//����������

ChildGoods::~ChildGoods()
{
	delete[] childtype;
}
