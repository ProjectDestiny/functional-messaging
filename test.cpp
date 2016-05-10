#include <iostream>
#include <typeinfo>
#include "receiver.hpp"

class MockObj
{
public:
	MockObj() {}
};

void test0() {
	std::cout << std::is_const<int>::value << '\n'; // false
	std::cout << std::is_const<const int>::value  << '\n'; // true
	std::cout << std::is_const<const int*>::value  << '\n'; // false
	std::cout << std::is_const<int* const>::value  << '\n'; // true
	std::cout << std::is_const<const int&>::value  << '\n'; // false

    std::cout << "===" << std::endl;
	std::cout << std::is_const<MockObj * const>::value << std::endl;
	std::cout << std::is_const<const MockObj *>::value << std::endl;
	std::cout << std::is_const<const MockObj * const>::value << std::endl;
}

// Test that
void test1() {
    std::cout << "===test1" << std::endl;

	MockObj* mock = nullptr;
	std::cout << "consts: " << std::is_const<MockObj*>::value << std::endl;

    Receiver* rec = get_receiver(mock);
	bool res = rec == nullptr;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Should Be: TRUE" << std::endl;
}

void test2() {
    std::cout << "===test2" << std::endl;

	const MockObj* mock = nullptr;
	std::cout << "consts: " << std::is_const<const MockObj*>::value << std::endl;

	Receiver* rec = get_receiver(mock);
	bool res = rec == nullptr;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Should Be: TRUE" << std::endl;
}

void test3() {
    std::cout << "===test3" << std::endl;

	MockObj* const mock = nullptr;
    std::cout << "consts: " << std::is_const<MockObj* const>::value << std::endl;

    // By SFINAE, mock will lose its const qualifier
	Receiver* rec = get_receiver(mock);
	bool res = rec == nullptr;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Should Be: TRUE" << std::endl;
}

void test4() {
	std::cout << "===test4" << std::endl;

	const MockObj mock;
	std::cout << "consts: " << std::is_const<const MockObj>::value << std::endl;

    // By SFINAE, mock will lose its const qualifier
    Receiver* rec = get_receiver(mock);
	bool res = rec == nullptr;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Should Be: TRUE" << std::endl;
}

int main() {
    std::cout << std::boolalpha;

	//test0();
	test1();
	test2();
	test3();
	test4();
    return 0;
}
