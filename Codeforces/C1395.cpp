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
	for(int j = 0 ; j<v[0].size();j++){
		ret = min(ret , cost(curr , v[i][j]) + solve_(i+1 , curr|v[i][j] , dp ,v));
	}
	return ret;
}

void solve(){
	ll n , m;
	cin>>n>>m;
	vector<int>a(n);
	vector<int>b(m);
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	for(int i =0;i<m;i++){
		cin>>b[i];
	}
	vector< vector<int> > v(n , vector<int>(m));
	vector< vector<int> > dp(n,vector<int>(1024,-1));
	for(int i =0;i<n ; i++){
		for(int j=0;j<m;j++){
			v[i][j]=(a[i]&b[j]);
		}
	}

	cout<<solve_(0, 0 , dp , v);
}
int main(){
	SLAY
	// cin>>_;
	while(_--){
		solve();
	}
	return 0;
}