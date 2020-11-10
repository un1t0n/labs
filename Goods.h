#ifndef _Goods_h
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define _Goods_h
using namespace std;
class Goods
{
public:
	Goods(); //����������� �� ���������
	Goods(const char* name, int day, int month, int year, double cost, int amount); //����������� � �����������
	Goods(const Goods& good); //����������� �����������
	~Goods(); //����������
	char* getName(); //������ ���
	int getDay(); //������ ����
	int getMonth(); //������ ����
	int getYear(); //������ ����
	int getMaxAmount();
	char* strObj(); //��������� ������������� �������
	void setCost(double _cost); //���������� ��������� ������
	double getCost(); //������ ��������� ������
	void setAmount(int _amount); //������ ���������� ������
	int getAmount(); //������ ���������� ������
	void setName(const char* newname); //������ ��� ������
	void setDate(int _day, int _month, int _year); //������ ���� ������
	void setMarkup(int money); //��������� ���� ������
	void setMarkdown(int money); //��������� ���� ������
	void setReceive(int good); //���������� ���������� �������
	void setSell(int good); //���������� ���������� �������
	void setPercentage(double percentage); //������� ��� ������ ������ � ���������� �����������
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
	char* name; //��������
	double cost; //����
	int amount; //����������
	int day; //����
	int month; //�����
	int year; //���
	static const int MAX_AMOUNT; //������������ ���������� ������
};
#endif #pragma once
