#include "pch.h"
#include "DataHolder.h"

using ::testing::_;
using ::testing::Return;

class MockQueue : public QueueInterface {
public:
	MOCK_METHOD0(dequeue, int());
	MOCK_METHOD1(enqueue, void(int data));
};

TEST(GMockTests, CanAddData) {
	MockQueue q;
	DataHolder dh(&q);
	
	EXPECT_CALL(q, enqueue(_));
	dh.add_data(1);
}

TEST(GMockTests, CanAddAndGetData) {
	MockQueue q;
	DataHolder dh(&q);

	EXPECT_CALL(q, enqueue(1));
	EXPECT_CALL(q, dequeue()).WillOnce(Return(1));

	dh.add_data(1);
	auto out = dh.get_data();

	EXPECT_EQ(1, out);
}