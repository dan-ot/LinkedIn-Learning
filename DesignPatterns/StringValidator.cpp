#include "StringValidator.h"

using namespace std;

string NotEmptyValidator::handle(string test_string)
{
    cout << "Checking if empty...";

    if (test_string.empty()) {
        return "Please enter a value.";
    }
    
    return BaseValidator::handle(test_string);
}

string LengthValidator::handle(string test_string)
{
    cout << "Checking string length...";

    if (test_string.length() < min_length_) {
        return "Please enter a value longer than " + to_string(min_length_);
    }

    return BaseValidator::handle(test_string);
}

string RegexValidator::handle(string test_string)
{
    cout << "Checking regex match...";
    if (regex_match(test_string, regex(regex_string_)) == false) {
        return "The value entered does not match the proper format for a " + pattern_name_;
    }

    return BaseValidator::handle(test_string);
}

string HistoryValidator::handle(string test_string)
{
    cout << "Checking if string has been used before...";
    if (history_items_.count(test_string) > 0) {
        return "Please enter a value ehre that you haven't used before.";
    }

    return BaseValidator::handle(test_string);
}
