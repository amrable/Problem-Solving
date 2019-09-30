#include <bits/stdc++.h>

using namespace std;
stack<char> s ;
long long ans,t,c=0,v;
string str1,str2;
int size[1000];
int sets[1000];
int n,q,p,a,b,m,temp,f;
map <int,int> check;
const unsigned int M = 1000000007; //10^9+7
vector <int> extra;
bool nums[1000];


int root (int i)
{
    while(sets[ i ] != i)
    {
        sets[ i ] = sets[ sets[ i ] ] ;
        i = sets[ i ];
    }
    return i;
}
bool unified(int a , int b){
    if(root(a)==root(b))return true;
    else return false;
}

void wunion(int set1,int set2){

    //if(unified(set1,set2))return;
    int root1=root(set1);
    int root2=root(set2);

    if(size[root1] > size[root2]){
        sets[root2]=root1;
        size[root1]+=size[root2];
    }else{
        sets[root1]=root2;
        size[root2]+=size[root1];
    }

}

int main()
{

    cin>>n>>m;


    //create sets
    for(int i = 0 ; i < n ; i ++){
            sets[i]=i;
            size[i]=1;
    }


    for(int i = 0 ; i < n ; i ++){
        cin>>p;

        //each person at least should know 1 language to be able to communicate
        if(p==0){
            ans++;
            continue;
        }

        extra.clear();

        for(int j =  0 ; j < p ; j++){
            cin>>temp;

            //track the language known by each employee

            nums[temp]=true;
            extra.push_back(temp);
        }

        // unify them if they are not unified
        for(int j = 1 ; j<extra.size() ; j++){
            if( !unified(extra[j], extra[j-1])){
                wunion(extra[j], extra[j-1]);
            }
        }

    }
    c=0;

    for(int i = 1 ; i <= m ; i ++){
        if(nums[i]){
            if( check[ root(sets[i]) ] == 0){
                f=1;
                c++;
                check[ root(sets[i]) ]=1;
            }
        }
    }

    //the answer is the unlearnt employees + the subsets need to be linked - 1

    ans+=c;
    ans-=f;
    cout<<ans<<endl;
    return 0;
}
