#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



int main(){
	fastio
	int n,m;
	cin >> n >> m;
	bool r[n], c[n];
	memset(r,0,sizeof r);
	memset(c,0,sizeof c);
	while(m--){
		int x,y;
		cin >> x >> y;
		r[x] = 1;
		c[y] = 1;
	}	
	int ans = 0;
	for(int i = 2;i*2 <= n+1;i++){
		if(i*2==n+1){
			if(!r[i]||!c[i]){
				ans++;
			}
		}
		else{
			bool cl = 0, cr = 0, cu = 0, cd = 0;
			if(!r[i]) cl = 1;
			if(!r[n+1-i]) cr = 1;
			if(!c[i]) cu = 1;
			if(!c[n+1-i]) cd = 1;
			ans += cl + cr + cu + cd;
		}
	}
	cout << ans << "\n";
}