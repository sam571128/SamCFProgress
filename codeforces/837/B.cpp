#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	string grid[n];
	for(int i = 0;i < n;i++) cin >> grid[i];
	int cnt[3] = {};
	char lst = '0';
	for(int i = 0;i < n;i++){
		char col = '0';
		for(int j = 0;j < m;j++){
			if(col=='0') col = grid[i][j];
			else if(col!=grid[i][j]){
				goto next;
			}
		}
		if(lst!=col){
			if(col=='R'&&cnt[0]) goto stop;
			if(col=='G'&&cnt[1]) goto stop;
			if(col=='B'&&cnt[2]) goto stop;
		}
		if(col=='R') cnt[0]++;
		if(col=='G') cnt[1]++;
		if(col=='B') cnt[2]++;
		lst = col;
	}
	if(cnt[0]==cnt[1]&&cnt[1]==cnt[2]){
		cout << "YES\n";
		return 0;
	}
	next:;
	lst = '0';
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i = 0;i < m;i++){
		char col = '0';
		for(int j = 0;j < n;j++){
			if(col=='0') col = grid[j][i];
			else if(col!=grid[j][i]){
				goto stop;
			}
		}
		if(lst!=col){
			if(col=='R'&&cnt[0]) goto stop;
			if(col=='G'&&cnt[1]) goto stop;
			if(col=='B'&&cnt[2]) goto stop;
		}
		if(col=='R') cnt[0]++;
		if(col=='G') cnt[1]++;
		if(col=='B') cnt[2]++;
		lst = col;
	}
	if(cnt[0]==cnt[1]&&cnt[1]==cnt[2]){
		cout << "YES\n";
		return 0;
	}
	stop:;
	cout << "NO\n";
}