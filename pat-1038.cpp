#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
char nums[10000][9];
char* ns[10000];
bool my1( char* a, char*b )
{
	if ( strcmp( a, b ) == 0 )
		return true;
	int al, bl, i;
	al = strlen(a);
	bl = strlen(b);
	for ( i = 0; i < al && i < bl && a[i] == b[i]; ++ i );	
	if ( strcmp( a, b ) < 0 ) {
		if ( i < al )  
			return true;
		if ( strcmp(a, b+i) <= 0 ) 
			return true;
		return false;	
	}
	else {
		if ( i < bl )
			return false;
		if ( strcmp( a+i, b ) > 0 )
			return false; 
		return true;
	}
}
bool my(char*a, char*b)
{
int la = strlen(a);
int lb = strlen(b);

if (la==lb)
	return strcmp(a,b)<0;
else if (la<lb){
	int r = strncmp(a,b,la);
	if (r == 0)
		return strncmp(b+la,a,la)>0;
	return r<=0;
}
else
{
	int r = strncmp(b,a,lb);
	if (r == 0)
		return strncmp(a+lb,b,lb)<=0;
	return r>0;
}
}
int main()
{
	int n; scanf("%d", &n);
	for (int i=0;i<n;i++)
		{scanf("%s", nums[i]);
		ns[i]=nums[i];}
	sort(ns, ns+n,my); int f = 0;
	for (int i = 0;i<n;i++)
		for(int j=0;j<strlen(ns[i]);j++)
			{if (ns[i][j]!='0')f=1;
			if(f==1) putchar(ns[i][j]);}
	if(f==0)puts("0");
	puts("");
	return 0;
}
