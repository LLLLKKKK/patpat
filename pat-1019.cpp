#include <iostream>

using namespace std;

 

void convert(long n,long d){

int num[1000];

int i = 0,pos;

int flag = 0;

while (n){

num[i++] = n% d;

n /= d;

}

int j=0;

i--;

pos = i;

//cout <<"IJ:"<<i<<" "<<j<<endl; 

while (j<i){

if (num[i] != num[j]){

cout<<"No"<<endl; 

flag = 1;

break;

}

i--;j++;

}

if (!flag) cout<<"Yes"<<endl;

cout<<num[pos]; 

for (i = pos-1;i>=0;i--){

cout<<" "<<num[i];

}

cout<<endl; 

}

 

int main(){

long n,d;

cin>>n>>d;

convert(n,d);

return 0;

}


