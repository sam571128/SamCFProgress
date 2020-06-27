#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	bool hasone = false, hasn = false;
	for(int i = 0;i < n;i++){
		if(b[i]<a[i]&&!hasn){
			cout << "No\n";
			return;
		}else if(b[i] > a[i]&&!hasone){
			cout << "No\n";
			return;
		}
		if(a[i]==1) hasone = true;
		if(a[i]==-1) hasn = true;
	}
	cout << "Yes\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}