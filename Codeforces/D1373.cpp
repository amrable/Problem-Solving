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

ll maxSubArraySum(vector<ll>& a){ 
   if(a.size()==0)return 0;
   ll max_so_far = a[0]; 
   ll curr_max = a[0]; 
  
   for (int i = 1; i < a.size(); i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 

int main(){SLAY
	int _=1 , tc=1;
	cin>>_;
	while(_--){
		ll n=0;
		string str;
		cin>>n;
		vector<ll>v(n);
		vector<ll>even;
		vector<ll>odd;
		vector<ll>pre;
		ll even_tot=0,odd_tot=0;
		
		for(int i = 0 ; i <n ; i++){
			cin>>v[i];
			if(i%2){
				odd.push_back(v[i]);
				odd_tot+=v[i];
			}else{
				even.push_back(v[i]);
				even_tot+=v[i];
			}
		}
		ll ans = even_tot;
		pre.clear();
		for(int i = 1; i<n ; i += 2){
			ll temp=v[i]-v[i-1];
			pre.push_back(temp);
		}
		ans = max(ans , even_tot + maxSubArraySum(pre));
		pre.clear();
		for(int i = 1; i<n-1 ; i += 2){
			ll temp=v[i]-v[i+1];
			pre.push_back(temp);
		}
		ans = max(ans , even_tot + maxSubArraySum(pre));
		
		
		
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
