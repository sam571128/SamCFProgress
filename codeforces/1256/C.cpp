#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m,d;
	cin >> n >> m >> d;
	int arr[m+1], ans[n+1] = {}, sum = 0;
	for(int i = 1; i <= m; i++)
		cin >> arr[i], sum += arr[i];
    int now = 0;
    for(int i = 1; i <= m; i++){
        if(now+d+sum>n+1){
            for(int j = now + 1; j < now + 1 + arr[i]; j++)
                ans[j] = i;
            now = now + 1 + arr[i] - 1, sum -= arr[i];
        }
        else{
            for(int j = now + d; j < now + d + arr[i]; j++)
                ans[j] = i;
            now = now + d + arr[i] - 1, sum -= arr[i];
        }
    }
    if(now+d+sum >= n+1){
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
    	return;
    }
    cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}