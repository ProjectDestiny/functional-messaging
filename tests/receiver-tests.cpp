#include <typeinfo>
#include <iostream>
#include <type_traits>
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

TEST(ReceiverCreation, GetReceiverReturnsNullptrForEmptyPointerObject) {
	MockObj* mock = nullptr;
	auto rec = get_receiver(mock);
	ASSERT_EQ(rec,nullptr);
}

TEST(ReceiverCreation, GetReceiverReturnsNewReceiverForNonEmptyObject) {
	MockObj* mock = new MockObj;
	auto rec = get_receiver(mock);
	ASSERT_NE(rec,nullptr);
}

TEST(ReceiverCreation, GetReceiverReturnsNullptrForEmptyConstPointerObject) {
	MockObj * const mock = nullptr;
	auto rec = get_receiver(mock);
	ASSERT_EQ(rec,nullptr);
}

TEST(ReceiverCreation, GetReceiverReturnsNewReceiverForNonEmptyConstPointerToObject) {
	MockObj * const mock = new MockObj;
	auto rec = get_receiver(mock);
	ASSERT_NE(rec,nullptr);
}

TEST(ReceiverCreation, GetReceiverReturnsNewReceiverForObjectInstance) {
	MockObj mock;
	auto rec = get_receiver(mock);
	ASSERT_NE(rec,nullptr);
}

TEST(ReceiverCreation, GetReceiverReturnsNewReceiverForConstObjectInstance) {
	const MockObj mock;
	auto rec = get_receiver(mock);
	ASSERT_NE(rec,nullptr);
}
