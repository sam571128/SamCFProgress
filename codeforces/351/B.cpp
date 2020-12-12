#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int bit[N];

void update(int pos, int val){
    while(pos < N){
    bit[pos]+=val;
    pos+=pos&-pos;  
    }
}

int query(int pos){
    int res = 0;
    while(pos){
    res += bit[pos];
    pos -= pos&-pos;  
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n;i++){
        int tmp;
        cin >> tmp;
        cnt += query(N-1)-query(tmp);
        update(tmp,1);
    }
    cout << setprecision(10) << fixed << cnt*2-cnt%2 << "\n";
}

signed main(){
    fastio
    int t = 1;
    //cin >> t;
    while(t--) solve();
}