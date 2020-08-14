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
			lazy.resize(N<<1,INT_MAX);
			stree.resize(N<<1, INT_MAX);
		}
 
		void update_point(int index, int val){
			index += N-1;
			stree[index]=val;
			while(index>1){
				index>>=1;
				stree[index]=min(stree[index<<1],stree[index<<1|1]);
			}
		}
 
		void update_range(int i, int j, int val){
			update_range(1 , 1 , N , i , j , val);
		}
 
		void update_range(int node ,int b , int e, int i ,int j,int val){
			if(b>j || e<i)return;
			if(b>=i && e<=j){
				stree[node] += val * (e-b+1);
				lazy[node] += val;
				return;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			stree[node]=stree[node<<1]+stree[node<<1|1];
		}
 
		void propagate(int node, int b, int mid, int e){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
			stree[node<<1] += (mid-b+1)*lazy[node];		
			stree[node<<1|1] += (e-mid)*lazy[node];		
			lazy[node] = 0;
		}
 
		int query(int val){
			return query(1,1,N,val);
		}
 
		int query(int node, int b, int e, int val){
			if(b==e)return b;
			int mid = b + (e-b)/2;
			if(stree[node<<1|1]<val){
				return query(node<<1|1 , mid+1 , e, val);
			}
			return query(node<<1 , b , mid, val);
		}
};
 
int main(){
	int n, N=1,m;
	cin>>n;
	while(N<n)N<<=1;
	vector<ll> arr(N+1, INT_MAX);
	SegmentTree st(arr);
	for(int i = 1 ;i<=n ; i++){
		cin>>arr[i];
		st.update_point(i,arr[i]);
	}
	
	for(int i = 1;i<=n;i++){
		int pos = st.query(arr[i]);
		// cout<<pos<<" "<<i<<endl;
		if(pos<=i)cout<<-1<<" ";
		else cout<<pos-i-1<<" ";
	}
 
}