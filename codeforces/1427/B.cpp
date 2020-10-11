#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int wins = 0;
    int losses = 0;
    vector<int> v; 
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            wins++;
            if (i == 0||s[i-1] == 'L') cnt++;
        }
        if (s[i] == 'L') {
            losses++;
            if (i == 0||s[i-1] == 'W') v.push_back(0);
            v.back()++;
        }
    }
    if (k >= losses) {
        cout << 2*n-1 << "\n";
        return;
    }
    if (wins == 0) {
        if (k == 0) cout << 0 << "\n";
        else cout << 2*k-1 << "\n";
        return;
    }
    if (s[0] == 'L') v[0] = 1e18;
    if (s[n-1] == 'L') v.back() = 1e18;
    sort(v.begin(), v.end());
    wins += k;
    for (int x: v) {
        if (x > k) break;
        k -= x;
        cnt--;
    }
    cout << 2*wins - cnt << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}