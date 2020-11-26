#ifndef _ChildGoods_h
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Goods.h"
class ChildGoods :
	public Goods
{
public:
	ChildGoods();
	ChildGoods(const char* type, int age, const char* name, int day, int month, int year, double cost, int amount);
	ChildGoods(const ChildGoods& good);
	~ChildGoods();
	void setType(const char* newtype);
	void setAge(int _age);
	int getAge();
	char* getType();
	char* strObj();
	friend bool operator<= (const ChildGoods &good, int _age);
	int age;
private:
	char* childtype;
};
#endif
