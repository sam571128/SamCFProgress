#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int arr[N];
int main(){
	fastio
	int n;
	cin >> n;
	int ans[n];
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		ans[i] = ++arr[tmp];
	}
	for(int i = 2;i < N;i++){
		if(arr[i]>arr[1]||arr[i]>arr[i-1]){
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << *max_element(ans,ans+n) << "\n";
	for(int i = 0;i < n;i++) cout << ans[i] << " ";
}