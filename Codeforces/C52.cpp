#include <bits/stdc++.h>
#define ll long long
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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
			lazy.resize(N<<1);
			stree.resize(N<<1);
			build(1,1,N);
		}
 
		void build(ll node , ll b , ll e){
			if(b==e)stree[node]=array[b];
			else{
				int mid = b + (e-b)/2;
				build(node<<1, b, mid);
				build(node<<1|1, mid+1, e);
				stree[node] = min(stree[node<<1],stree[node<<1|1]);
			}
		}
 
		void update_range(int i, int j, ll val){
			update_range(1 , 1 , N , i , j , val);
		}
 
		void update_range(int node ,int b , int e, int i ,int j,ll val){
			if(b>j || e<i)return;
			if(b>=i && e<=j){
				stree[node]+= val;
				lazy[node]+= val;
				return;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			stree[node]=min(stree[node<<1],stree[node<<1|1]);
		}
 
		void propagate(int node, int b, int mid, int e){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
			stree[node<<1] += lazy[node];		
			stree[node<<1|1] += lazy[node];		
			lazy[node] = 0;
		}
 
		ll query(int i, int j){
			return query(1,1,N,i,j);
		}
 
		ll query(int node, int b, int e, int i, int j){
			if(i>e || j <b)
				return LLONG_MAX;		
			if(b>= i && e <= j)
				return stree[node];
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			ll q1 = query(node<<1,b,mid,i,j);
			ll q2 = query(node<<1|1,mid+1,e,i,j);
			return min(q1 , q2);	
		}
};
 
int main(){
	SLAY
	int n, N=1,m;
	string in;
	getline(cin,in);
	n=stoi(in);
	while(N<n)N<<=1;
	vector<ll> arr(N+1, LLONG_MAX);
	getline(cin,in);
    vector<string> tokens; 
    stringstream check1(in); 
    string intermediate; 
    while(getline(check1, intermediate, ' ')){ 
        tokens.push_back(intermediate); 
    } 
	    
	for(int i = 1 ;i<=n ; i++){
		arr[i]=stoi(tokens[i-1]);
	}
	SegmentTree st(arr);
	getline(cin,in);
	m=stoi(in);
	while(m--){
		vector<ll> v(3,0);
		string line;
		getline(cin,line);
	    vector<string> tokens; 
	    stringstream check1(line); 
	    string intermediate; 
	    while(getline(check1, intermediate, ' ')){ 
	        tokens.push_back(intermediate); 
	    } 
	    for(int i = 0; i < tokens.size(); i++) 
	        v[i] = stoi(tokens[i])+1; 
	    v[2]--;
	    if(tokens.size()==2){
	    	if(v[0]>v[1]){
	    		cout<<min(st.query(1,v[1]),st.query(v[0],n));
	    	}else{
	    		cout<<st.query(v[0],v[1]);
	    	}
	    	cout<<endl;
	    }else{
	    	if(v[0]>v[1]){
	    		st.update_range(1,v[1],v[2]);
	    		st.update_range(v[0],n,v[2]);
	    	}else{
	    		st.update_range(v[0],v[1],v[2]);
	    	}
	    }
	    
    }
		
 
}