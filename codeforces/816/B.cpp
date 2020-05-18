#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int mxN = 2e5+5;

int c[mxN];
int main(){
	fastio
	int n,k,q;
	cin >> n >> k >> q;
	for(int i = 0;i < n;i++){
		int l,r;
		cin >> l >> r;
		c[l]++;
		c[r+1]--;
	}
	for(int i = 1;i < mxN;i++){
		c[i] += c[i-1];
	}
	for(int i = 1;i < mxN;i++){
		c[i] = (c[i]>=k);
	}
	for(int i = 1;i < mxN;i++){
		c[i] += c[i-1];
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << c[r]-c[l-1] << "\n";
	}
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}