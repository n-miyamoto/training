#include "gtest/gtest.h"
#include "myunionfind.h"

namespace {

class MyUnionfindTest: public ::testing::Test{
};

TEST_F(MyUnionfindTest, find )
{
	uf_init(100000);
	for(int i=0;i<100000;i++){
		EXPECT_EQ(i,find(i));
	}
}

TEST_F(MyUnionfindTest, unite )
{
	uf_init(100000);
	for(int i=0;i<100000;i++){
		if(i%2==0) unite(0,i);
	}

	for(int i=0;i<100000;i++){
		if(i%2==0)EXPECT_EQ(0,find(i));
	}

}


TEST_F(MyUnionfindTest, same)
{
	uf_init(100000);
	for(int i=0;i<100000;i++){
		if(i%2==0) unite(0,i);
		else unite(1,i);
	}

	for(int i=0;i<100000;i++){
		if(i%2==0)EXPECT_EQ(0,find(i));
		else EXPECT_EQ(1,find(i));
	}

	for(int i=0;i<10000;i++){
		for(int j=i+1;j<10000;j++){
			if((i+j)%2==0) EXPECT_EQ(true,same(i,j));
			else EXPECT_EQ(false,same(i,j));
		}
	}

}

} // namespace	