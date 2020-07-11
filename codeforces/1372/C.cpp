#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int last = -1, count = 0;
	for(int i = 1, tmp;i <= n;i++){
		cin >> tmp;
		if(last == -1 && i!=tmp){
			count++;
			last = 1;
		}
		if(tmp==i){
			last = -1;
		}
	}
	cout << (count > 2? 2 : count) << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}