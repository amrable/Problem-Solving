#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;

int cnt[100001];
int main(){
	SLAY
	int _=1 , tc=1;
	ll n,m;
	while(_--){
		memset(cnt ,0, sizeof(cnt));
		cin>>n;
		vector<int>v(n);
		set<int> s;
		multiset<int> counts;
		for(int i=0;i<n;i++){
			cin>>v[i];
			cnt[v[i]]++;
			s.insert(v[i]);
		}
		for(int x: s){
			counts.insert(cnt[x]);
		}
		cin>>m;
		for(int i =0;i<m;i++){
			char c ;
			int val;
			cin>>c>>val;
			if(c=='+'){
				int was = cnt[val];
				cnt[val]++;
				counts.insert(cnt[val]);
				if(was != 0)counts.erase(counts.find(was));
			}else{
				int was = cnt[val];
				cnt[val]--;
				if(cnt[val]!=0)counts.insert(cnt[val]);
				counts.erase(counts.find(was));
			}
			int x=0 , y=0 , z=0 ;
			multiset<int>::reverse_iterator itr; 
			int j = 0;
		    for (itr = counts.rbegin(); itr != counts.rend(); ++itr) { 
		    	if(j==0){
		    		x = *itr;
		    	}else if(j==1){
		    		y = *itr;
		    	}else if(j==2){
		    		z = *itr;
		    	}else break;
		        j++;
		    } 
			// cout<<x<<" "<<y<<" "<<z<<endl;
			if(x>=8)cout<<"YES";
			else if(x>=6 && y>=2)cout<<"YES";
			else if(x>=4 && y>=4)cout<<"YES";
			else if(x>=4 && y>=2 && z>=2)cout<<"YES";
			else cout<<"NO";
			cout<<endl;
		}
	}
	return 0;
}