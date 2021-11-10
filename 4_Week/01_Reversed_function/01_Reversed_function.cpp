#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
	explicit FunctionPart(char new_operation, double new_value)
		:operation(new_operation), value(new_value){}
	double Apply() const {
		if (operation == '+')
			return value;
		else
			return -value;
	}
	void Invert() {
		operation = operation == '+' ? '-' : '+';
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(char operation, double value) {
		parts.push_back(FunctionPart{ operation, value });
	}
	void Invert() {
		for (auto& part : parts) {
			part.Invert();
		}
		reverse(parts.begin(), parts.end());
	}
	double Apply(double value) const {
		for (const auto& part : parts) {
			value += part.Apply();
		}
		return value;
	}
private:
	vector<FunctionPart> parts;
};

int main()
{
	Function function;
	function.AddPart('+', 5.12);
	function.AddPart('+', 7.78);
	function.AddPart('-', 3.14);
	function.AddPart('+', 0.12);

	cout << function.Apply(5L)<< endl;

	function.Invert();
	
	cout << function.Apply(5L) << endl;

}
