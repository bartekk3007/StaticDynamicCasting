#include <iostream>

class BNV
{
public:
	void print()
	{
		std::cout << "I am base\n";
	}
};

class DNV : public BNV
{
public:
	void print()
	{
		std::cout << "I am derived\n";
	}
};

class BV
{
public:
	virtual ~BV()
	{

	}
	void virtual print()
	{
		std::cout << "I am base\n";
	}
};

class DV : public BV
{
public:
	void print()
	{
		std::cout << "I am derived\n";
	}
};

int main()
{
	BNV bnv1;
	DNV dnv1;
	BNV bnv2;
	DNV dnv2;

	BNV& bnvref = dnv2;
	//DNV& dnvref = bnv2;

	BV bv1;
	DV dv1;
	BV bv2;
	DV dv2;

	BV& bvref = dv2;
	//DV& dvref = bv2;

	// non-virtual D2B
	BNV& BNVstaticN = static_cast<BNV&>(dnv1);
	BNVstaticN.print();
	// virtual D2B
	BV& BVStaticN = static_cast<BV&>(dv1);
	BVStaticN.print();
	// non-virtual B2D
	DNV& DNVstaticN = static_cast<DNV&>(bnv1);
	DNVstaticN.print();
	DNV& DNVstaticP = static_cast<DNV&>(bnvref);
	DNVstaticP.print();
	// virtual B2D
	DV& DVstaticN = static_cast<DV&>(bv1);
	DVstaticN.print();
	DV& DVstaticP = static_cast<DV&>(bvref);
	DVstaticP.print();

	// non-virtual D2B
	BNV& BNVdynamicN = dynamic_cast<BNV&>(dnv1);
	// virtual D2B
	BV& BVSdynamicN = dynamic_cast<BV&>(dv1);
	// non-virtual B2D
	// DNV& DNVdynamicN = dynamic_cast<DNV&>(bnv1);
	// DNV& DNVdynamicP = dynamic_cast<DNV&>(bnvref);
	// virtual B2D
	//DV& DVdynamicN = dynamic_cast<DV&>(bv1);
	DV& DVdynamicP = dynamic_cast<DV&>(bvref);

	// C-style casting
	char letter = 'a';
	int number = (int)letter;

	//function-sytyle casting
	float smallNumber = .25f;
	double betterNumber = double(smallNumber);
	std::cout << betterNumber << '\n';

	return 0;
}