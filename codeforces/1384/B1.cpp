#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> d(n+2, -k);
    for (int i = 1; i <= n; ++i)
        cin >> d[i];

    set<tuple<int, int, bool>> s;
    function<bool(int, int, bool)> dfs = [&](int pos, int tide, bool down)
    {
        if (pos > n) return true;
        
        if (s.find({ pos, tide, down }) != s.end())
            return false;

        s.insert({ pos, tide, down });

        tide += down ? -1 : +1;
        if (tide == 0) down = false;
        if (tide == k) down = true;

        if (d[pos] + tide <= l && dfs(pos, tide, down))
            return true;
        if (d[pos + 1] + tide <= l && dfs(pos + 1, tide, down))
            return true;
        return false;
    };

    if (dfs(0, 0, false)) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}