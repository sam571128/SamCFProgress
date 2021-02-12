#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

pair<int,int> check(int a, int b){
	for(int i = 1;i*i*i*i < a;i++){
		if(a-i*i*i*i==b) return {a,b};
	}
	return {-1,-1};
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int l1 = 1, l2 = 1;
	int grid[n][m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> grid[i][j];
			if((i+j)%2) l1 = lcm(l1,grid[i][j]);
			else l2 = lcm(l2,grid[i][j]);
		}
	}

	bool isdone = false;
	if(l1==1||l2==1){
		if(l1==1) l1 = l2+1;
		else l2 = l1+1;
		isdone = true;
	}
	int tmp = l1, tmp2 = l2;
	for(;tmp <= 1e6&&!isdone;tmp+=l1){
		//cout << tmp << " " << tmp2 << "\n";
		pair<int,int> tt;
		tt = check(tmp,tmp2);
		if(tt.first==-1) continue;
		else{
			l1 = tt.first, l2 = tt.second;
			isdone = true;
		}
	}
	tmp = l1;
	for(;tmp2 <= 1e6&&!isdone;tmp2+=l2){
		pair<int,int> tt;
		tt = check(tmp2,tmp);
		if(tt.first==-1) continue;
		else{
			l1 = tt.second, l2 = tt.first;
			isdone = true;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(l1==l2){
				if((i+j)%2) grid[i][j] = l1+grid[i][j]*grid[i][j]*grid[i][j]*grid[i][j];
				else grid[i][j] = l1;
			}else{
				if((i+j)%2) grid[i][j] = l1;
				else grid[i][j] = l2;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}