#include <bits/stdc++.h>

#define long long ll
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for(int i = 0;i <= 32;i++){
		for(int j = 0;j <= 32;j++){
			if((pow(i,2)+j==n)&&(pow(j,2)+i==m)) ans++;
		}
	}
	cout << ans << "\n";
}