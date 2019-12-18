
#include "fixed_queue.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace dev {
namespace testing {

class FixedSizeQueueTest : public ::testing::Test {
 public:
  void SetUp() override {
      FixedSizeQueue tmp_queue;
      std::swap(queue_, tmp_queue);
  }
  void TearDown() override {}

  FixedSizeQueue queue_;
};

TEST_F(FixedSizeQueueTest, Push) {
    float item = 5.1;
    EXPECT_NO_THROW(queue_.push(item));
}

TEST_F(FixedSizeQueueTest, GetFirst) {
    float item_1 = 5.1;
    float item_2 = 3.2;
    queue_.push(item_1);
    queue_.push(item_2);

    float result = 0;
    ASSERT_TRUE(queue_.getFirst(result));

    EXPECT_EQ(result, item_1);
}

TEST_F(FixedSizeQueueTest, PushThreeItems) {
    float item_1 = 5.1;
    float item_2 = 3.2;
    float item_3 = 1.1;
    queue_.push(item_1);
    queue_.push(item_2);
    queue_.push(item_3);

    float result = 0;
    ASSERT_TRUE(queue_.getFirst(result));

    EXPECT_EQ(result, item_2);
}

}  // namespace testing
}  // namespace dev
