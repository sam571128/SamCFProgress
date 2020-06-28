#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	ll score = 0;
	ll sum = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(i==0) score = tmp;
		sum += tmp;
	}
	if(sum>=m){
		cout << m << "\n";
	}else{
		cout << sum << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}