#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e7+1;
ll arr[N];

void build(){
	for(int i = 0;i < N;i++){
		arr[i] = 1;
	}
	for(int i = 2;i < N;i++){
		for(int j = i;j < N;j+=i){
			arr[j]++;
		}
	}
}

int main(){
	fastio
	build();
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		ans += i * arr[i];
	}
	cout << ans << "\n";
}