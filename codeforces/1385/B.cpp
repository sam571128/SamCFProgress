#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
    set<int> s;
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0, tmp;i < 2*n;i++){
        cin >> tmp;
        if(s.find(tmp)==s.end()){
            v.push_back(tmp);
        }
        s.insert(tmp);
    }
    for(auto x : v) cout << x << ' ';
    cout << "\n";
}

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) solve();
}