#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	bool arr[n];
	memset(arr,0,sizeof arr);
	bool ok = true;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		if(arr[((i+tmp)%n+n)%n]){
			ok = false;
		}else{
			arr[((i+tmp)%n+n)%n] = true;
		}
	}
	cout << (ok?"YES\n":"NO\n");
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}