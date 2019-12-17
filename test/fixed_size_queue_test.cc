
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
  dev::FixedSizeQueue queue_;
};

TEST_F(FixedSizeQueueTest, Push) {
    float item = 5.1;
    EXPECT_NO_THROW(queue.push(item));
}

TEST_F(FixedSizeQueueTest, GetFirst) {
    float item = 5.1;
    queue_.push(item);
    EXPECT_TRUE(queue_.getFirst());
}

//TODO:
//  Increase coverage

}  // namespace testing
}  // namespace dev
