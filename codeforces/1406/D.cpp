//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int arr[N], n;
int suma = 0, sumb = 0;

void update(int pos, int val){
	if(pos > n-1) return;
	arr[pos]>0 ? suma -= arr[pos] : sumb += arr[pos];
	arr[pos] += val;
	arr[pos]>0 ? suma += arr[pos] : sumb -= arr[pos];
}

signed main(){
	fastio
	cin >> n;
	for(int i = 0;i < n;i++) cin >> arr[i];
	for(int i = 1;i < n;i++){
		if(arr[i]>arr[i-1]) suma+=arr[i]-arr[i-1]; else sumb+=arr[i-1]-arr[i];
	}
	for(int i = n-1;i;i--){
		arr[i] = arr[i]-arr[i-1];
	}
	int tmp = arr[0];
	cout << (int)(ceil((tmp+suma)/2.0)==0 ? 0 : ceil((tmp+suma)/2.0))  << "\n";
	int q;
	cin >> q;
	while(q--){
		int l,r,x;
		cin >> l >> r >> x;
		if(l==1) tmp+=x;
		else update(l-1,x);
		update(r,-x);
		cout << (int)(ceil((tmp+suma)/2.0)==0 ? 0 : ceil((tmp+suma)/2.0)) << "\n";
	}
}