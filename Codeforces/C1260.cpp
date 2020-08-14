#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
using namespace std;
ll gcd(ll a , ll b){
	if(b==0)return a;
	return gcd(b , a%b);
}
ll lcm(ll a, ll b){  
    return (a*b)/gcd(a, b);  
}  
void solve(){
	ll r,b,k;
	cin>>r>>b>>k;
	if(r>b)swap(r,b);
	
	ll l = lcm(r,b);
	ll rs = l/r - 1;
	ll bs = l/b;
	
	ll dist = rs/bs + (int) (rs%bs!=0);
	if(dist<k)cout<<"OBEY";
	else cout<<"REBEL";
	cout<<endl;
}
int main(){
	SLAY
	int _=1 , tc=1;
	cin>>_;
	ll n,m;
	while(_--){
		solve();
	}
	return 0;
}