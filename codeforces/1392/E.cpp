//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 50;
int grid[N][N];

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++){
		if(i&1) grid[i][j] = ((int)1<<i+j);
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
	int q;
	cin >> q;
	for(int i = 0;i < q;i++){
		int k;
		cin >> k;
		int x = 0, y = 0;
		cout << 1 << " " << 1 << "\n";
		while(x!=n-1||y!=n-1){
			if(x==n-1) y+=1;
			else if(y==n-1) x+=1;
			else if(x&1^1){
				if(k&((int)1<<x+1+y)) x+=1;
				else y+=1;
			}else{
				if(k&((int)1<<x+y+1)) y+=1;
				else x+=1;
			}
			cout << (x+1) << " " << (y+1) << "\n";
		}
		cout << endl;
	}
}