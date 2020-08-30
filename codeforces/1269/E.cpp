#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;

struct BIT{
	int arr[N];
	BIT(){memset(arr,0,sizeof arr);}
	void modify(int pos, int val){
		while(pos < N){
			arr[pos]+=val;
			pos += pos&(-pos);
		}
	}
	int query(int pos){
		int res = 0;
		while(pos){
			res += arr[pos];
			pos -= pos&(-pos);
		}
		return res;
	}
};

int pos[N], sum;

void solve(){
	BIT t1, t2;
	int n;
	cin >> n;
	for(int i = 1, tmp;i <= n;i++){
		cin >> tmp;
		pos[tmp] = i;
	}
	for(int i = 1;i <= n;i++){
		sum += i - 1 - t1.query(pos[i]);
		t1.modify(pos[i],1), t2.modify(pos[i],pos[i]);
		int mid, l = 1, r = n;
		while(l<=r){
			mid = (l+r)/2;
			if(t1.query(mid)*2 <= i) l = mid+1;
			else r = mid-1;
		}
		int ans = 0;
		int cnt1 = t1.query(mid), cnt2 = t2.query(mid);
		ans += mid*cnt1 - cnt2 - cnt1*(cnt1-1)/2;
		cnt1 = i - cnt1, cnt2 = t2.query(n) - cnt2;
		ans += cnt2 - cnt1*(mid+1) - cnt1*(cnt1-1)/2;
		cout << ans + sum << " ";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}