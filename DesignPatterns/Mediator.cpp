#include "Mediator.h"
#include <iostream>

using namespace std;

void InterfaceElement::set_visibility(bool visibility) {
	is_visible_ = visibility;
}

string InterfaceElement::get_description() {
	return is_visible_
		? name_ + " is visible"
		: name_ + " is NOT visible";
}

void ITextBox::change_text(const std::string& new_value)
{
	text_value_ = new_value;

	if (new_value.empty()) {
		mediate_(name_ + " is empty");
	}
	else {
		mediate_(name_ + " is not empty");
	}
}

void ICheckbox::set_is_checked(bool is_checked)
{
	is_checked_ = is_checked;
	if (is_checked) {
		mediate_(name_ + " checked");
	}
	else {
		mediate_(name_ + " unchecked");
	}
}


UserInterface::UserInterface()
{
	auto med = [this](string m) { this->mediate(m); };
	name_text_box_ = make_unique<ITextBox>("Name Textbox", true, med);
	is_married_checkbox_ = make_unique<ICheckbox>("Is Married Checkbox", true, med);
	spouses_name_checkbox_ = make_unique<ITextBox>("Spouse's Name Textbox", false, med);
	submit_button_ = make_unique<IButton>("Submit Button", false, med);
}

void IButton::click()
{
	mediate_(name_ + " clicked");
}

void UserInterface::mediate(const std::string& event)
{
	cout << "Mediating event: " << event << "...\n";

	if (event == "Name Textbox is empty") {
		submit_button_->set_visibility(false);
	}
	else if (event == "Name Textbox is not empty") {
		submit_button_->set_visibility(true);
	}
	else if (event == "Is Married Checkbox checked") {
		spouses_name_checkbox_->set_visibility(true);
	}
	else if (event == "Is Married Checkbox unchecked") {
		spouses_name_checkbox_->set_visibility(false);
	}
	else if (event == "Submit Button checked") {
		cout << "Submitted! \n";
	}
	else {
		cout << "Uknown event: " << event << "\n";
	}
}

void UserInterface::print()
{
	cout << "Name: " << name_text_box_->get_description() << "\n";
	cout << "Is Married: " << is_married_checkbox_->get_description() << "\n";
	cout << "Spouse's Name: " << spouses_name_checkbox_->get_description() << "\n";
	cout << "Submit Button: " << submit_button_->get_description() << "\n";
}

void UserInterface::married(bool is_married)
{
	is_married_checkbox_->set_is_checked(is_married);
}

void UserInterface::named(const string &name)
{
	name_text_box_->change_text(name);
}
