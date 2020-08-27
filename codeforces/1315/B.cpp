#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	//Unsolved
	int a,b,p;
	cin >> a >> b >> p;
	string s;
	cin >> s;

    int n = s.size();
    s[n-1] = 'X';
    for (int i = n-1; i > 0; --i) {
        if(s[i] != s[i - 1]) {
            if(s[i - 1] == 'A') p -= a;
            else  p -= b;
        }
        if(p < 0) break;
        n = i;
    }
    cout << n << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}