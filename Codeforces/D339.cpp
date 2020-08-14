#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree{
	public:
		int N;
		vector<ll> stree;
		vector<ll> lazy;
		vector<ll> array;
		
		SegmentTree(vector<ll>& v){
			N = v.size()-1;
			array = v;
			lazy.resize(N<<1,0);
			stree.resize(N<<1,0);
		}
 
		void update_point(int index, int val){
			index += N-1;
			stree[index] = val;
			bool orz=true;
			// cout<<"Update "<<index<<"\n";
			while(index>1){
				index>>=1;
				if(orz)stree[index]=stree[index<<1] | stree[index<<1|1];
				else stree[index]=stree[index<<1] ^ stree[index<<1|1];
				orz = !orz;
				// cout<<stree[index]<<endl;
			}
		}
 
		int query(int i, int j){
			bool orz=true;
			return query(1,1,N,i,j, orz);
		}
 
		int query(int node, int b, int e, int i, int j, bool&orz){
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j){
				orz = true;
				return stree[node];
			}
				
			int mid = b + (e-b)/2;
			int q1 = query(node<<1,b,mid,i,j,orz);
			int q2 = query(node<<1|1,mid+1,e,i,j,orz);
			
			if(orz){
				orz = false;
				return q1 | q2;
			}
			orz = true;
			return q1 ^ q2;
		}
};
 
int main(){
	int tc=1,_=1;
	bool f = false;
	ll n,m;
	while(_--){
		ll N=1;
		cin>>n>>m;
		n = pow(2,n);
		while(N<n)N<<=1;
		vector<ll> arr(N+1,0);
		SegmentTree st(arr);
		for(int i = 1 ;i<=n ; i++){
			cin>>arr[i];
			st.update_point(i,arr[i]);
		}
		while(m--){
			int node , val;
			cin>>node>>val;			
			st.update_point(node,val);
			cout<<st.stree[1]<<endl;
		}
		cout<<endl;
	}
 
}
