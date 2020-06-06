#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll int n;
void solve(){
	cin >> n;
	ll int ans = 0;
	for(int i = 0;i < 60;i++){
		if(n & (1LL << i)){
			ans += (1LL << (i+1)) - 1;
		}
	}
	cout << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve(); 
}