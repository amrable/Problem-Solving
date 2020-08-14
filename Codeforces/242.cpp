#include <bits/stdc++.h>
#define ll long long
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

class SegmentTree{
	public:
		int N;
		vector< vector<ll> > stree;
		vector<ll> lazy;
		vector<ll> array;
 
		SegmentTree(vector<ll>& v){
			N = v.size()-1;
			array = v;
			lazy.resize(N<<1);
			stree.resize(N<<1);
			for(int i = 0;i<N<<1;i++)stree[i].resize(32,0);
			build(1,1,N);
		}
 
		void build(int node , int b , int e){
			if(b==e){
				for(int i = 0 ; i<32;i++){
					if((array[b]&(1<<i)) != 0){
						stree[node][i]++;
					}
				}
			}
			else{
				int mid = b + (e-b)/2;
				build(node<<1, b, mid);
				build(node<<1|1, mid+1, e);
				for(int i = 0 ; i<32;i++){
					stree[node][i] = stree[node<<1][i]+stree[node<<1|1][i];
				}
			}
		}
 
		void update_range(int i, int j, int val){
			update_range(1 , 1 , N , i , j , val);
		}
 
		void update_range(int node ,int b , int e, int i ,int j,int val){
			if(b>j || e<i)return;
			if(b>=i && e<=j){
				int maxn = e-b+1;
				for(int i = 0 ; i<32;i++){
					if( (val&(1<<i))!=0){
						stree[node][i]= maxn - stree[node][i];
					}
				}
				lazy[node] ^= val;
				return;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			for(int i = 0 ; i<32;i++){
				stree[node][i] = stree[node<<1][i]+stree[node<<1|1][i];
			}
		}
 
		void propagate(int node, int b, int mid, int e){
			lazy[node<<1] ^= lazy[node];
			lazy[node<<1|1] ^= lazy[node];
			int maxn = mid-b+1;
			for(int i = 0 ; i<32;i++){
				if((lazy[node]&(1<<i))!=0){
					stree[node<<1][i] = maxn - stree[node<<1][i];
					stree[node<<1|1][i] = maxn - stree[node<<1|1][i];
				}
			}
			lazy[node] = 0;
		}
 
		ll query(int i, int j){
			return query(1,1,N,i,j);
		}
 
		ll query(int node, int b, int e, int i, int j){
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j){
				ll ans = 0;
				for(int i = 0 ; i<32;i++){
					ans+= stree[node][i]*pow(2,i);
				}
				return ans;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			ll q1 = query(node<<1,b,mid,i,j);
			ll q2 = query(node<<1|1,mid+1,e,i,j);
			return q1 + q2;	
		}
};
 
int main(){
	SLAY
	int n, N=1,m;
	cin>>n;
	while(N<n)N<<=1;
	vector<ll> arr(N+1);
	for(int i = 1 ;i<=n ; i++)cin>>arr[i];
	SegmentTree st(arr);
	cin>>m;
	while(m--){
		int type , l , r, val;
		cin>>type;
		if(type==1){
			// get sum
			cin >> l>> r;
			cout<<st.query(l , r)<<"\n";
		}else{
			// update to range
			cin >> l>> r>>val;
			st.update_range(l , r, val);
		}
	}
}