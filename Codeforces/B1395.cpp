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
void solve(){
	ll n,m,s1,s2;
	cin>>n>>m>>s1>>s2;
	cout<<s1<<" "<<s2<<endl;
	for(int i = 1 ; i<=m ; i++){
		if(i==s2)continue;
		cout<<s1<<" "<<i<<endl;
	}
	int curr = m , new_curr=m;
	for(int i = s1-1 ; i>=1 ; i--){
		if(curr == m){
			for(int j = m ; j>0 ; j-- ){
				cout<<i<<" "<<j<<endl; 
			}
			curr=1;
		}else{
			for(int j = 1 ; j<=m ; j++ ){
				cout<<i<<" "<<j<<endl; 
			}
			curr=m;
		}
	}
	
	for(int i = s1+1 ; i<=n ; i++){
		if(curr == m){
			for(int j = m ; j>0 ; j-- ){
				cout<<i<<" "<<j<<endl; 
			}
			curr=1;
		}else{
			for(int j = 1 ; j<=m ; j++ ){
				cout<<i<<" "<<j<<endl; 
			}
			curr=m;
		}
	}
	
}
int main(){
	SLAY
	// cin>>_;
	while(_--){
		solve();
	}
	return 0;
}