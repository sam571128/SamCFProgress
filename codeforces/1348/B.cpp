#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	set<int> s;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		s.insert(tmp);
	}
	if(s.size()>k){
		cout << -1 << "\n";
		return;
	}
	cout << n*k << "\n";
	for(int i = 0;i < n;i++){
		for(int x : s) cout << x << " ";
		for(int j = 0;j < k - s.size();j++){
			cout << 1 << " ";
		}
	}
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}