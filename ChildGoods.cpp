#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ChildGoods.h"

// ChildGoods::ChildGoods(const char* childtype, int age, const char* name, int day, int month, int year, double cost, int amount) : Goods(name,day,month,year,cost,amount)
	// онструктор класса ChildGoods c параметрами
	//—оздает объект, наследует от базового класса Goods остальные параметры
	//args: 
	// - const char* childtype -- тип товара (название), - int age -- возрастна€ категори€

ChildGoods::ChildGoods(const char* childtype, int age, const char* name, int day, int month, int year, double cost, int amount) : Goods(name,day,month,year,cost,amount)
{
	this->childtype = new char;
	this->childtype = _strdup(childtype);
	this->age = age;
}

// ChildGoods::ChildGoods() 
	//—тандартный конструктор класса Goods
	//—оздает объект

ChildGoods::ChildGoods() {
	childtype = NULL;
	age = 0;
}

//ChildGoods::ChildGoods(const ChildGoods& good)
	// онструктор копировани€
	//args:
	// - const ChildGoods& good -- объект, с которого снимаетс€ копи€

ChildGoods::ChildGoods(const ChildGoods& good) {
	if (good.childtype) {
		childtype = new char[strlen(good.childtype) + 1];
		strcpy(childtype, good.childtype);
	}
	else childtype = (char*)"Notype";
	age = good.age;
}

//void ChildGoods::setAge(int _age)
	//”становить возрастную категорию
	//args:
	// - int _age --задание возрастной категории
void ChildGoods::setAge(int _age) { //”становить стоимость товара
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
	//получить возрастную категорию

int ChildGoods::getAge() {
	return age;
}

//void ChildGoods::setType(const char* newtype)
	//”становить тип товара
	//args:
	// - const char* newtype --задание типа

void ChildGoods::setType(const char* newtype) {
	int len = 0;
	len = strlen(newtype);
	childtype = new char[len + 1];
	strcpy(childtype, newtype);
}

//int ChildGoods::getAge()
	//получить тип

char* ChildGoods::getType(){
	return childtype;
}

//char* ChildGoods::strObj()
	//получить строковое представление

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
	//ѕрегрузка проверки возрастной категории
	//args:
	// - const ChildGoods &good -- товар, - int _age -- задание возрастной категории

bool operator<=(const ChildGoods &good, int _age)
{
    return good.age <= _age;
}

//ChildGoods::~ChildGoods(void)
	//деструктор

ChildGoods::~ChildGoods()
{
	delete[] childtype;
}
