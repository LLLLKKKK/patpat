#include<iostream>
#include<algorithm>
using namespace std;
int a[1000001],b[1000001];
int main()
{
 int nc,np;
 int i,j;
  cin>>nc;
  for(i=0;i<nc;i++)
   cin>>a[i];
  sort(a,a+nc);
  cin>>np;
  for(i=0;i<np;i++)
   cin>>b[i];
  sort(b,b+np);
  long long sum=0;
  for(i=0,j=0;a[i]<0&&b[j]<0&&i<nc&&j<np;i++,j++)
   sum+=((long long)a[i])*b[j];
  for(i=nc-1,j=np-1;a[i]>0&&b[j]>0&&i<nc&&j<np;i--,j--)
   sum+=((long long)a[i])*b[j];
  cout<<sum<<endl;

 return 0;
}
