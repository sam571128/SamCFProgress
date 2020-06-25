#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e6+5;
const int MOD = 1e9+7;
int arr[N];
int main(){
	fastio
	for(int i = 1;i <= N;i++){
		arr[i] = (arr[i-1]%MOD+arr[i-2]*2%MOD)%MOD + (i%3==0 ? 4 : 0);
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << arr[n] << "\n";
	}
}