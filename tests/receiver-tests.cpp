#include <typeinfo>
#include "gtest/gtest.h"
#include "../src/receiver.hpp"

// TEST(Group1,Subtest1) {
// 	EXPECT_EQ(1,0);
// }
//
// TEST(Group2,Subtest1) {
// 	EXPECT_EQ(0,0);
// }

class MockObj
{
public:
	MockObj() {}
};

TEST(ReceiverCreation,
     GetReceiverFromPtr) {
	MockObj* mock = nullptr;
	std::cout << "consts: " << std::is_const<MockObj*>::value << std::endl;

	Receiver* rec = get_receiver(mock);
	ASSERT_EQ(rec,nullptr);
}
