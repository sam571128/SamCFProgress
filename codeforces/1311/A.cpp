#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	if(a==b){
		cout << 0 << "\n";
		return;
	}
	if((b>a)&&(b-a)&1||(b<a)&&(b-a)&1^1) cout << 1 << "\n";
	else cout << 2 << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}