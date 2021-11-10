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
	void Invert();
private:
};

class Function {
public:
	void Invert();
private:
	vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& param,
	const Image& image) {
	Function function;

	return function;
}

double ComputeImageWeight(const Params& param,
	const Image& image) {

}

double ComputeQualityByWeight(const Params& param,
	const Image& image, double weight) {

}

int main()
{

}