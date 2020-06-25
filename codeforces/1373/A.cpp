#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	if(b==1){
		cout << -1 << " " << -1 << "\n";
	}
	if(c<=a){
		cout << -1 << " " << b << "\n";
		return;
	}
	cout << 1 << " ";
	if(c/b>=a){
		cout << -1 << "\n";
	}else{
		cout << b << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}