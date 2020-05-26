#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int even = 0;
		int odd = 0;
		int one = 0;
		int arr[n];
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			if(arr[i]&1) odd++;
			else even++;
		}
		sort(arr,arr+n);
		for(int i = 0;i < n-1;i++){
			if(arr[i+1]-arr[i]==1){
				one++;
			}
		}
		if(odd%2==0&&even%2==0){
			cout << "YES\n";
			continue;
		}
		if(one>=1){
			cout << "YES\n";
			continue;
		}else{
			cout << "NO\n";
		}
	}
}