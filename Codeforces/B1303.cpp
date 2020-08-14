#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("travel_restrictions_validation_input.txt", "r", stdin);
using namespace std;
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 , -1 , 0 , 0};
int getmod(int x, int y , int mod ){return (((x - y)%mod)+mod)%mod;}
int main(){SLAY
	int _=1 , tc=1;
	cin>>_;
	while(_--){
		ll n,g,b;
		cin>>n>>g>>b;
		
		ll gs = (n/2+n%2)/g;
		ll extrag = (n/2+n%2)%g;
		ll bs = (n/2)/b;
		ll extrab = (n/2)%b;
	
		ll days = gs*(g+b)-b;
		ll bad_left = gs*b - b;
		
		if(extrag>0){
			days+= (b+extrag);
			bad_left +=b;
		}
		
		if(n/2 >bad_left)days+= (n/2 - bad_left);
		cout<<days;
		cout<<endl;
	}
	return 0;
}