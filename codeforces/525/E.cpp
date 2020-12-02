#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 30;

unordered_map<int,int> vals[N];
int arr[N], fac[N];
int n,k,s, ans, cnt;
//18! < 1e16

void init(){
	fac[0] = 1;
	for(int i = 1;i <= 18;i++)
		fac[i] = fac[i-1]*i;
}

void dfs1(int idx = 0, int val = 0, int have = k){
	if(idx==n/2-1){
		vals[k-have][val]++;
		if(s-arr[idx] >= val) vals[k-have][val+arr[idx]]++;
		if(have && arr[idx] <= 18 && s-fac[arr[idx]] >= val){
			vals[k-(have-1)][val+fac[arr[idx]]]++;
		}
		return;
	}
	dfs1(idx+1,val,have);
	if(s-arr[idx] >= val) dfs1(idx+1,val+arr[idx],have);
	if(have && arr[idx] <= 18 && s-fac[arr[idx]] >= val) dfs1(idx+1,val+fac[arr[idx]],have-1);
}
//a + b = k
//k-have1 i used
//k-have2 
//k-have1-have2
//k-have1 < have2;
// x < have
void dfs2(int idx = n/2, int val = 0, int have = k){
	if(idx==n-1){
		for(int i = 0;i <= have;i++){
			ans+=vals[i][s-val];
		}
		if(s - arr[idx] >= val)
			for(int i = 0;i <= have;i++){
				ans+=vals[i][s-val-arr[idx]];
			}
		if(have && arr[idx] <= 18 && s-fac[arr[idx]] >= val)
			for(int i = 0;i <= have-1;i++){
				ans+=vals[i][s-val-fac[arr[idx]]];
			}
		return;
	}
	dfs2(idx+1,val,have);
	dfs2(idx+1,val+arr[idx],have);
	if(have && arr[idx] <= 18 && s-fac[arr[idx]] >= 0) dfs2(idx+1,val+fac[arr[idx]],have-1);
}

signed main(){
	fastio
	init();
	cin >> n >> k >> s;
	for(int i = 0;i < n;i++) cin >> arr[i];
	if(n==1){
		cout << (arr[0]==s)+(arr[0]<=18&&fac[arr[0]]==s) << "\n";
		return 0;
	}
	dfs1();
	dfs2();
	cout << ans << "\n";
}