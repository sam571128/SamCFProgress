#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5;
int n,r,k;
int arr[N], sub[N];

bool check(int x){
    int now = 0, tmp = k;
    int tsub[n];
    for(int i = 0;i < n;i++) tsub[i] = sub[i];
    for(int i = 0;i < n;i++){
        now += tsub[i];
        if(now < x){
            if(x-now > tmp) return false;
            if(i+2*r+1 < n) tsub[i+2*r+1] -= x-now;
            tmp -= x-now;
            now += x-now;
        }
    }
    return true;
}

signed main(){
    fastio
    cin >> n >> r >> k;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        sub[max(i-r,(int)0)] += arr[i];
        if(i+r+1 < n) sub[i+r+1] -= arr[i]; 
    }
    int l = 0, r = 2e18;
    while(l < r-1){
        int mid = l+(r-l)/2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    if(check(l+1)) l = l+1;
    cout << l << "\n";
}