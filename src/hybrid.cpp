#include "boost/python.hpp"
#include <string>
#include <set>

extern void init_utils();

#define BOOST_PYTHON_STATIC_LIB

using namespace std;

set<string> key_names = { "key_a", "key_b", "key_c" };

namespace bp = boost::python;


/////////////////////////// boost python /////////////////////////////////
void say_hello()
{
	printf("hello world\n");
}

enum NumberType
{
	First = 1,
	Second,
	Third,
};

class HybridTest
{
public:
	HybridTest(int t1, int t2) : t1_(t1), t2_(t2) {}
	void test() { printf("HybridTest: %d + %d = %d\n", t1_, t2_, t1_ + t2_); }
private:
	int t1_;
	int t2_;
};


BOOST_PYTHON_MODULE(hybrid)
{

	init_utils();
	
	for (const string &name : key_names)
	{
		bp::scope().attr(name.c_str()) = name;
	}

	bp::def("say_hello", say_hello);

	bp::enum_<NumberType>("number_type")
		.value("first", NumberType::First)
		.value("second", NumberType::Second)
		.value("third", NumberType::Third)
		;

	bp::class_<HybridTest>("HybridTest", bp::init<int, int>())
		.def("test", &HybridTest::test)
		;

}