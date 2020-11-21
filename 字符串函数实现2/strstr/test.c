#include<stdio.h>
#include<assert.h>
const char* my_strstr(const char* str, const char* str_stu)
{
	assert(str);
	assert(str_stu);
	while (*str) {
		const char* p = str;
		const char* q = str_stu;
		while (*p && *q && *p == *q) {
			p++;
			q++;
		}
		if (*q == '\0') {
			return str;
		}
		str++;
	}
	return NULL;
}
int main()
{
	const char* str = "asdgh 147 1234 dwasd";
	char* str_stu = "1234";
	printf("%s\n", my_strstr(str, str_stu));
	return 0;
}