#ifndef _Goods_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define _Goods_h
using namespace std;
class Goods
{
public:
	Goods(); //Конструктор по умолчанию
	Goods(const char* name, int day, int month, int year, double cost, int amount); //Конструктор с параметрами
	Goods(const Goods& good); //Конструктор копирования
	~Goods(); //Деструктор
	char* getName(); //Узнать имя
	int getDay(); //Узнать день
	int getMonth(); //Узнать день
	int getYear(); //Узнать день
	int getMaxAmount();
	char* strObj(); //Строковое представление объекта
	void setCost(double _cost); //Установить стоимость товара
	double getCost(); //Узнать стоимость товара
	void setAmount(int _amount); //Задать количество товара
	int getAmount(); //Узнать количество товара
	void setName(const char* newname); //Задать имя товару
	void setDate(int _day, int _month, int _year); //Задать дату товару
	void setMarkup(int money); //Повышение цены товара
	void setMarkdown(int money); //Понижение цены товара
	void setReceive(int good); //Увеличение количества товаров
	void setSell(int good); //Уменьшение количества товаров
	void setPercentage(double percentage); //Наценка или уценка товара в процентном соотношении
	void operator -=(int amount);
	void operator +=(int amount);
	operator double();
	Goods& operator++();
	Goods& operator--();
	Goods& operator = (const Goods& good);
	friend istream& operator >> (istream& in, Goods& goods);
	friend ostream& operator << (ostream& out, Goods& goods);
	void toTxt(ofstream& out);
	Goods* outTxt(ifstream& in);
	void toBin(fstream& out);
	Goods* outBin(fstream& in);
private:
	char* name; //Название
	double cost; //Цена
	int amount; //Количество
	int day; //день
	int month; //месяц
	int year; //год
	static const int MAX_AMOUNT; //Максимальное количество товара
};
#endif #pragma once
