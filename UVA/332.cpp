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
ll d,x,y;
ll gcd(ll a , ll b){
	if(b==0)return a;
	return gcd(b , a%b);
}
ll mypow(ll x, int y)  {  
    ll temp;  
    if(y == 0)return 1;  
    temp = mypow(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else{  
        if(y > 0)return x * temp * temp;  
        else return (temp * temp) / x;  
    }  
}  
  
int main(){
	SLAY
	int _=1 , tc=1;
	// cin>>_;
	// sieve();
	ll x10[11];
	x10[0]=1;
	ll curr =1;
	for(int i = 1;i<=10;i++){
		x10[i]= 10*x10[i-1];
	}
	string str;
	ll n;
	while(true){
		cin>>n>>str;
		if(n<0)break;
		ll len = str.length();
		ll tot = str.length()-2;
		ll p=0,d,q;
		for(int i = 2;i<len;i++){
			int d = str[i]-'0';
			p*=10;
			p+=d;
		}
		if(n!=0){
			p -= p/x10[n];
			q = x10[tot] - x10[tot-n];
		}else{
			q = x10[tot];
		}
		ll g = gcd(p,q);
		cout<<"Case "<<tc++<<": "<<p/g<<"/"<<q/g;
		cout<<endl;
	}
	return 0;
}
