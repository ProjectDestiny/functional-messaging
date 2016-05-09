#include <iostream>
#include "receiver.hpp"

class MockObj
{

};

void test1() {
	MockObj* mock = nullptr;
    Receiver* rec = get_receiver<MockObj*>(mock);
	bool res = rec == nullptr;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Should Be: TRUE" << std::endl;
}

void test2() {
	const MockObj* mock = nullptr;
	Receiver* rec = get_receiver<const MockObj*>(mock);
	bool res = rec == nullptr;
	std::cout << "Result: " << res << std::endl;
	std::cout << "Should Be: TRUE" << std::endl;
}

int main() {
    return 0;
}
