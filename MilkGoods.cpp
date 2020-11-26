#define _CRT_SECURE_NO_WARNINGS
#include "MilkGoods.h"

// MilkGoods::MilkGoods(const char* milktype, int milkday, int milkmonth, int milkyear, const char* name, int day, int month, int year, double cost, int amount) : Goods(name,day,month,year,cost,amount)
	//Конструктор класса MilkGoods c параметрами
	//Создает объект, наследует от базового класса Goods остальные параметры
	//args: 
	// - const char* milktype -- тип товара (название), - int milkday -- день привоза товара, 
	// - int milkmonth -- месяц привоза товара, int milkyear -- год привоза товара
MilkGoods::MilkGoods(const char* milktype, int milkday, int milkmonth, int milkyear, const char* name, int day, int month, int year, double cost, int amount) : Goods(name,day,month,year,cost,amount)
{
	this->milktype = new char;
	this->milktype = _strdup(milktype);
	this->milkday = milkday;
	this->milkmonth = milkmonth;
	this->milkyear = milkyear;
}

// MilkGoods::MilkGoods()
	//Стандартный конструктор класса Goods
	//Создает объект

MilkGoods::MilkGoods() {
	milktype = NULL;
	milkday = 1;
	milkday = 1;
	milkday = 1970;
}
//MilkGoods::MilkGoods(const Goods& good)
	//Конструктор копирования
	//args:
	// - const MilkGoods& good -- объект, с которого снимается копия

MilkGoods::MilkGoods(const MilkGoods& good) {
	if (good.milktype) {
		name = new char[strlen(good.milktype) + 1];
		strcpy(milktype, good.milktype);
	}
	else milktype = (char*)"Notype";
	milkday = good.milkday;
	milkmonth = good.milkmonth;
	milkyear = good.milkyear;
}

int MilkGoods::getMilkDay() { //Получить дату
	return milkday;
}

int MilkGoods::getMilkMonth() { //Получить месяцц
	return milkmonth;
}

int MilkGoods::getMilkYear() { //Получить год
	return milkyear;
}

//void MilkGoods::setMilkDate(int _day, int _month, int _year)
	//установить дату привоза товара
	//args:
	// - int _day -- день привоза, - int _month -- месяц привоза, - int _year -- год привоза
void MilkGoods::setMilkDate(int _day, int _month, int _year) {
	try {
	if (((_day > 0) && (_day < 32)) && ((_month > 0) && (_month < 13)) && ((_year > 0) && (_year < 2147483648))) {
		milkday = _day;
		milkmonth = _month;
		milkyear = _year;
		}
	else {
		throw "Can't set minus or zero date";
		}
	}
	catch (const char* ex) {
		std::cout << ex <<std::endl;
	}
}

//void MilkGoods::setType(const char* newtype)
	//установить дату привоза товара
	//args:
	// - const char* newtype -- установить тип товара

void MilkGoods::setType(const char* newtype) {
	int len = 0;
	len = strlen(newtype);
	milktype = new char[len + 1];
	strcpy(milktype, newtype);
}

//char* MilkGoods::getType()
	//получить тип товара

char* MilkGoods::getType(){
	return milktype;
}

//char* MilkGoods::strObj()
	//получить строковое представление о товаре

char* MilkGoods::strObj() {
	char* type;
	type = getType();

	char buffer1[16];
	int a = getMilkDay();
	sprintf(buffer1, "%d", a);

	char buffer2[16];
	int b = getMilkMonth();
	sprintf(buffer2, "%d", b);

	char buffer3[16];
	int c = getMilkYear();
	sprintf(buffer3, "%d", c);

	const char* milkday = buffer1;
	const char* milkmonth = buffer2;
	const char* milkyear = buffer3;
	int len = 32;
	char* string = new char[len + 1];
	sprintf(string, "%s %s %s %s %s", type, milkday, milkmonth, milkyear, Goods::strObj());
	return string;
}

//void MilkGoods::delay(int milkday, int day)
	//функция пересчёта стоимости товара по истечению срока годности
	//args:
	//int milkday -- день привоза, int day - день в магазине
void MilkGoods::delay(int milkday, int day){
	if (milkday<day) {
		setPercentage(50);
	}
}

//MilkGoods::~MilkGoods()
	//деструктор

MilkGoods::~MilkGoods()
{
	delete[] milktype;
}

