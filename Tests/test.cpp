#include "pch.h"

class CheckoutTests : public ::testing::Test {
public:
protected:
	Checkout checkout;
};

TEST_F(CheckoutTests, CanCalculateCurrentTotal) {
	checkout.add_item_price("a", 1);
	checkout.add_item("a");
	auto result = checkout.calculate_total();

	EXPECT_EQ(1, result);
}

TEST_F(CheckoutTests, CanAddMultipleItemsAndTotal) {
	checkout.add_item_price("a", 1);
	checkout.add_item_price("b", 2);
	checkout.add_item("a");
	checkout.add_item("b");
	auto result = checkout.calculate_total();

	EXPECT_EQ(3, result);
}

TEST_F(CheckoutTests, CanAddDiscountRules) {
	checkout.add_discout_rule("a", 3, 2);
}

TEST_F(CheckoutTests, CanCalculateTotalWithDiscount) {
	checkout.add_item_price("a", 1);
	checkout.add_discout_rule("a", 3, 2);
	checkout.add_item("a");
	checkout.add_item("a");
	checkout.add_item("a");
	checkout.add_item("a");
	checkout.add_item("a");
	auto total = checkout.calculate_total();

	EXPECT_EQ(4, total);
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException) {
	EXPECT_THROW(checkout.add_item("a"), std::invalid_argument);
}