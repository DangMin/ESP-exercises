#include <gtest/gtest.h>
#include "string.h"
#include <string.h>

TEST(StringLength, EmptyString) {
	char s[] = {'\0'};
	ASSERT_EQ(0, my_strlen(s));
}

TEST(StringLength, StringWithLength) {
	char s[5][30] = {"Hello World!", "3Ig5cdIUV3", "p4pNbq1HoB8t6nO", "SEUeiq", "CA3ZW8ZGFFs372uMrwp"};
	int len[5] = {12, 10, 15, 6, 19};
	int i = 0;

	while (i<5) {
		ASSERT_EQ(len[i], my_strlen(s[i]));
		++i;
	}
}

TEST(StringCopy, CopyEmptyString) {
	char s[] = "", d[100];
	mystrcpy(s, d);
	ASSERT_STREQ("", d);
}

TEST(StringCopy, CopyStringWithLength) {
	char s[] = "dJWEMv06nyA4M7Q6PRf", d[100];
	mystrcpy(s, d);
	ASSERT_STREQ("dJWEMv06nyA4M7Q6PRf",d);
	ASSERT_EQ(my_strlen(s), my_strlen(d));
}

TEST(StringCopy, CopyStringToPredefinedString) {
	char s[] = "dafdfalkdsfajsldkfa", d[] = "sadjflaksdfaskldfaj";
	mystrcpy(s, d);
	ASSERT_STREQ("dafdfalkdsfajsldkfa", d);
}

TEST(StringCompare, NoDifferent) {
	char s[100] = "t7gPYeTV4g9UvRaihyi", d[100] = "t7gPYeTV4g9UvRaihyi";
	ASSERT_EQ(0, mystrcmp(s, d));
}

TEST(StringCompare, PositiveCase) {
	char s[100] = "t7APYeTV4g9UvRaihyi", d[100] = "t7gPYeTV4g9UvRaihyi";
	ASSERT_EQ(2, mystrcmp(s, d));
}

TEST(StringCompare, NegativeCase) {
	char s[100] = "t7gPYeTV4g9UvRaihyi", d[100] = "t7gPYeTV4g1UvRaihyi";
	ASSERT_EQ(-10, mystrcmp(s, d));
}

TEST(StringCompare, LongVsShort) {
	char s[100] = "t7gPYeTV4g1Uv", d[100] = "t7gPYeTV4g1UvRaihyi";
	ASSERT_EQ(13, mystrcmp(s, d));
}

TEST(StringCompare, ShortVsLong) {
	char s[100] = "t7gPYeTV4g9UvRaihyi", d[100] = "t7gPY";
	ASSERT_EQ(-5, mystrcmp(s, d));
}

TEST(StringToUpper, NoLetters) {
	char s[100] = "SADFBNLSKSLFKASJDL";
	ASSERT_EQ(0, str2upper(s));
	ASSERT_STREQ("SADFBNLSKSLFKASJDL", s);
}

TEST(StringToUpper, LettersToBeTransform) {
	char s[100] = "p53cbtJa3p5UhzmOs";
	ASSERT_EQ(10, str2upper(s));
	ASSERT_STREQ("P53CBTJA3P5UHZMOS", s);
}

TEST(StringToLower, NoLetters) {
	char s[100] = "z3rkl9lj6br4";
	ASSERT_EQ(0, str2lower(s));
	ASSERT_STREQ("z3rkl9lj6br4", s);
}

TEST(StringToLower, StringWithUpper) {
	char s[100] = "Z3RKL9lJ6bR4";
	ASSERT_EQ(6, str2lower(s));
	ASSERT_STREQ("z3rkl9lj6br4", s);
}

TEST(StringToLower, StringWithLower) {
	char s[100] = "asdjfj39jelfsls13asf";
	ASSERT_EQ(0, str2lower(s));
	ASSERT_STREQ("asdjfj39jelfsls13asf", s);
}

TEST(StringStripNumbers, MyTest) {
	unsigned char s[100] = "jcMU96eWIR4t0OjnO";
	int i = str_strip_numbers(s);
	ASSERT_EQ(13, str_strip_numbers(s));
	ASSERT_STREQ("jcMUeWIRtOjnO", (char*)s);
}

TEST(StringDuplicate, EmptyString) {
	char s[10] = "", *d;
	d = strdupl(s);
	ASSERT_STREQ("", d);
}

TEST(StringDuplicate, StringWithContent) {
	char s[100] = "dfDLKf:dfjsdflsk1049", *d;
	d = strdupl(s);
	ASSERT_STREQ("dfDLKf:dfjsdflsk1049", d);
}