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
	// cin>>_;
	while(_--){
		int n,a,b,k , levels=0;
		cin>>n>>k;
		vector<int>v(n);
		vector<int>c(k);
		vector<int> freq(k);
		vector<int> suff(k+1);
		vector<int> next;
		for(int i = 0 ;i <n;i++){
			cin>>v[i];
			freq[v[i]-1]++;
		}
		for(int i = 0 ;i <k;i++){
			cin>>c[i];
		}
		sort(v.begin(),v.end());
		
		for(int i = k-1;i>=0;i--){
			suff[i]=freq[i]+suff[i+1];
		}
		
		for(int i = 0 ;i <k;i++){
			levels = max( levels,(int)ceil(1.0*suff[i]/c[i]));
		}
		cout<<levels<<endl;;
		vector< vector<int> >ans(levels);
		
		for(int i =0;i<n;i++){
			ans[i%levels].push_back(v[i]);
		}

		for(int i = 0 ; i<ans.size() ; i++){
			cout<<ans[i].size()<<" ";
			for(int j = 0 ; j<ans[i].size() ; j++)cout<<ans[i][j]<<" ";
			cout<<endl;
		}
		
		cout<<endl;
	}
	return 0;
}
