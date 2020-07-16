#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int x;
bool ok = true;
int getans(int n,int m,int t = 0){
	if(t==x&&(n==1||m==1)){
		if(n==1&&m==1){
			return 1;
		}else if(n==1){
			return m/2;
		}else if(m==1){
			return n/2;
		}
	}
	if(t==x) return n+m-2;
	if(n-2<=0||m-2<=0){
		ok = false;
		return 0;
	}
	else return getans(n-2,m-2,t+1);
}

int main(){
	fastio
	int n,m;
	cin >> n >> m >> x;
	x--;
	int ans = getans(n,m);
	if(ok) cout << ans << "\n";
	else cout << 0 << "\n";
}