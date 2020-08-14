#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;

ll x,y,d;
void extended_gcd(int a , int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}else{
		extended_gcd(b,a%b);
		double temp = y;
		y = x - y * (a/b);
		x = temp;	
	}
}

int main(){
	SLAY
	ll n;
	while(cin>>n && n){
		ll n1,n2,c1,c2;
		cin>>c1>>n1>>c2>>n2;
		extended_gcd(n1,n2);
		if(n%d){
			cout<<"failed\n";
			continue;
		}
		
		ll k = n/d;
		
		x *= k;
		y *= k;
		
		ll k1 = n2/d , k2 = n1/d;
		
		if(x<0){
			k = 0-(x/k1) + (int)(x%k1 != 0);
			x += k * k1;
			y -= k * k2;
		}
		if(y<0){
			k = 0-(y/k2) + (int)(y%k2 != 0);
			x -= k * k1;
			y += k * k2;
		}
		
		if(x<0 || y<0){
			cout<<"failed\n";
			continue;
		}
		
		k = x/k1;
		x -= k*k1;
		y += k*k2;
		
		ll x1 = x , y1 = y;
		
		k = y/k2;
		x += k*k1;
		y -= k*k2;
		
		ll x2 = x , y2 = y;
		
		if(c1*x1 + c2 * y1 < c1*x2 + c2 * y2){
			cout<<x1<<" "<<y1;
		}else{
			cout<<x2<<" "<<y2;
		}
		
		cout<<endl;
	}
	
	return 0;
}