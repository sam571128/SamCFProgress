#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	for(int i = 0, tmp; i < n;i++){
		cin >> tmp;
		tmp = abs(tmp);
		if(i&1) cout << tmp << " ";
		else cout << -tmp << " ";
	}
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}