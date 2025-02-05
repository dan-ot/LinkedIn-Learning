#include "OptionalsVariants.h"
#include <vector>

using namespace std;

static optional<long> factor(long n) {
	for (long i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return i;
		}
	}
	return optional<long>();
}

static ostream& operator << (ostream& out, const any& o) {
	if (!o.has_value())
		out << "None.\n";
	else if (o.type() == typeid(int)) {
		auto x = any_cast<int>(o);
		cout << "int " << x << "\n";
	}
	else if (o.type() == typeid(string)) {
		auto x = any_cast<const string&>(o);
		cout << "string " << x << "\n";
	}
	else if (o.type() == typeid(vector<int>)) {
		auto v = any_cast<const vector<int>&>(o);
		cout << "vector of int, " << v.size() << " elements.\n";
		for (const auto& e : v) cout << e << " ";
		cout << "\n";
	}
	else cout << "I don't handle this type (compiler type string: " << o.type().name() << "\n";

	return out;
}