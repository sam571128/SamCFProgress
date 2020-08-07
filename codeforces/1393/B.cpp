//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

unordered_map<int,int> m;
int sq = 0, rect = 0;
signed main(){
    fastio
    int n;
    cin >> n;
    for(int i = 0, tmp;i < n;i++){
        cin >> tmp;
        m[tmp]++;
        sq += m[tmp]/4-(m[tmp]-1)/4, rect += m[tmp]%4/2-(m[tmp]-1)%4/2;
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if(c=='+'){
            m[x]++;
            sq += m[x]/4-(m[x]-1)/4, rect += m[x]%4/2-(m[x]-1)%4/2;
        }else{
            m[x]--;
            sq += m[x]/4-(m[x]+1)/4, rect += m[x]%4/2-(m[x]+1)%4/2;
        }
        if(sq>=2||sq>=1&&rect/2>=1) cout << "YES\n";
        else cout << "NO\n";
    }
}