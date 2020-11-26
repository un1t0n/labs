#define _CRT_SECURE_NO_WARNINGS
#include "Goods.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
#include <iostream>
#include <fstream>
#include "Tests.h"
using namespace std;

void test()
{ 
	ChildGoods good("Constructor", 10, "Apple", 25, 5, 2001, 10.0, 100);
	Tests tests;
	cout << "Test 1: " << tests.test_destruct() << "\n";
	cout << "Test 2: " << tests.test_name(&good) << "\n";
	cout << "For Test 3: ";
	cout << "Test 3: " << tests.test_date(&good) << "\n";
	cout << "Test 4: " << tests.test_markup(&good) << "\n";
	cout << "Test 5: " << tests.test_markdown(&good) << "\n";
	cout << "Test 6: " << tests.test_receive(&good) << "\n";
	cout << "Test 7: " << tests.test_sell(&good) << "\n";
	cout << "For Test 8: ";
	cout << "Test 8: " << tests.test_oversell(&good) << "\n";
	cout << "For Test 9: ";
	cout << "Test 9: " << tests.test_percentage(&good) << "\n";
	cout << "Test 10: " << tests.test_string(&good) << "\n";
	cout << "Test 11: " << tests.overload_plus_amount(&good) << "\n";
	cout << "Test 12: " << tests.overload_minus_amount(&good) << "\n";
	cout << "Test 13: " << tests.overload_double_cost(&good) << "\n";
	cout << "Test 14: " << tests.overload_increment_date(good) << "\n";
	cout << "Test 15: " << tests.overload_decrement_date(good) << "\n";
	cout << "Test 16: " << tests.overload_assignment(&good) << "\n";
	cout << "Test 17: " << tests.toTxt_test() << '\n';
	cout << "Test 18: " << tests.toBin_test() << '\n';
	cout << "For Test 19: ";
	cout << "Test 19: " << tests.test_cost(&good) << '\n';
	cout << "Test of class (Childgoods):" << '\n';
	cout << "Test 20: " << tests.test_name_of_ChildGood(&good) << '\n';
	cout << "Test 21: " << tests.test_age_of_ChildGood(&good) << '\n';
	cout << "For Test 22: ";
	cout << "Test 22: " << tests.test_not_true_age_of_ChildGood(&good) << '\n';
	cout << "Test 23: " << tests.test_string_of_ChildGood(&good) << '\n';
	cout << "Test 24: " << tests.test_age_category_of_ChildGood(good) << '\n';
	MilkGoods milkgood("Milk", 25, 05, 2000, "Apple", 25, 5, 2001, 10.0, 100);
	cout << "Test of class (Milkgoods):" << '\n';
	cout << "Test 25: " << tests.test_name_of_MilkGood(&milkgood) << '\n';
	cout << "Test 26: " << tests.test_string_of_MilkGood(&milkgood) << '\n';
	cout << "Test 27: " << tests.test_delay_of_MilkGood(milkgood) << '\n';
	cout << "For Test 28: ";
	cout << "Test 28: " << tests.test_date_of_MilkGood(&milkgood) << '\n';
	cout << "\nSuccessful: " << tests.successful << "/28";
	cout << "\nFailed: " << tests.failed;
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "RUS");
	test();

	cin.get();
	cin.get();
}
