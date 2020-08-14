#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 , -1 , 0 , 0};
int getmod(int x, int y , int mod ){return (((x - y)%mod)+mod)%mod;}

// sieve
int MAXN = 46341 + 1;
int spf[46341+1];
int gcd(int a , int b){
	if(b==0)return a;
	return gcd(b , a%b);
}
void sieve(){
	for(int i = 1 ; i<MAXN ; i++)spf[i]=i;
	for(int i = 4 ; i<MAXN ; i+=2)spf[i]=2;
	for(int i = 3; i*i<MAXN; i+=2){
		if(spf[i]==i){
			for(int j = i*i ; j<MAXN ; j+=i){
				if(spf[j]==j)spf[j]=i;
			}
		}
	}
}
int get_len(ll x){
	int ret=10;
	while(x){
		ret--;
		x/=10;
	}
	return ret;
}
int main(){
	// SLAY
	// int _=1 , tc=1;
	// cin>>_;
	// sieve();
	ll n,m;
	while(cin>>n>>m){
		bool ok=true;
		if(gcd(n,m)!=1){
			ok=false;
		}	
		int limit=get_len(n);
		for(int i = 0 ;i<limit ; i++)cout<<" ";
		cout<<n;
		
		limit=get_len(m);
		for(int i = 0 ;i<limit ; i++)cout<<" ";
		cout<<m;
		cout<<"    ";
		if(ok)cout<<"Good Choice\n";
		else cout<<"Bad Choice\n";
		cout<<endl;
	}
	return 0;
}
