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
		
		ll min_balance = 0 , curr_balance=0 , ans = 0;
		n = str.length();
		for(int i = 0 ;i<n ;i++){
			if(str[i]=='-'){
				curr_balance--;
			}else curr_balance++;
			
			if(curr_balance<min_balance){
				ans+= (i+1);
				min_balance = curr_balance; 
			}
		}
		ans+=n;
		
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
