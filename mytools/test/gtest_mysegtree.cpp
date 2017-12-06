#include "gtest/gtest.h"
#include "mysegtree.h"

namespace {

class MySegtreeTest : public ::testing::Test{
};

TEST_F(MySegtreeTest, init)
{
	init(1);
	EXPECT_EQ( 1,show_n());
	
	init(3);
	EXPECT_EQ( 4,show_n());
	for(int i=0;i<7;i++) EXPECT_EQ( INF, show_node(i));

	init(4);
	EXPECT_EQ( 4,show_n());
	
	init(5);
	EXPECT_EQ(8,show_n());

	init(8);
	EXPECT_EQ(8,show_n());

	init(14);
	EXPECT_EQ(16,show_n());
	for(int i=0;i<31;i++) EXPECT_EQ( INF, show_node(i));

	init(1<<16);
	EXPECT_EQ(1<<16,show_n());

}

TEST_F(MySegtreeTest, update){
	//test update
	init(15);
	update(3,99);
	EXPECT_EQ(99,show_node(0));
	EXPECT_EQ(99,show_node(16+3-1));

	update(14,98);
	EXPECT_EQ(98,show_node(0));	
	EXPECT_EQ(98,show_node(16+14-1));

	update(12,100);
	EXPECT_EQ(98,show_node(0));	
	EXPECT_EQ(100,show_node(16+12-1));

	//over write
	update(12,90);
	EXPECT_EQ(90,show_node(0));	
	EXPECT_EQ(90,show_node(16+12-1));	
}

TEST_F(MySegtreeTest, query){
	init(15);
	for(int i=0;i<15;i++) update(i,i);

	for(int i=0;i<15;i++) for(int j=i+1;j<15;j++){
		int q = query(i,j,0,0,16);
		EXPECT_EQ(i,q);
	}
}

} // namespace