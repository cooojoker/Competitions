//INCORRECT
//BETTER SOLUTION:COUNT THE 0 OR 1 NUM ON EACH BIT,AND SEE IF IT'S COMMONTARY. FOR EXAMP:N=5,
//A BIT HAS COMPARISON OF 2 2 OR 2 3 IS BOTH AVALIABLE,BUT LATER ONE NEEDS TO FLIP//
//!!!!SILLY ME!!!!
#define LOCAL
#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
string conv(int l,int id,string s)
{
	if(s[id]=='0') return s.substr(0,id)+'1'+s.substr(id+1,l-id);
	else return s.substr(0,id)+'0'+s.substr(id+1,l-id);
}

int main()
{
	#ifdef LOCAL
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	for(int it=0;it<t;it++)
	{
		int n,l;
		cin>>n>>l;
		vector<string> dev,out;
		string s;
		rep(i,0,n-1) {cin>>s;dev.push_back(s);}
		rep(i,0,n-1) {cin>>s;out.push_back(s);}
		sort(dev.begin(), dev.end());
		sort(out.begin(), out.end());
		bool res=true,flag=true;
		int round=0;
		rep(i,0,n-1) {if(dev[i]!=out[i]) flag=false;}
		if(flag) cout<<"Case #"<<it+1<<": "<<'0'<<endl;
		else
		{
			rep(i,1,l-1)
			{
				flag=true;
				rep(j,0,n-1) 
				if(dev[j].substr(0,i)!=out[j].substr(0,i)) flag=false;
				if(flag) {continue;}
				else
				{
					rep(k,0,n-1) dev[k]=conv(l,i-1,dev[k]);
					sort(dev.begin(), dev.end());
					flag=true;
					rep(j,0,n-1) if(dev[j].substr(0,i)!=out[j].substr(0,i)) flag=false;
					if(flag) round++;
					else {res=false;cout<<"Case #"<<it+1<<": "<<"NOT POSSIBLE"<<endl;break;}
				}
			}
			if(res)
			{
				flag=true;
				rep(j,0,n-1) 
				if(dev[j]!=out[j]) flag=false;
				if(flag) cout<<"Case #"<<it+1<<": "<<round<<endl;
				else
				{
					rep(k,0,n-1) dev[k]=conv(l,l-1,dev[k]);
					sort(dev.begin(), dev.end());
					flag=true;
					rep(j,0,n-1) if(dev[j]!=out[j]) flag=false;
					if(flag) {round++;cout<<"Case #"<<it+1<<": "<<round<<endl;}
					else {res=false;cout<<"Case #"<<it+1<<": "<<"NOT POSSIBLE"<<endl;}
				}
			}
		}
	}
	return 0;
}




