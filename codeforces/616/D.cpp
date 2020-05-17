#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int cnt[N];
int main(){
	fastio
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n;i++) cin >> arr[i];
	int cur = 0;
	int l = 0,r = 0,al = -1, ar = -1;
	while(l<n){
		while(r<n){
			if(++cnt[arr[r]]==1) cur++;
			if(cur > k){
				if(--cnt[arr[r]]==0) cur--;
				break;
			}
			r++;
		}
		if(ar-al < r-l) al = l, ar = r;
		if(--cnt[arr[l]]==0) cur--;
		l++;
	}
	cout << al+1 << " " << ar << "\n";
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}