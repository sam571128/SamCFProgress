#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int arr1[N], arr2[N];
int n;
void modify(int *arr,int pos, int val){
	while(pos <= n){
		arr[pos]+=val;
		pos += pos&(-pos);
	}
}
int query(int *arr, int pos){
	int res = 0;
	while(pos){
		res += arr[pos];
		pos -= pos&(-pos);
	}
	return res;
}

int pos[N], sum;

void solve(){
	cin >> n;
	for(int i = 1, tmp;i <= n;i++){
		cin >> tmp;
		pos[tmp] = i;
	}
	for(int i = 1;i <= n;i++){
		sum += i - 1 - query(arr1,pos[i]);
		modify(arr1,pos[i],1), modify(arr2,pos[i],pos[i]);
		int mid, l = 1, r = n;
		while(l<=r){
			mid = (l+r)/2;
			if(query(arr1,mid)*2 <= i) l = mid+1;
			else r = mid-1;
		}
		int ans = 0;
		int cnt1 = query(arr1,mid), cnt2 = query(arr2,mid);
		ans += mid*cnt1 - cnt2 - cnt1*(cnt1-1)/2;
		cnt1 = i - cnt1, cnt2 = query(arr2,n) - cnt2;
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