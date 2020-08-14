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
		ll n=0;
		string str;
		cin>>str;
		
		int s = 0 , e = str.length()-1;
		
		while( s<=e && str[s]=='0')s++;
		while( s<=e && str[e]=='0')e--;
		
		for(int i = s ; i <=e ; i++){
			if(str[i]=='0')n++;
		}
		cout<<n;
		cout<<endl;
	}
	return 0;
}