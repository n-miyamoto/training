#include "gtest/gtest.h"
#include "mysqdiv.h"

namespace {

class MySqdivTest: public ::testing::Test{
};

TEST_F(MySqdivTest, sqdiv_init)
{
	sqdiv_init(1);
	EXPECT_EQ(1,sqdiv_show_n());	

	sqdiv_init(4);
	EXPECT_EQ(2,sqdiv_show_n());

	sqdiv_init(5);
	EXPECT_EQ(3,sqdiv_show_n());

	sqdiv_init(300*300);
	EXPECT_EQ(300,sqdiv_show_n());

}

TEST_F(MySqdivTest, sqdiv_update)
{
	sqdiv_init(14);
	EXPECT_EQ(4,sqdiv_show_n());

	int N = sqdiv_show_n();
	for(int i=0;i< N;i++) EXPECT_EQ(INF,sqdiv_show_node(i));
	for(int i=0;i<14;i++) update_bkt(i,i);
	
	EXPECT_EQ( 0,sqdiv_show_node(0));
	EXPECT_EQ( 4,sqdiv_show_node(1));
	EXPECT_EQ( 8,sqdiv_show_node(2));
	EXPECT_EQ(12,sqdiv_show_node(3));

}


TEST_F(MySqdivTest, req)
{
	sqdiv_init(14);

	for(int i=0;i<14;i++) update_bkt(i,i);
	for(int i=0;i<14;i++) for(int j=i+1;j<14;j++){
		EXPECT_EQ(i,req(i,j));
	}

	for(int i=0;i<14;i++) update_bkt(i,13-i);
	for(int i=0;i<14;i++) for(int j=i+1;j<14;j++){
		EXPECT_EQ(13-j,req(i,j));
	}



}

} // namespace	