#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;
signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int cnt[101] = {};
	int mx = 0, num = 0, tmp = 0;
	for(auto x : arr){
		cnt[x]++;
		if(cnt[x]>mx){
			mx = cnt[x];
			tmp = x;
			num = 1;
		}else if(cnt[x]==mx) num++;
	}
	if(num > 1){
		cout << n << "\n";
		return 0;
	}
	int ans = 0;
	for(int s = 1;s <= 100;s++){
		if(s==tmp) continue;
		gp_hash_table<int,int> cnt;
		int sum = 0;
		for(int i = 0;i < n;i++){
			if(arr[i]==s) sum -= 1;
			if(arr[i]==tmp) sum += 1;
			if(sum==0) ans = max(i+1,ans);
			if(cnt[sum]){
				ans = max(i+1-cnt[sum],ans);
			}else cnt[sum] = i+1;
		}
	}
	cout << ans << "\n";
}