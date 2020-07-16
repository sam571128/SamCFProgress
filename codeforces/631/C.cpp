#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int a[N], r[N], t[N], b[N];
int sz;
signed main(){
    fastio
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++){
        cin >> t[i] >> r[i];
        while(sz > 0 && r[i] >= r[sz-1]) sz--;
        t[sz]  = t[i], r[sz] = r[i], sz++;
    }
    int l = 0, br = r[0];
    r[sz] = 0, ++sz;
    for(int i = 0;i < br;i++) b[i] = a[i];
    sort(b,b+br);
    for(int i = 1;i < sz;i++){
        for(int j = r[i-1];j > r[i];--j) a[j-1] = (t[i-1]==1 ? b[--br] : b[l++]);
    }
    for(int i = 0;i < n;i++) cout << a[i] << " ";
}
