#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e4;
bool s[N];
int arr[N];
int n;

bool check(int k){
	for(int i = 0;i < n;i++){
		if(!s[arr[i]^k]) return false;
	}
	return true;
}
void solve(){
	for(int i = 0;i < N;i++) s[i] = false;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> arr[i], s[arr[i]] = true;;
	for(int k = 1;k <= 1024;k++){
		if(check(k)){
			cout << k << "\n";
			return ;
		}
	}
	cout << -1 << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}