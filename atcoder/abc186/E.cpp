#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

pair<int,int> ext_gcd(int a, int b){
    if(b==0) return {1,0};
    else if(a==0) return {0,1};
    auto [s,t] = ext_gcd(b,a%b);
    return {t,s-a/b*t};
}

int inv(int a, int p){
    auto [x,y] = ext_gcd(a,p);
    if(x*a+y*p==1){
        return (x+p)%p;
    }else{
        return -1;
    }
}

int solve(int a, int b, int p){
    int g = gcd(gcd(a,b),gcd(b,p));
    a/=g,b/=g,p/=g;
    int INV = inv(a,p);
    if(INV==-1){
        return -1;
    }else{
        return b*INV%p;
    }
}

void solve(){
    int n,s,k;
    cin >> n >> s >> k;
    cout << solve(k,-s%n+n,n) << "\n";
}

signed main(){
    fastio
    int t = 1;
    cin >> t;
    while(t--) solve();
}