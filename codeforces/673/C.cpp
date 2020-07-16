#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5005;
int ans[N], cnt[N];
int main(){
	fastio
	int n;
	cin >> n;
	int t[n];
	for(auto &x : t) cin >> x;
	for(int l = 1;l <= n;l++){
		for(int i = 1;i <= n;i++) cnt[i] = 0;
		int tmp = 0;
		for(int i = l-1;i < n;i++){
			int num = t[i];
			cnt[t[i]]++;
			if(cnt[num]>cnt[tmp]||(cnt[num]==cnt[tmp]&&num<tmp)){
				tmp = num;
			}
			ans[tmp]++;
		}
	}
	for(int i = 1;i <= n;i++) cout << ans[i] << " ";
}