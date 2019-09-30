#include <bits/stdc++.h>

using namespace std;
stack<char> s ;
long long ans,t,c=0,v;
string str1,str2;
int size[1000];
int sets[1000];
int n,q,p,a,b,m;
map <int,int> check;
const unsigned int M = 1000000007; //10^9+7
vector <pair<char, char>> extra;
bool letters[256];


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

    cin>>n;
    cin>>str1>>str2;



    // create a set for each letter
    for(int i = 0 ; i < 26 ; i ++){
            sets[i]=i;
            size[i]=1;


    }

    //Lopp of each corresponding letters

    for(int i = 0 ; i < n ; i ++){

        //if the 2 letters are not similar, we would like to buy a new Mana if there are no way to reach one letter from the other
        if(str1[i]!=str2[i]){
            if( !unified(str1[i]-'a',str2[i]-'a')){
                wunion(str1[i]-'a',str2[i]-'a');
                ans++;
                extra.push_back(make_pair(str1[i], str2[i]));
            }
        }
    }
    cout<<ans<<endl;

    while(ans--){
        cout<<extra.back().first<<" "<<extra.back().second<<endl;
        extra.pop_back();
    }




    return 0;
}
