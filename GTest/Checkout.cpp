#include "Checkout.h"

void Checkout::add_item_price(std::string item, int price)
{
	price_list_[item] = price;
}

void Checkout::add_item(std::string item)
{
	if (price_list_.find(item) == price_list_.end())
		throw std::invalid_argument("Invalid item. No price found.");
	cart_[item] += 1;
}

void Checkout::add_discout_rule(std::string item, int number_of_items, int discount_price)
{
	discount_schedule_[item] = Discount{ number_of_items, discount_price };
}

int Checkout::calculate_total()
{
	int total = 0;
	for (auto& item_pair : cart_) {
		if (price_list_.find(item_pair.first) != price_list_.end()) {
			if (discount_schedule_.find(item_pair.first) != discount_schedule_.end()) {
				auto bundles = item_pair.second / discount_schedule_[item_pair.first].required_quantity;
				total += bundles * discount_schedule_[item_pair.first].discount_price;
				auto normal_priced = item_pair.second % discount_schedule_[item_pair.first].required_quantity;
				total += normal_priced * price_list_[item_pair.first];
			}
			else {
				total += price_list_[item_pair.first] * item_pair.second;
			}
		}
	}

	return total;
}
