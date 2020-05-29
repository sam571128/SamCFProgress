#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 30;
int a[N],b[N],k[N],p[N];
int n,u,r;
ll int ans = -1e18;
void dfs(int num,int state){
	if(num%2==0){
		ll int t = 0;
		for(int i = 0;i < n;i++){
			t += a[i]*k[i];
		}	
		ans = max(ans,t);
	}	
	if(num==0) return;
	int tmp[N];
	for(int i = 0;i < n;i++){
		tmp[i] = a[i];
	}
	if(!state){
		for(int i = 0;i < n;i++){
			a[i] = a[i]^b[i];
		}
		dfs(num-1,1);
		for(int i = 0;i < n;i++){
			a[i] = a[i]^b[i];
		}
	}

	for(int i = 0;i < n;i++){
		a[i] = tmp[p[i]-1]+r;
	}
	dfs(num-1,0);
}
int main(){
	fastio
	cin >> n >> u >> r;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++) cin >> b[i];
	for(int i = 0;i < n;i++) cin >> k[i];
	for(int i = 0;i < n;i++) cin >> p[i];
	dfs(u,0);
	cout << ans;
}	