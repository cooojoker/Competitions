//#define LOCAL
#define MOD 1000000007
#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	long long n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long tmp,tmp2,sum=0;
		cin>>n;
		if(n>=MOD) n%=MOD;
		tmp=((1+n)*n/2)%MOD;
		tmp2=(tmp*tmp)%MOD;
		sum+=tmp-(2*n)%MOD+2;
		sum*=tmp2;
		sum%=MOD;
		//cout<<n<<" "<<tmp<<" "<<tmp2<<" "<<tmp-(2*n)%MOD+2<<endl;
		cout<<"Case "<<i+1<<": "<<int(sum)<<endl;
	}
	return 0;
}
