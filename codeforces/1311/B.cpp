#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int a[n];
	int check[n];
	memset(check,0,sizeof check);
	for(auto &x : a) cin >> x;
	for(int i = 0, tmp;i < m;i++) cin >> tmp, check[tmp-1]++;
	for(int i = 0;i < n-1;i++){
		for(int j = 0;j < n-i-1;j++){
			if(a[j] > a[j+1]){
				if(check[j]) swap(a[j],a[j+1]);
				else{
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}