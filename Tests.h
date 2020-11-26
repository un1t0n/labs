#pragma once

#ifndef _Tests_h

#include "Goods.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
class Tests
{

public:
	Tests();
	bool test_destruct();
	bool test_name(Goods* test_good);
	bool test_date(Goods* test_good);
	bool test_markup(Goods* test_good);
	bool test_markdown(Goods* test_good);
	bool test_receive(Goods* test_good);
	bool test_sell(Goods* test_good);
	bool test_oversell(Goods* test_good);
	bool test_percentage(Goods* test_good);
	bool test_string(Goods* test_good);
	bool overload_plus_amount(Goods* test_good);
	bool overload_minus_amount(Goods* test_good);
	bool overload_double_cost(Goods* test_good);
	bool overload_increment_date(Goods& test_good);
	bool overload_decrement_date(Goods& test_good);
	bool overload_assignment(Goods* test_good);
	bool toBin_test();
	bool toTxt_test();
	bool test_cost(Goods* test_good);
	bool test_name_of_ChildGood(ChildGoods* test_good);
	bool test_age_of_ChildGood(ChildGoods* test_good);
	bool test_not_true_age_of_ChildGood(ChildGoods* test_good);
	bool test_string_of_ChildGood(ChildGoods* test_good);
	bool test_age_category_of_ChildGood(ChildGoods& test_good);
	bool test_name_of_MilkGood(MilkGoods* test_good);
	bool test_string_of_MilkGood(MilkGoods* test_good);
	bool test_delay_of_MilkGood(MilkGoods& test_good);
	bool test_date_of_MilkGood(MilkGoods* milkgood);
	int successful;
	int failed;
};


#endif #pragma once
