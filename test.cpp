#include <bits/stdc++.h>
#include "gtest/gtest.h"

using  namespace std;
/*TEST(SquareRootTest, PositiveNos) { 
    EXPECT_EQ(6, pow(36.0,0.5));
    EXPECT_EQ(18.0, pow(324.0,0.5));
    EXPECT_EQ(25.4,pow(645.16,0.5));
    EXPECT_EQ(0, pow(0.0,0.5));
}
//THIS ONE FAILS 
TEST(SquareRootTest, NegativeNos) {
    EXPECT_EQ(-1.0, pow(-15.0,0.5));
    EXPECT_EQ(-1.0, pow(-0.2,0.5));
}*/

TEST(Casting,INTEGERtoLONG)
{
srand(time(0));
for(int i=0;i<10000;i++)
	{
	int num=rand();
	EXPECT_EQ(num,(long)num);

	}
}
TEST(PRECISION,FLOATPREC)
{
srand(time(0));float a=100000;
for (int i=0;i<10000;i++)
{
float num=(rand()/RAND_MAX)*a	;
double temp=(double)(num);
EXPECT_LE(fabs(temp*temp-num*num),0.01);

}

}
TEST(VECTOR,0elements)
{
vector <int> v1,v2;
EXPECT_EQ(v1,v2);

}
TEST(VECTOR,greaterthanzeroelements)
{
vector<int> v1,v2,v3;
for(int i=0;i<10000;i++)
{
int temp=rand();
v1.push_back(temp);
v2.push_back(temp);
}
v3=v1;
EXPECT_EQ(v1,v2);
EXPECT_EQ(v1,v3);
EXPECT_EQ(v3,v2);



}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
