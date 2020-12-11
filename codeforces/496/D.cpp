#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;

signed main(){
	fastio
	int cnt[2];
	int n;
	cin >> n;
	int arr[2][N], cnt2[2][N], tt = -1;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		tt = tmp-1;
		cnt[tmp-1]++;
		cnt2[0][i] = cnt[0];
		cnt2[1][i] = cnt[1];
		arr[tmp-1][cnt[tmp-1]] = i;
	}
	vector<pair<int,int>> ans;
	for(int t = 1;t <= n;t++){
		int now0 = 0, now1 = 0, idx = -1, win0 = 0, win1 = 0;
		bool ok = true;
		while(idx<n-1){
			if(now0+ t > cnt[0]&&now1 + t > cnt[1]){
				ok = false;
				break;
			}
			if((now0 + t > cnt[0] ? n :arr[0][now0+t]) < (now1 + t > cnt[1] ? n : arr[1][now1+t])){
				win0++;
			}else{
				win1++;
			}
			idx = min((now0 + t > cnt[0] ? n-1 :arr[0][now0+t]), (now1 + t > cnt[1] ? n-1 : arr[1][now1+t]));
			now0 = cnt2[0][idx], now1 = cnt2[1][idx];
		}
		if(win0==win1) continue;
		if(ok){
			if(tt==0&&win1 > win0) continue;
			if(tt==1&&win0 > win1) continue;
			ans.push_back({max(win0,win1),t});
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(),ans.end());
	for(auto x : ans) cout << x.first << " " << x.second << "\n";
}