#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	int b[n];
	for(int i = 0; i < n;i++) cin >> arr[i];
	bool one = false, zero = false;
	for(int i = 0; i < n;i++){
		cin >> b[n];
		if(b[n]) one = true;
		else zero = true;
	}
	bool check = true;
	for(int i = 0;i < n-1;i++){
		if(arr[i]>arr[i+1]) check = false;
	}
	if(check) cout << "Yes\n";
	else{
		if(one&&zero){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}