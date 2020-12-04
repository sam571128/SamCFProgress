#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int ans[N], tmp[N], sum[N];

void range_ap(int l, int r, int a, int d){
	sum[l] += a;
	tmp[l] += d;
	sum[r+1] -= a + d*(r-l);
	tmp[r] -= d;
}

void getans(){
	int now = 0;
	for(int i = 0;i < N;i++){
		sum[i] += now;
		now += tmp[i];
	}
	now = 0;
	for(int i = 0;i < N;i++){
		now += sum[i];
		ans[i] += now;
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int tmp;
		cin >> tmp;
		if(tmp <= i){
			range_ap(0,n-(i+1),i+1-tmp,1);
			range_ap(n-(i+1)+1,n-(i+1)+tmp,tmp-1,-1);
			range_ap(n-i+tmp,n-1,1,1);
		}else{
			range_ap(0,tmp-(i+1),tmp-(i+1),-1);
			range_ap(tmp-(i+1)+1,n-(i+1),1,1);
			range_ap(n-(i+1)+1,n-1,tmp-1,-1);
		}
	}
	getans();
	int mi = ans[0], idx = 0;
	for(int i = 0;i < n;i++){
		int val = ans[i];
		if(mi > val){
			mi = val, idx = i;
		}
	}
	cout << mi << " " << idx << "\n";
}