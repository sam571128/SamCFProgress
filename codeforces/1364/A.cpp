#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, x;
	cin >> n >> x;
	int sum = 0;
	int count = 0;
	int arr[n];
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(tmp%x==0) count++;
		sum = (sum + tmp%x)%x;
		arr[i] = tmp%x;
	}
	if(count==n) {
		cout << -1 << "\n";
		return;
	}
	if(sum!=0){
		cout << n << "\n";
		return;
	}
	int l = 0, r = n-1;
	int ans = 0;
	int tmp = n;
	while(sum==0){
		if(arr[l]!=0){
			tmp--;
			break;
		}else{
			l++;
			tmp--;
		}
	}
	ans = max(ans,tmp);
	tmp = n;
	while(sum==0){
		if(arr[r]!=0){
			tmp--;
			break;
		}
		r--;
		tmp--;
	}
	ans = max(ans,tmp);
	cout << ans << "\n";

}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}