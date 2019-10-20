#define _CRT_SECURE_NO_WARNINGS 1
#include"ViolentMatch.h"
//指针
char * ViolentMatch(const char *str1, const char *str2)
{
	assert(str1);
	assert(str2);

	char *src = (char *)str1;
	char *sub = (char *)str2;
	char *flag;

	while (*src)
	{
		flag = src;
		while (*flag&&*sub && (*flag == *sub))
		{
			flag++;
			sub++;
		}
		if (!(*sub))
		{
			return src;
		}
		else
		{
			src++;
			sub = str2;
		}
	}
	return;
}

//返回第一个字符的下标
int  int_ViolentMatch(const char *str1, const char *str2)
{
	int str1_Len = strlen(str1);
	int str2_Len = strlen(str2);

	int i = 0;
	int j = 0;
	while (i<str1_Len&&j<str2_Len)
	{
		if (str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == str2_Len)
	{
		return i - j;
	}
	else 
		return -1;
}
