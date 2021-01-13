#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 9;
int t[N][N];

signed main(){
	fastio
	int n, k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> t[i][j];
	vector<int> v;
	for(int i = 0;i <= n-2;i++) v.push_back(2+i);
	int cnt = 0;
	do{
		int sum = 0;
		sum += t[1][v[0]];
		for(int i = 1;i <= n-2;i++) sum += t[v[i-1]][v[i]];
		sum += t[v[n-2]][1];
		if(sum==k) cnt++;
	}while(next_permutation(v.begin(),v.end()));
	cout << cnt << "\n";
}