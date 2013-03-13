#include<iostream>
using namespace std;
#include<memory.h>

int map[1001][1001];
int sto[1001][1001];
int city;
int way;
int num;

void dfs(int k)
{
	sto[0][k]=1;
	for(int i=1;i<=city;i++)
	{
		if(sto[k][i]==1&&sto[0][i]==0)
		{
			dfs(i);
		}
	}
}

int main()
{

	int a;
	int b;
	int occupy;
	int count;
	
	cin>>city;
	cin>>way;
	cin>>num;

	memset(map,0,sizeof(map));
	
	for(int i=0;i<way;i++)
	{
		cin>>a;
		cin>>b;
		map[a][b]=1;
		map[a][0]++;
		map[b][a]=1;
		map[b][0]++;
	}

	for(int i=0;i<num;i++)
	{
		memcpy(sto,map,sizeof(sto));
		cin>>occupy;
		count=0;
		for(int i=1;i<=city;i++)
		{
			if(sto[occupy][i]==1)
			{
				sto[occupy][i]=0;
				sto[i][occupy]=0;	
			}
		}

	
		for(int i=1;i<=city;i++)
		{
			if(sto[0][i]==0&&i!=occupy)
			{
				count++;
				dfs(i);
			}
		}

		cout<<count-1<<endl;

	}

}

