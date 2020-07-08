#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	if(n==1){
		cout << -1 << "\n";
		return;
	}
	int sum = 2*(n-1);
	bool check = false;
	if((n-1)%9==0) check = true;
	for(int i = 0;i < (check?n-2:n-1);i++){
		cout << 2;
	}
	if(check) cout << 99 << "\n";
	else cout << 9 << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}