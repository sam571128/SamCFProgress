#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n,d;
    cin >> n >> d;
    int ans = 0;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(a*a+b*b<=d*d) ans++;
    }
    cout << ans << "\n";
}