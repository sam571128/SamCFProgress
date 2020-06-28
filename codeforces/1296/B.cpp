#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum = n;
	while(n>=10){
		sum += n/10;
		n = n%10 + n/10;
	}
	cout << sum << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}