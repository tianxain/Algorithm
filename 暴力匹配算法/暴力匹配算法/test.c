#define _CRT_SECURE_NO_WARNINGS 1
#include"ViolentMatch.h"
int main()
{
	char str1[] = "hello World";
	char str2[] = "Wor";
	char *ret = ViolentMatch(str1, str2);
	printf("%c\n", *ret);

	int int_ret = int_ViolentMatch(str1, str2);
	printf("%d", int_ret);
	return 0;
}