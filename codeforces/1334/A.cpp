#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int last[2] = {-1,-1};
	bool check = 1;
	for(int i = 0,l,r;i < n;i++){
		cin >> l >> r;
		if(l < last[0]||r < last[1]|| r - last[1] > l - last[0]){
			check = 0;
		}
		last[0] = l, last[1] = r;
	}
	cout << (check ? "YES\n" : "NO\n");
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}