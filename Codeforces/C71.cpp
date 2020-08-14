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
vector<int> getDiv(int N){
	vector<int> ret;
	for(int i=1;i*i<=N ; i++){
		if(N%i==0 && N/i >2){
			if(N/i == i)ret.push_back(i);
            else{ 
                ret.push_back(i);
                if(N/(N/i)>2)ret.push_back(N/i); 
            } 
		}
	}
	return ret;
}
int main(){SLAY
	int _=1 , tc=1;
	// cin>>_;
	while(_--){
		ll n;
		cin>>n;
		vector<int> divs = getDiv(n);
		vector<int> v(n);
		for(int i = 0;i<n;i++){
			cin>>v[i];
		}
		bool ok= false;
		for(int i = 0;i<divs.size();i++){
			int curr = divs[i];
			int sum = 0 , target = n/curr;
			for(int start = 0 ; start< curr; start++){
				sum = 0;
				for(int j = 0 ; j<target ; j++){
					sum += v[ (start+ j*curr) %n];
				}
				
				if(target == sum ){
					ok=true;
					break;
				}
			}
			if(ok)break;
		}
		if(ok)cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}