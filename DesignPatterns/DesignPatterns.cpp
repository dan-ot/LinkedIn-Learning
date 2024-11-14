#include <iostream>
#include "StringValidator.h"
#include "StringValidator2.h"

using namespace std;

int main()
{
    IStringValidator* emailValidator = new BaseValidator;

    auto ev2 = mine::Validator::with(shared_ptr<mine::IValidation>(new mine::NotEmptyValidator()))
        .then(shared_ptr<mine::IValidation>(new mine::RegexValidator("email address", "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$")));
    emailValidator
        ->set_next(new NotEmptyValidator())
        ->set_next(new RegexValidator("email address", "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));

    cout << "Checking Emails --------------\n";
    cout << "Input: \n" << emailValidator->validate("") << "\n\n";
    cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
    cout << "Input: shaun@test.com\n" << emailValidator->validate("shaun@test.com") << "\n\n";

    cout << "Checking Emails --------------\n";
    cout << "Input: \n" << ev2.validate("") << "\n\n";
    cout << "Input: shaun\n" << ev2.validate("shaun") << "\n\n";
    cout << "Input: shaun@test.com\n" << ev2.validate("shaun@test.com") << "\n\n";

    delete emailValidator;

    return 0;
}