#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    unordered_set<int> s;
    for(int i = 0, tmp;i < n;i++){
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << "\n";
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
} 