#include <bits/stdc++.h>
#define ll long long
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pll pair<ll,ll>
#define PI 3.141592653589793238

using namespace std;

class SegmentTree{
	public:
		int N;
		vector<ll> stree;
 
		SegmentTree(int n){
			N = n;
			stree.resize(N<<1);
		}
		
		void update_point(int index, ll val){
			index += N-1;
			stree[index]= val;
			while(index>1){
				index>>=1;
				stree[index]=max(stree[index<<1],stree[index<<1|1]);
			}
		}
 
		ll query(int i, int j){
			return query(1,1,N,i,j);
		}
 
		ll query(int node, int b, int e, int i, int j){
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j)
				return stree[node];
			int mid = b + (e-b)/2;
			ll q1 = query(node<<1,b,mid,i,j);
			ll q2 = query(node<<1|1,mid+1,e,i,j);
			return max(q1,q2);	
		}
};
 
int main(){
	ll n, N=1,ans=0;
	cin>>n;
	while(N<n)N<<=1;
	SegmentTree st(N);
	vector<pll> a(n+1);
	for(int i = 1 ;i<=n ; i++){
		ll r , h;
		cin>>r>>h;
		a[i].first = r*r*h;
		a[i].second = i;
	}
	sort(a.begin(),a.end());
	vector< pll > buff;
	for(int i = 1;i<=n;i++){
		ll temp = st.query(1 , a[i].second)+a[i].first;
		ans = max(ans , temp);
		buff.push_back(make_pair(a[i].second , temp));
		if( i==n || (i+1<=n && a[i].first != a[i+1].first)){
			for(pll x: buff){
				st.update_point(x.first , x.second);
			}
			buff.clear();
		}
	}
 	printf("%.7f\n",1.0*ans*PI);
}