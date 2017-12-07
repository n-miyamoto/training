#include "gtest/gtest.h"
#include "mybit.h"

namespace {

class MyBitTest : public ::testing::Test{
};

TEST_F(MyBitTest, bit_init)
{
	bit_init(1);
	EXPECT_EQ( 1,bit_show_n());

	bit_init(4);
	EXPECT_EQ( 4,bit_show_n());

	bit_init(5);
	EXPECT_EQ( 8,bit_show_n());

	bit_init(7);
	EXPECT_EQ( 8,bit_show_n());

	bit_init(1<<16);
	EXPECT_EQ(1<<16,bit_show_n());
}

TEST_F(MyBitTest, add)
{
	//simple case	
	bit_init(4);
	for(int i=1; i<=4;i++)add(i,i);
	EXPECT_EQ(1,bit_show_node(1));
	EXPECT_EQ(3,bit_show_node(2));
	EXPECT_EQ(3,bit_show_node(3));
	EXPECT_EQ(10,bit_show_node(4));
}


TEST_F(MyBitTest, sum)
{
	//simple case	
	bit_init(4);
	for(int i=1; i<=4;i++)add(i,i);
	EXPECT_EQ(1,sum(1));
	EXPECT_EQ(3,sum(2));
	EXPECT_EQ(6,sum(3));
	EXPECT_EQ(10,sum(4));

}

} // namespace	