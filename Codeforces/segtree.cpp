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
			lazy.resize(N<<1 , INT_MAX);
			stree.resize(N<<1, INT_MAX);
			// build(1,1,N);
		}
		
		// void build(int node , int b , int e){
			// if(b==e)stree[node]=array[b];
			// else{
				// int mid = b + (e-b)/2;
				// build(node<<1, b, mid);
				// build(node<<1|1, mid+1, e);
				// stree[node] = stree[node<<1] & stree[node<<1|1];
			// }
		// }
		
		// void update_point(int index, int val){
			// index += N-1;
			// stree[index]+=val;
			// while(index>1){
				// index>>=1;
				// stree[index]=stree[index<<1]+stree[index<<1|1];
			// }
		// }
		
		void update_range(int i, int j, int val){
			update_range(1 , 1 , N , i , j , val);
		}
		
		void update_range(int node ,int b , int e, int i ,int j,int val){
			if(b>j || e<i)return;
			if(b>=i && e<=j){
				stree[node] = stree[node] & val; 
				lazy[node] = lazy[node] & val;
				return;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			stree[node]=stree[node<<1]&stree[node<<1|1];
			// cout<<"Anding "<< (node<<1) << " and "<< (node<<1|1)<<" at "<<node <<" = "<<stree[node]<<endl;
			// cout<<stree[node<<1]<<" "<<stree[node<<1|1]<<endl;
		}
		
		void propagate(int node, int b, int mid, int e){
			lazy[node<<1] &= lazy[node];
			lazy[node<<1|1] &= lazy[node];
			stree[node<<1] &= lazy[node];		
			stree[node<<1|1] &= lazy[node];		
			lazy[node] = INT_MAX;
		}
		
		int query(int i, int j){
			return query(1,1,N,i,j);
		}
	
		int query(int node, int b, int e, int i, int j){
			if(i>e || j <b)
				return INT_MAX;		
			if(b>= i && e <= j){
				return stree[node];
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			int q1 = query(node<<1,b,mid,i,j);
			int q2 = query(node<<1|1,mid+1,e,i,j);
			// cout<<"node "<<node<<" "<<q1<<" "<<q2<<endl;
			return q1 & q2;	
		}
		int get_parent_value(int index){
			while(index>1){
				if(stree[index]!=INT_MAX)return stree[index];
				index >>= 1;
			}
			return stree[index];
		}
};

int main(){
	int n, N=1,m;
	cin>>n>>m;
	while(N<n)N<<=1;
	vector<ll> arr(N+1, INT_MAX);
	// for(int i = 0 ;i<=N ; i++)arr[i]=INT_MIN;
	// padding
	// for(int i = n+1;i<=N;i++)arr[i]=0;
	SegmentTree st(arr);
	vector< vector<int> > v(m, vector<int>(3));
	bool ok= true;
	for(int i = 0;i<m;i++){
		int  l , r, val;
		cin >> v[i][0]>> v[i][1]>>v[i][2];
		st.update_range( v[i][0], v[i][1],v[i][2]);
	}
	for(int i = 0;i<m;i++){
		ll curr = st.query(v[i][0] , v[i][1]);
		if(curr != v[i][2]){
			// cout<<i<<" "<<curr<<endl;
			ok=false;
		}
	}
	if(ok){
		cout<<"YES\n";
		for(int i = 1 ;i <= n ; i++){
			cout<<st.get_parent_value(i+N-1)<<" ";
		}
	}else cout<<"NO";
}