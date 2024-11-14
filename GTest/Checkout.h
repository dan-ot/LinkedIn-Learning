#pragma once
#include <string>
#include <map>
#include <stdexcept>

class Checkout
{
public:
	void add_item_price(std::string item, int price);
	void add_item(std::string item);
	void add_discout_rule(std::string item, int number_of_items, int discount_price);

	int calculate_total();

	Checkout() {
	};

private:
	struct Discount {
		int required_quantity;
		int discount_price;
	};

	std::map<std::string, int> price_list_;
	std::map<std::string, Discount> discount_schedule_;
	std::map<std::string, int> cart_;
};

