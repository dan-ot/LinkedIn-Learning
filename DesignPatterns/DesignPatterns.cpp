#include <iostream>
#include <sstream>
#include "StringValidator.h"
#include "StringValidator2.h"
#include "CommandDomain.h"
#include "Command.h"
#include "Mediator.h"

using namespace std;

static string vector_to_string(vector<string> v) {
    stringstream ss;
    for (auto& s : v) {
        ss << s << ", ";
    }
    return ss.str();
}

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

    Canvas* canvas = new Canvas;

    Button* addTriangleButton = new Button(new AddShapeCommand("triangle", canvas));
    Button* addSquareButton = new Button(new AddShapeCommand("square", canvas));
    Button* clearButton = new Button(new ClearCommand(canvas));

    addTriangleButton->click();
    cout << "Current canvas state: " << vector_to_string(canvas->get_shapes()) << "\n";
    addSquareButton->click();
    addSquareButton->click();
    addTriangleButton->click();
    cout << "Current canvas state: " << vector_to_string(canvas->get_shapes()) << "\n";
    clearButton->click();
    cout << "Current canvas state: " << vector_to_string(canvas->get_shapes()) << "\n";

    delete canvas;

    UserInterface ui{};
    ui.print();
    ui.named("Bert");
    ui.married(true);
    ui.print();
    

    return 0;
}