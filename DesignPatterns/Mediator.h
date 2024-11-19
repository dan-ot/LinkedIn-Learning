#pragma once
#include <string>
#include <memory>
#include <functional>

class InterfaceElement {
protected:
	std::function<void(const std::string &)> mediate_;
	std::string name_;
	bool is_visible_ = true;
public:
	InterfaceElement(const std::string& name, bool is_visible, const std::function<void(const std::string &)> &mediator)
		: name_(name), is_visible_(is_visible), mediate_(mediator) {
	};
	void set_visibility(bool is_visible);
	std::string get_description();
};

class IButton : public InterfaceElement {
public:
	IButton(const std::string& name, bool is_visible, const std::function<void(const std::string&)> &mediator)
		: InterfaceElement(name, is_visible, mediator) {
	};
	virtual ~IButton() {};
	virtual void click();
};

class ITextBox : public InterfaceElement {
	std::string text_value_ = "";
public:
	ITextBox(const std::string& name, bool is_visible, const std::function<void(const std::string&)> &mediator)
		: InterfaceElement(name, is_visible, mediator) {
	};
	virtual ~ITextBox() {};
	virtual void change_text(const std::string& new_value);
};

class ICheckbox : public InterfaceElement {
	bool is_checked_ = true;
public:
	ICheckbox(const std::string& name, bool is_visible, const std::function<void(const std::string&)> &mediator)
		: InterfaceElement(name, is_visible, mediator) {
	};
	virtual ~ICheckbox() {};
	virtual void set_is_checked(bool is_checked);
};

class UserInterface {
	std::unique_ptr<ITextBox> name_text_box_;
	std::unique_ptr<ICheckbox> is_married_checkbox_;
	std::unique_ptr<ITextBox> spouses_name_checkbox_;
	std::unique_ptr<IButton> submit_button_;
public:
	UserInterface();
	void mediate(const std::string&);
	void print();
	void married(bool);
	void named(const std::string&);
};