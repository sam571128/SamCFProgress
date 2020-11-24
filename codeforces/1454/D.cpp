#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    int n;
    cin >> n;
    int tmp = n;
    map<int,int> m;
    for(int i = 2;i <= sqrt(n);i++){
        while(tmp%i==0){
            m[i]++;
            tmp/=i;
        }
    }
    if(tmp!=1) m[tmp]++;
    int ma = 0, num = 0;
    for(auto [a,b] : m){
        if(b > ma) num = a, ma = b;
    }
    cout << ma << "\n";
    while(n%(num*num)==0){
        cout << num << " ";
        n/=num;
    }
    cout << n << "\n";
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}