#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int query(string s){
	cout << s << endl;
	int n;
	cin >> n;
	if(n<=0) exit(0);
	return n;
}

const int N = 300;
void solve(){
	int cntA = N - query(string(N,'a'));
	int cntB = N - query(string(N,'b'));
	int n = cntA + cntB;
	int tmp = cntB;
	string ans = string(n,'a');
	for(int i = 0;i < n-1;i++){
		ans[i] = 'b';
		if(query(ans) > tmp) ans[i] = 'a';
		else tmp--;
	}
	if(tmp) ans[n-1] = 'b';
	query(ans);
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}