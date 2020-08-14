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
int d,x,y;
ll gcd(ll a , ll b){
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
ll lcm(ll a, ll b)  {  
 	return (a*b)/gcd(a, b);  
}  

vector<int> getdiv(int n){
	vector<int> ret;
	for(int i = 1 ; i*i<=n;i++){
		if(n%i == 0){
			if(n/i == i)ret.push_back(i);
			else{
				ret.push_back(i);
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}
int main(){
	SLAY
	int _=1 , tc=1;
	// cin>>_;
	// sieve();
	ll n,m;
	while(true){
		ll ans=0;
		cin>>n;
		if(n==0)break;
		
		vector<int>divs = getdiv(n);
		for(int i=0;i<divs.size();i++){
			for(int j=i+1;j<divs.size();j++){
				ll l = lcm(divs[i],divs[j]);
				if(l==n)ans++;
			}
		}
		cout<<n<<" "<<ans+1;
		cout<<endl;
	}
	return 0;
}