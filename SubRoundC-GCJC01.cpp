#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#define LOCAL
using namespace std;

long long kgcd(long long a, long long b){
if (a == 0) return b;
if (b == 0) return a;
if (!(a & 1) && !(b & 1)) return kgcd(a>>1, b>>1) << 1;
else if (!(b & 1)) return kgcd(a, b>>1);
else if (!(a & 1)) return kgcd(a>>1, b);
else return kgcd(abs(a - b), min(a, b));}

int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long num,den;
		scanf("%d/%d",&num,&den);
		long long nd=kgcd(num,den);
		num/=nd;den/=nd;
		double den2=log(den)/log(2);
		if(den2-int(den2)!=0)
			cout<<"Case #"<<i+1<<": "<<"impossible"<<endl;
		else
		{
			int j=0;
			while(1/pow(2,j)>double(num)/double(den))
				j++;
			cout<<"Case #"<<i+1<<": "<<j<<endl;
		}
	}
	return 0;
}
