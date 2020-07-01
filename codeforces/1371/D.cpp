#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n][n] = {}, row[n] = {},col[n] = {};
	int tmp = 0;
	while(k){
		for(int i = 0;i < n&&k;i++){
			arr[i][(tmp+i)%n] = 1;
			row[i]++;
			col[(tmp+i)%n]++;
			k--;
		}
		tmp++;
	}
	cout << (*max_element(row,row+n)-*min_element(row,row+n))*(*max_element(row,row+n)-*min_element(row,row+n)) + (*max_element(col,col+n)-*min_element(col,col+n))*(*max_element(col,col+n)-*min_element(col,col+n)) << "\n";
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++) cout << arr[i][j];
		cout << "\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}