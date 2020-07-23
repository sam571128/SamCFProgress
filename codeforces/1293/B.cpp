#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n;
    cin >> n;
    long double ans = 0;
    for(int i = 1;i <= n;i++){
        ans += 1.0/(i);
    }
    cout << fixed << setprecision(11) << ans << "\n";
}