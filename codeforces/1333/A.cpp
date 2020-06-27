#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if((i+j)&1&&!(n*m&1^1&&i==n-1&&(j==m-1||j==m-2))) cout << "W";
			else cout << "B";
		}
		cout << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}