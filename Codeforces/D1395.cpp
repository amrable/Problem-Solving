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

int cost(int x ,int y){
	return ((~x)&y);
}
int solve_(int i , int curr ,vector<  vector<int> >&dp, vector< vector<int> >&v){
	if(i==v.size())return 0;
	int& ret =dp[i][curr];
	if(~ret)return ret;
	ret = INT_MAX;
	for(int j = 0 ; j<v.size();j++){
		ret = min(ret , cost(curr , v[i][j]) + solve_(i+1 , curr|v[i][j] , dp ,v));
	}
	return ret;
}

void solve(){
	ll n ,m , d;
	cin>>n>>d>>m;
	vector<ll> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	int j = 0 , i;
	ll ans = 0;
	for(i=n-1;i>=0;i--){
		ll c = d , cost = 0;
		if(a[i]<=m)break;
		while(c-- && j<i){
			cost += a[j];
			j++;
		}
		if(c>0){
			ans+=a[i];
			int done = (n-i)*d;
			for(int j = max(0,done) ; j<i ; j++){
				if(a[j]>m)break;
				ans+=a[j];
			}
			cout<<ans;	
			return;
		}else{
			if(cost>=a[i]){
				int j = (n-i-1)*d;
				while(j<i && a[j]<=m)ans+=a[j];
				cout<<ans;
				return;
			}else{
				ans+=a[i];
			}
		}
	}
	int done = (n-i-2)*d;
	for(int j = max(0,done) ; j<i ; j++){
		ans+=a[j];
	}
	cout<<ans;

}
int main(){
	SLAY
	// cin>>_;
	while(_--){
		solve();
	}
	return 0;
}