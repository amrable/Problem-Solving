#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
using namespace std;
int _=1 , tc=1;
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 , -1 , 0 , 0};
int getmod(int x, int y , int mod ){return (((x - y)%mod)+mod)%mod;}
int MAXN = 46341 + 1;
int spf[46341+1];
int d,x,y;
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
void extended_gcd(int a , int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}else{
		extended_gcd(b,a%b);
		int temp = y;
		y = x - y * (a/b);
		x = temp;	
	}
}
ll gcd(ll a , ll b){
	if(b==0)return a;
	return gcd(b , a%b);
}
ll lcm(ll a, ll b){  
    return (a*b)/gcd(a, b);  
}
void solve(ll n, ll m){
	
	vector< pii > v(m);
	for(int i=0;i<m;i++){
		int x,r;
		cin>>x>>r;
		v[i].first = max(0,x-r);
		v[i].second = min((int)n,x+r);
	}
	sort(v.begin(),v.end());
	
	int r = 0, i=0 , ans = m;
	
	while(r<n){
		int newr = r;
		while(i<m && v[i].first <= r){
			if(newr<v[i].second)newr=v[i].second;
			i++;
		}
		if(r==newr)break;
		r = newr;
		ans--;
	}
	if(r<n)cout<<"-1\n";
	else cout<<ans<<endl;;

}
int main(){
	SLAY
	// cin>>_;
	while(true){
		ll n,m;
		cin>>n>>m;
		if(n==0 && m == 0)break;
		solve(n,m);
	}
	return 0;
}