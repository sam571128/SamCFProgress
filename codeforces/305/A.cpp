#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int ans[5];
int main() {
	int n;
    cin >> n;
    for(int i = 0,tmp; i < n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            ans[0] = 1;
            continue;
        }
        if (tmp == 100) {
            ans[1] = 1;
            continue;
        }
        if (tmp % 10 == 0) {
            ans[2] = tmp;
            continue;
        }
        if (tmp < 10) {
            ans[3] = tmp;
            continue;
        }
        ans[4] = tmp;
    }
    vector < int > ans2;
    if (ans[0]) ans2.push_back(0);
    if (ans[1]) ans2.push_back(100);
    if (ans[2]) ans2.push_back(ans[2]);
    if (ans[3]) ans2.push_back(ans[3]);
    if (!ans[2] && !ans[3] && ans[4]) ans2.push_back(ans[4]);
    cout << ans2.size() << "\n";
    for(auto x : ans2) cout << x << " ";
}