#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;

ll d,x,y;
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
int main(){
	SLAY
	int _=1 , tc=1;
	cin>>_;
	ll n,m;
	while(_--){
		cin>>n>>m;
		ll a = n/m , b = ceil(1.0*n/m);
		extended_gcd(a , b);
		cout<< x * n / d << " " << y * n / d;
		cout<<endl;
	}
	return 0;
}