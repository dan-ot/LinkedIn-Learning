#include "StringValidator2.h"
#include <iostream>
#include <sstream>

using namespace std;

string Handler::handle(string input)
{
    stringstream rb;
    for (auto &validator : validations_) {
        auto possible_error = validator->handle(input);

        if (possible_error.has_value()) {
            rb << possible_error.value();
        }
    }

    auto response = rb.str();

    if (response.empty()) {
        group_->publish(input);
        return "Success!";
    }
    else {
        return response;
    }
}

Handler Handler::targeting(shared_ptr<ChatGroup> target, shared_ptr<IHandling> first)
{
    auto vc = Handler();
    vc.validations_.push_back(first);
    vc.group_ = target;
    return vc;
}
Handler Handler::then(shared_ptr<IHandling> next)
{
    validations_.push_back(next);
    return *this;
}

optional<string> NotEmptyValidator::handle(string input) {
    cout << "Validating emptiness... ";
    if (input.empty()) {
        return optional("String was empty.");
    }
    else {
        return optional<string>();
    }
}

optional<string> LengthValidator::handle(string input) {
    cout << "Validating length... ";
    if (input.length() < min_length_) {
        return optional("String isn't long enough.");
    }
    else {
        return optional<string>();
    }
}

optional<string> RegexValidator::handle(string input) {
    cout << "Validating pattern... ";
    if (regex_match(input, regex_)) {
        return optional<string>();
    }
    else {
        return optional("String didn't match " + pattern_name_);
    }
}

optional<string> HistoryValidator::handle(string input) {
    cout << "Validating history... ";
    if (history_.count(input) > 0) {
        return optional("String has been used before.");
    }
    else {
        history_.emplace(input);
        return optional<string>();
    }
}
