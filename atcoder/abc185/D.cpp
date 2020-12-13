#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n,m;
    cin >> n >> m;
    int arr[m];
    for(auto &x : arr) cin >> x;
    sort(arr,arr+m);
    vector<int> v;
    int now = 0;
    for(int i = 0;i < m;i++){
        if(arr[i]-now-1!=0) v.push_back(arr[i]-now-1);
        now = arr[i];
    }
    if(now!=n) v.push_back(n-now);
    if(v.empty()){
        cout << 0 << "\n";
        return 0;
    }
    int tmp = *min_element(v.begin(),v.end());
    int ans = 0;
    for(auto x : v){
        //cout << x << "\n";
        ans += (x+tmp-1)/tmp;
    }
    cout << ans << '\n';
}