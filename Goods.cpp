#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Goods.h"
#include <fstream>
using namespace std;
// Goods::Goods(const char* name, const char* date, double cost, int amount)
	//Конструктор класса Goods c параметрами
	//Создает объект
	//args: 
	// - const char* name -- имя товара, - const char* name -- дата товара, 
	// - double cost -- стоимость товара, - int amount -- количество товара. 

Goods::Goods(const char* name, int day, int month, int year, double cost, int amount) {
	this->name = new char;
	this->name = _strdup(name);
	this->day = day;
	this->month = month;
	this->year = year;
	this->cost = cost;
	this->amount = amount;
}

// Goods::Goods () 
	//Стандартный конструктор класса Goods
	//Создает объект

Goods::Goods() {
	name = NULL;
	day = 1;
	month = 1;
	year = 1970;
	amount = 0;
	cost = 0;
}

// void Goods::setName(const char* newname)
	//Установка имени товару
	//args: 
	//- const char* newname -- новое имя товара 

void Goods::setName(const char* newname) {
	int len = 0;
	len = strlen(name);
	name = new char[len + 1];
	strcpy(name, newname);
}

// void Goods::setDate(const char* newdate)
	//Установка даты товару
	//args: 
	//- const char* newdate -- новая дата товара 
void Goods::setDate(int _day, int _month, int _year) {
	try {
	if (((_day > 0) && (_day < 32)) && ((_month > 0) && (_month < 13)) && ((_year > 0) && (_year < 2147483648))) {
		day = _day;
		month = _month;
		year = _year;
		}
	else {
		throw "Can't set minus or zero date";
		}
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}


//char* Goods::getName()
	//Проверка имени товара
	//возврат - имени

char* Goods::getName() { //Получить имя
	return name;
}

//char* Goods::getName()
	//Получение даты товара
	//возврат - даты

int Goods::getDay() { //Получить дату
	return day;
}

int Goods::getMonth() { //Получить дату
	return month;
}

int Goods::getYear() { //Получить дату
	return year;
}
int Goods::getMaxAmount() {
	return MAX_AMOUNT;
}




//Goods::Goods(const Goods& good)
	//Конструктор копирования
	//args:
	// - const Goods& good -- объект, с которого снимается копия

Goods::Goods(const Goods& good) {
	if (good.name) {
		name = new char[strlen(good.name) + 1];
		strcpy(name, good.name);
	}
	else name = (char*)"Noname";
	day = good.day;
	month = good.month;
	year = good.year;
	cost = good.cost;
	amount = good.amount;
}

const int Goods::MAX_AMOUNT = 100; //Присваивает статической константе значение 100 (максимальное количество товаров)

//void Goods::setMarkup(int money)
	//добавить наценку к стоимости товара
	//args:
	// - int money -- наценка к стоимости товара
void Goods::setMarkup(int money) {
	cost += money;
}

//void Goods::setMarkup(int money)
	//уменьшить стоимость товара
	//args:
	// - int money -- уценка к стоимости товара

void Goods::setMarkdown(int money) {
	cost -= money;
}

//void Goods::setCost(double _cost)
	//Установить стоимость товара
	//args:
	// - double _cost -- новая стоимость товара

void Goods::setCost(double _cost) {
	try {
	if (_cost >= 0) {
		cost = _cost;
		}
	else {
		throw "Can't set minus cost";
		}
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}

//double Goods::getCost()
	//Узнать стоимость товара
	//возврат - стоимости

double Goods::getCost() {
	return cost;
}

//void Goods::setAmount(int _amount)
	//Установить количество товара
	//args:
	// - int _amount -- новое количество товара

void Goods::setAmount(int _amount) {
	try {
	if (_amount >= 0) {
		amount = _amount;
		}
	else {
		throw "Can't set minus amount";
		}
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}

//void Goods::setReceive(int good)
	//Добавить количества товара
	//args:
	// - int good -- на какое количество добавить товара

void Goods::setReceive(int good) {

	amount += good;
}

//void Goods::setPercentage(double percentage)
	//Изменить наценку товара (в процентном соотношении)
	//args:
	// - double percentage -- на какой процент изменить цену товара

void Goods::setPercentage(double percentage) {
	try {
	if (percentage >= 0.0) 
		cost = double(cost) * (percentage / 100); //throw "You can't make negative percentage";
	else 
		throw "You can't make negative percentage";	
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}

//void Goods::setSell(int good)
	//Сколько продано товара
	//args:
	// - int good -- сколько товара продано

void Goods::setSell(int good) {
	try {
	if (good <= MAX_AMOUNT) {
		amount -= good;
		}
	else {
		throw "It isn`t allowed to sell greater than 100 per once";
		}
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}

//int Goods::getAmount()
	//Узнать количество товара
	//возврат - количства

int Goods::getAmount() {
	return amount;
}

//char* Goods::strObj()
	//Вывести всю информацию о товаре
	//возврат - строчное представление

char* Goods::strObj() {
	char* name;
	name = getName();

	char buffer1[16];
	int a = getDay();
	sprintf(buffer1, "%d", a);

	char buffer2[16];
	int b = getMonth();
	sprintf(buffer2, "%d", b);

	char buffer3[16];
	int c = getYear();
	sprintf(buffer3, "%d", c);

	char buffer4[16];
	int i = getCost();
	sprintf(buffer4, "%d", i);

	char buffer5[16];
	int j = getAmount();
	sprintf(buffer5, "%d", j);

	const char* day = buffer1;
	const char* month = buffer2;
	const char* year = buffer3;
	const char* cost = buffer4;
	const char* amount = buffer5;
	int len = 32;
	char* string = new char[len + 1];
	sprintf(string, "%s %s %s %s %s %s", name, day, month, year, cost, amount);
	return string;
}

// Bankomat::~Bankomat()
	//Деструктор класса
	//Удаляет динамическую информацию объекта

Goods::~Goods() {
	delete[] name;
}

// void Goods::operator+=(int good)
	//Перегрузка присвоения количества товара
	//Вызывает функцию присвоения товара

void Goods::operator+=(int good) {
	setReceive(good);
}

// void Goods::operator-=(int good)
	//Перегрузка уменьшения количества товара
	//Вызывает функцию продажи количества товара

void Goods::operator-=(int good) {
	setSell(good);
}

// Goods::operator double()
	//Перегрузка присвоения типа double - к стоимости
	//Возвращает значение стоимости в double

Goods::operator double() {
	return cost;
}

// Goods& Goods::operator++ ()
	//Перегрузка инкремента ко дню
	//Возвращает указатель на день


Goods& Goods::operator++ () {
	day++;
	return *this;
}

// Goods& Goods::operator-- ()
	//Перегрузка декремента ко дню
	//Возвращает указатель на день

Goods& Goods::operator--() {
	day--;
	return *this;
}

// Goods& Goods::operator = (const Goods& good)
	//Перегрузка присвоения
	//Возвращает указатель на товар


Goods& Goods::operator = (const Goods& good) {

	if (&good == this) {
		return *this;
	}
	if (good.name) {
		name = new char[strlen(good.name) + 1];
		strcpy(name, good.name);
	}
	else name = (char*)"Noname";
	day = good.day;
	month = good.month;
	year = good.year;
	cost = good.cost;
	amount = good.amount;
	return *this;
}
int lineAmount(ifstream& in) {
	int i = 0;
	const int N = 1024;
	char* str = new char[N];
	while (!in.eof()) {
		in.getline(str, N, '\n');
		i++;
	}
	delete[] str;
	in.clear();
	in.seekg(0);
	return i - 1; //that`s cuz last line is always \n
}
ostream& operator << (ostream& os, Goods& good) {
	os << good.name << " "  << good.day << " " << good.month << " " << good.year << " " << good.cost << " " << good.amount << " " << good.MAX_AMOUNT;
	return os;
	}
istream& operator >> (istream& is, Goods& good) {
	if (good.name != NULL) {
		delete[] good.name;
	}

	good.name = new char[16];
	is >> good.name >> good.day >> good.month >> good.year >> good.cost >> good.amount; // MAX_AMOUNT is const, can`t be written
	return is;
}
void Goods::toTxt(ofstream& out) {
	out << *this << '\n';
}
Goods* Goods::outTxt(ifstream& in) {
	Goods* good = new Goods;
	int N = lineAmount(in);
	good = new Goods[N];
	for (int i = 0; i < N; i++) {
		in >> good[i];
		in.seekg(sizeof(good->getMaxAmount()), ios::cur); //seek for sizeof MAX_AMOUNT (can`t be written) + 1 byte for space + 1 byte for \n
	}
	return good;
}
void Goods::toBin(fstream& out) {
	char* memBlockId = (char*)name;
	int lenIdArr = 2;
	char* lenId = new char[lenIdArr];
	lenId[0] = strlen(name) + '0';
	lenId[1] = '\0';
	out.write(lenId, sizeof(lenId));
	out.write(memBlockId, strlen(memBlockId));
	out.write((char*)& day, sizeof(day));
	out.write((char*)& month, sizeof(month));
	out.write((char*)& year, sizeof(year));
	out.write((char*)& cost, sizeof(cost));
	out.write((char*)& amount, sizeof(amount));
	out.write((char*)& MAX_AMOUNT, sizeof(MAX_AMOUNT));
}
Goods* Goods::outBin(fstream& in) {
	char* lenId = new char[2];
	int lenIdArr = 2;
	lenId[1] = '\0';
	int fileSz = 5;
	Goods* good = new Goods[5];
	for (int i = 0; i < 5; ++i) {
		in.read(lenId, sizeof(lenId));
		int strSize = lenId[0] - '0';
		char* memblock = new char[strSize];
		in.read(memblock, strSize);
		memblock[strSize] = '\0';
		in.read((char*)&good[i].day, sizeof(day));
		in.read((char*)& good[i].month, sizeof(month));
		in.read((char*)& good[i].year, sizeof(year));
		in.read((char*)& good[i].cost, sizeof(cost));
		in.read((char*)& good[i].amount, sizeof(amount));
		in.seekg(sizeof(MAX_AMOUNT), ios::cur);
		good[i].name = memblock;
	}
	return good;
}