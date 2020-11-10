#define _CRT_SECURE_NO_WARNINGS
#include "Goods.h"
#include <iostream>
#include <fstream>
#include "Tests.h"
using namespace std;

void test()
{
	Goods good("Apple", 25, 5, 2001, 10.0, 100);
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
	cout << "Test 14: " << tests.overload_increment_date(&good) << "\n";
	cout << "Test 15: " << tests.overload_decrement_date(&good) << "\n";
	cout << "Test 16: " << tests.overload_assignment(&good) << "\n";
	cout << "Test 17: " << tests.toTxt_test() << '\n';
	cout << "Test 18: " << tests.toBin_test() << '\n';
	cout << "For Test 19: ";
	cout << "Test 19: " << tests.test_cost(&good) << '\n';
	cout << "\nSuccessful: " << tests.successful << "/19";
	cout << "\nFailed: " << tests.failed;
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "RUS");
	test();
	cin.get();
	cin.get();
}
