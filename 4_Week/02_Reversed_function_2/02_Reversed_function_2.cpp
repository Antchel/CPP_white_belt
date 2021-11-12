#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params
{
	int a;
	int b;
	int c;
};

class FunctionPart {
public:
	explicit FunctionPart(char new_operation, double new_value) :
		operation(new_operation), value(new_value) {}
	void Invert() {
		if (operation == '+')
			operation = '-';
		else if (operation == '-')
			operation = '+';
		else if (operation == '*')
			operation = '/';
		else if (operation == '/')
			operation = '*';
	}
	double Apply(double new_value) {
		if (operation == '+')
			return value + new_value;
		else if (operation == '-')
			return new_value - value;
		else if (operation == '*')
			return value * new_value;
		else if (operation == '/')
			return new_value / value;
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void Invert() {
		for (auto& part : parts) {
			part.Invert();
		}
		reverse(parts.begin(), parts.end());
	}
	double Apply(double value) {
		for (auto& part : parts) {
			value = part.Apply(value);
		}
		return value;
	}
	void AddPart(char operation, double value) {
		parts.push_back(FunctionPart{ operation, value });
	}
private:
	vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& param,
							const Image& image) {
	Function function;
	function.AddPart('*', param.a);
	function.AddPart('-', image.freshness * param.b);
	function.AddPart('+', image.rating * param.c);
	return function;
}

double ComputeImageWeight(	const Params& param,
							const Image& image) {
	Function function = MakeWeightFunction(param, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(	const Params& param,
								const Image& image, double weight) {
	Function function = MakeWeightFunction(param, image);
	function.Invert();
	return function.Apply(weight);
}

int main()
{
	Image image{ 10, 2, 6 };
	Params params{ 4,2,6 }; 

	cout << ComputeImageWeight(params, image) << "\n";
	cout << ComputeQualityByWeight(params, image, 52) << "\n";
	return 0;
}