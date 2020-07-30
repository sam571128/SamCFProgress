#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a[6] = {6,10,14,15,21,35};
	int n;
	cin >> n;
	for(int i = 0;i < 6;i++){
		for(int j = i+1;j < 6;j++){
			for(int k = j+1;k < 6;k++){
				if(n-(a[i]+a[j]+a[k])>0&&n-(a[i]+a[j]+a[k])!=a[i]&&n-(a[i]+a[j]+a[k])!=a[j]&&n-(a[i]+a[j]+a[k])!=a[k]){
					cout << "YES\n";
					cout << a[i] << " " << a[j] << " " << a[k] << " " << n-(a[i]+a[j]+a[k]) << "\n";
					return;
				}
			}
		}
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}