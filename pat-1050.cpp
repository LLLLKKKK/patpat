#include <cstdio>
#include <cstring>

int main()
{
char str[10005]={0};
char str1[10005]={0};
int ss[256] = {0};
	gets(str);
	gets(str1);
	int i=0;
	
	while(str1[i]!='\0')
		ss[str1[i++]] = 1;
	i=-1;
	while(str[++i]!='\0')
		if (!ss[str[i]])
			putchar(str[i]);
	putchar('\n');
	return 0;
}

