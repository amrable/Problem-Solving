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

vector<int> getDivisors(int n) { 
    vector<int>ret;
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0){ 
            // If divisors are equal, print only one 
            if (n/i == i) 
                ret.push_back(i);
  
            else {
            	ret.push_back(i);
            	ret.push_back(n/i);
            }
        } 
    } 
    
    return ret;
} 

int main(){SLAY
	int _=1 , tc=1;
	// cin>>_;
	while(_--){
		int n,x,ans=0,tot;
		cin>>n>>x;
		vector<int>divs=getDivisors(x);
		
		for(int i=0;i<divs.size();i++){
			if(divs[i] <= n && x/divs[i] <=n )ans++;
		}
		
			
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
