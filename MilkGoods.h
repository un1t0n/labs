#ifndef _MilkdGoods_h
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "goods.h"
class MilkGoods :
	public Goods
{
public:
	MilkGoods();
	~MilkGoods();
	MilkGoods(const char* type, int milkday, int milkmonth, int milkyear, const char* name, int day, int month, int year, double cost, int amount);
	MilkGoods(const MilkGoods& good); //Конструктор копирования
	void setType(const char* newtype);
	void setMilkday(int _day);
	void setMilkYonth(int _month);
	void setMilkYear(int _year);
	int getMilkDay();
	int getMilkMonth();
	int getMilkYear();
	void delay(int milkday, int day);
	char* getType();
	char* strObj();
	void setMilkDate(int _day, int _month, int _year);
	char* milktype;
	int milkday;
private:
	int milkmonth;
	int milkyear;
};
#endif
