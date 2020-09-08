#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a = 0, b = 0;

	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		if(tmp) a++;
		else b++;
	}
	if(a > b){
		cout << a-a%2 << "\n";
		for(int i = 0;i < a-a%2;i++) cout << 1 << " ";
		cout << "\n";
	}else{
		cout << b << "\n";
		for(int i = 0;i < b;i++) cout << 0 << " ";
		cout << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}