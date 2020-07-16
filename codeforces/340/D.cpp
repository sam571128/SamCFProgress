
#include<bits/stdc++.h>
 
using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
 
int n, A[222222], tree[222222], f[222222];
void ins(int x, int val) {
	for (int z = x; z <= 200000; z += z & -z) tree[z] = max(tree[z], val);
}
 
int ask(int r) {
	int res = 0;
	for (int z = r; z; z -= z & -z) res = max(res, tree[z]);
	return res;
}
 
int main() {
	cin >> n;
	For(i,1,n) scanf("%d", &A[i]);
	int ans = 0;
	For(i,1,n) {
		f[i] = ask(A[i] - 1) + 1;
		ins(A[i], f[i]);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}