/**
 * Unit Tests for Practice class
**/

#include <gtest/gtest.h>
#include "Practice.h"
#include <climits>

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PracticeTest, sortPositives)
{
    Practice obj;
    int a = 1;
    int b = 2;
    int c = 3;
    obj.sortDescending(a, b, c);
    ASSERT_TRUE(a == 3);
    ASSERT_TRUE(b == 2);
    ASSERT_TRUE(c == 1);
}

TEST(PracticeTest, sortNegatives)
{
    Practice obj;
    int a = -3;
    int b = -2;
    int c = -1;
    obj.sortDescending(a, b, c);
    ASSERT_TRUE(a == -1);
    ASSERT_TRUE(b == -2);
    ASSERT_TRUE(c == -3);
}

TEST(PracticeTest, sortMixedSigns)
{
    Practice obj;
    int a = 1;
    int b = -2;
    int c = 2;
    obj.sortDescending(a, b, c);
    ASSERT_TRUE(a == 2);
    ASSERT_TRUE(b == 1);
    ASSERT_TRUE(c == -2);
}

TEST(PracticeTest, sortPresortedMixedSigns)
{
    Practice obj;
    int a = 50;
    int b = 30;
    int c = -20;
    obj.sortDescending(a, b, c);
    ASSERT_TRUE(a == 50);
    ASSERT_TRUE(b == 30);
    ASSERT_TRUE(c == -20);
}

//A more complex sorting test.
//UINT_MAX will overflow the int type and become negative.
//The final outcome will be INT_MAX > (int)UINT_MAX > INT_MIN.
//This is not ideal behavior, but is a limitation of the language.
//This overflow bug occuring but the test passing is a good sign for the algorithm.
TEST(PracticeTest, sortWithOverflowBug)
{
    Practice obj;
    int a = INT_MIN;
    int b = (int)UINT_MAX; 
    int c = INT_MAX;
    obj.sortDescending(a, b, c);
    ASSERT_FALSE(a == (int)UINT_MAX); //the (int) casts get rid of compiler warnings
    ASSERT_FALSE(b == INT_MAX);
    ASSERT_TRUE(a == INT_MAX);
    ASSERT_TRUE(c == INT_MIN);
}

TEST(PracticeTest, is_short_simple_palindrome)
{
    Practice obj;
    bool actual = obj.isPalindrome("aa");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("aaa");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("ABBA");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("ALVLA");
    ASSERT_TRUE(actual);
}

TEST(PracticeTest, is_not_short_simple_palindrome)
{
    Practice obj;
    bool actual = obj.isPalindrome("abc");
    ASSERT_FALSE(actual);
    actual = obj.isPalindrome("abc");
    ASSERT_FALSE(actual);
}

TEST(PracticeTest, is_long_simple_palindrome)
{
    Practice obj;
    bool actual = obj.isPalindrome("anutforajaroftuna");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("BorroWorroB");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("tacocat");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("murderforajarofredrum");
    ASSERT_TRUE(actual);
}

TEST(PracticeTest, is_not_long_palindrome)
{
    Practice obj;
    bool actual = obj.isPalindrome("sallysoldseashellsbytheseashore");
    ASSERT_FALSE(actual);
    actual = obj.isPalindrome("ashipandastartostearherby");
    ASSERT_FALSE(actual);
    actual = obj.isPalindrome("romainvicta");
    ASSERT_FALSE(actual);
    actual = obj.isPalindrome("yohohoandabottleorum");
    ASSERT_FALSE(actual);
}

TEST(PracticeTest, is_long_complex_palindrome)
{
    Practice obj;
    bool actual = obj.isPalindrome("ANUTFORAjaroftuna");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("BoRROWorroB");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("taCOCat");
    ASSERT_TRUE(actual);
    actual = obj.isPalindrome("muRDERforaJARofredrum");
    ASSERT_TRUE(actual);
}

//An empty string is not a palindrome and should return false by default
TEST(PracticeTest, is_empty_string)
{
    Practice obj;
    bool actual = obj.isPalindrome("");
    ASSERT_FALSE(actual);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
