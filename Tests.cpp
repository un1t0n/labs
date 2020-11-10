#include "Goods.h"
#include "Tests.h"
#include <iostream>
#include <fstream>
using namespace std;
Tests::Tests(){
	successful = 0;
	failed = 0;
}

//“ест деструктора

bool Tests::test_destruct() { 
	Goods* good = new Goods("AAA", 1, 1, 1970, 0, 0);
	delete good;
	try {
		if ((good->getName() == (char*)0xfeeefeee))
			throw 1;
		else {
			failed++;
			return false;
			}
		}
	catch (int a) {
		successful++;
		return true;
	}
}

//“ест на сравнение имени

bool Tests::test_name(Goods* test_good) { 
	test_good->setName("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
	const char* expect = "Apple";
	const char* real;
	real = test_good->getName();

	if (*expect == *real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real <<"\n";
		failed++;
		return false;
	}
}

//“ест на сравнение даты

bool Tests::test_date(Goods* test_good) { 
	test_good->setDate(0,0,0);
	int expectDay = 25;
	int expectMonth = 5;
	int expectYear = 2001;
	int realDay = test_good->getDay();
	int realMonth = test_good->getMonth();
	int realYear = test_good->getYear();
	if ((expectDay == realDay) && (expectMonth == realMonth) && (expectYear == realYear)) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expectDay << " " << expectMonth << " " << expectYear << " Real: " << realDay << " " << realMonth << " " << realYear <<"\n";
		failed++;
		return false;
	}
}

//“ест на повышение стоимости товара

bool Tests::test_markup(Goods* test_good) { //“естируем загрузки денег в автомат
	test_good->setCost(10.0);
	test_good->setMarkup(5.0);

	double expect = 15.0;
	double real = test_good->getCost();
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
	}
}

//“ест на понижение стоимости товара

bool Tests::test_markdown(Goods* test_good) { 
	test_good->setCost(10.0);
	test_good->setMarkdown(5.0);
	double expect = 5;
	double real = test_good->getCost();
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
	}
}

//тест на увеличение количества товара

bool Tests::test_receive(Goods* test_good) {
	test_good->setAmount(100);
	test_good->setReceive(5);
	int expect = 105;
	int real = test_good->getAmount();
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
	}
}

//тест на уменьшение количества товара

bool Tests::test_sell(Goods* test_good) {
	test_good->setAmount(100);
	test_good->setSell(5);
	int expect = 95;
	int real = test_good->getAmount();
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
	}
}

//тест на уменьшение количества товара (с использованием константы)

bool Tests::test_oversell(Goods* test_good) {
	int expect = 100;
	int real = 0;
	test_good->setAmount(100);
	test_good->setSell(101);
	real = test_good->getAmount(); 
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
		}
}


//“ест на процентную наценку товара

bool Tests::test_percentage(Goods* test_good) {
	test_good->setCost(10.0);
	test_good->setPercentage(-50);
	int expect = 10;
	int real = test_good->getCost();
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
	}
}

//“ест на строковое представление товара

bool Tests::test_string(Goods* test_good) {
	test_good->setName("Orange");
	test_good->setDate(5,5,1999);
	test_good->setCost(10.0);
	test_good->setAmount(100);
	const char* expect = "Orange 5 5 1999 10.0 100";
	const char* real;
	real = test_good->strObj();

	if (*expect == *real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real <<"\n";
		failed++;
		return false;
	}
}
//“ест на перегрузку добавлени€ товаров

bool Tests::overload_plus_amount(Goods* test_good){
	int amount = 10;
	*test_good += amount;
	int expected = 110;
	int actual = test_good->getAmount();
	if (actual == expected) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expected << "Actual: " << actual << "\n";
		failed++;
		return false;
	}
}
//“ест на перегрузку уменьшени€ количества товаров

bool Tests::overload_minus_amount(Goods* test_good){
	int amount = 10;
	*test_good -= amount;
	int expected = 100;
	int actual = test_good->getAmount();
	if (actual == expected) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expected << "Actual: " << actual << "\n";
		failed++;
		return false;
	}
}

//“ест на приведение к типу double

bool Tests::overload_double_cost(Goods* test_good){
	int cost = 10;
	double expected = double(*test_good);
	double actual = test_good->getCost();
	if (actual == expected) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expected << "Actual: " << actual << "\n";
		failed++;
		return false;
	}
}

//“ест на перегрузку инкремента 

bool Tests::overload_increment_date(Goods* test_good){
	test_good->setDate(25,5,2001);
	test_good[0]++;
	int expected = 26;
	int actual = test_good->getDay();
	if (expected == actual) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expected <<" "<< "Actual: " << actual << "\n";
		failed++;
		return false;
	}
}

//“ест на перегрузку декремента

bool Tests::overload_decrement_date(Goods* test_good){
	test_good->setDate(25,5,2001);
	test_good[0]--;
	int expected = 24;
	int actual = test_good->getDay();
	if (expected == actual) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expected <<" "<< "Actual: " << actual << "\n";
		failed++;
		return false;
	}
}

//“ест на перегрузку присвоени€

bool Tests::overload_assignment(Goods* test_good) {
	test_good->setName("Orange");
	test_good->setDate(5,5,1999);
	test_good->setCost(10.0);
	test_good->setAmount(100);
	Goods* good2 = new Goods("Apple", 25,5,2001, 10.0, 100);
	*good2 = *test_good;
	 if ((strcmp(test_good->getName(), good2->getName()) == 0) && (test_good->getAmount() == good2->getAmount()) && 
		 (test_good->getDay() == good2->getDay()) && (test_good->getMonth() == good2->getMonth()) &&
		(test_good->getYear() == good2->getYear()) && (test_good->getCost() == good2->getCost())) {
		delete good2;
		 successful++;
		 return true;
	 }
	 else {
		 std::cout << "Actual " << good2->getName()<< " Expected " << test_good->getName()<<std::endl;
		 std::cout << "Actual " << good2->getDay()<< " Expected " << test_good->getDay()<<std::endl;
		 std::cout << "Actual " << good2->getMonth()<< " Expected " << test_good->getMonth()<<std::endl;
		 std::cout << "Actual " << good2->getYear() << " Expected " << test_good->getYear() << std::endl;
		 std::cout << "Actual " << good2->getAmount() << " Expected " << test_good->getAmount() << std::endl;
		 std::cout << "Actual " << good2->getCost() << " Expected " << test_good->getCost() << std::endl;
		delete good2;
		failed++;
		return false;
	 }
}
bool Tests::toTxt_test() {
		ofstream out("file.txt");
		try {
			if (!out) throw 1;
		}
		catch (int a) {
			cout << "Failed to open file" << endl;
			return false;
		}
		int N = 5;
		Goods* goodW = new Goods[N];
		for (int i = 0; i < N; ++i)
		{
			goodW[i] = Goods("Orange", 25, 4, 1999, 234, 5);
			out << goodW[i] << '\n';
		}
		out.close();
		Goods* goodR = new Goods[N];
		ifstream in("file.txt");
		try {
			if (!in) throw 1;
		}
		catch (int a) {
			cout << "Failed to open file" << endl;
			return false;
		}
		for (int i = 0; i < N; i++)
		{ 
			in >> goodR[i];
			in.seekg(sizeof(goodR->getMaxAmount()), ios::cur);
		}
		for (int i = 0; i < N; i++) {
			if (strcmp(goodW[i].getName(), goodR[i].getName()) != 0
				|| goodW[i].getDay() != goodR[i].getDay() 
				|| goodW[i].getMonth() != goodR[i].getMonth()
				|| goodW[i].getYear() != goodR[i].getYear()
				|| goodW[i].getCost() != goodR[i].getCost()
				|| goodW[i].getAmount() != goodR[i].getAmount()) {
				cout << "Expected: " << goodW[i] <<
					" Actual: " << goodR[i] << endl;
				failed++;
				return false;
				break;
			}

		}
		in.close();
		successful++;
		return true;
	}
bool Tests::toBin_test() {
	fstream out("file.dat", ios::binary|ios::out);
	try {
		if (!out) throw 1;
	}
	catch (int a) {
		cout << "Failed to open file" << endl;
		return false;
	}
	int N = 5;
	Goods* goodW = new Goods[N];
	for (int i = 0; i < N; ++i)
	{
		goodW[i] = Goods("Orange", 25, 4, 1999, 234, 5);
		goodW[i].toBin(out);
	}
	out.close();
	Goods* goodR = new Goods;
	fstream in("file.dat", ios::binary| ios::in);
	try {
		if (!in) throw 1;
	}
	catch (int a) {
		cout << "Failed to open file" << endl;
		return false;
	}
	goodR = goodR->outBin(in);
	for (int i = 0; i < N; i++) {
		if (strcmp(goodW[i].getName(), goodR[i].getName()) != 0
			|| goodW[i].getDay() != goodR[i].getDay()
			|| goodW[i].getMonth() != goodR[i].getMonth()
			|| goodW[i].getYear() != goodR[i].getYear()
			|| goodW[i].getCost() != goodR[i].getCost()
			|| goodW[i].getAmount() != goodR[i].getAmount()) {
			cout << "Expected: " << goodW[i] << " Actual: " << goodR[i] << endl;
			failed++;
			return false;
			break;
		}

	}
	in.close();
	successful++;
	return true;
}

bool Tests::test_cost(Goods* test_good) {
	test_good->setCost(-10.0);
	int expect = 10;
	int real = test_good->getCost();
	if (expect == real) {
		successful++;
		return true;
	}
	else {
		std::cout << "Expected: " << expect << " Real: " << real << "\n";
		failed++;
		return false;
	}
}