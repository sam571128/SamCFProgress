#include<bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=(1<<19);
typedef long long ll;
string str;
vector < pair < int , char > > sorted;
int cnt[MX] , done[MX] , K ;
int main(){
    cin>>str>>K;
    for(int j=0;j<str.size();j++) cnt[str[j] - 'a']++;
    for(int j=0;j<26;j++){
        sorted.push_back(P(cnt[j] , j + 'a'));
    }
    sort(sorted.begin() , sorted.end());
    int ans = 26;
    for(auto pp : sorted){
        if(pp.first > K) break;
        K -= pp.first;
        done[pp.second] = 1;
        --ans;
    }
    cout<<ans<<endl;
    for(auto ch : str) if(!done[ch]) cout<<ch;
    cout<<endl;
}