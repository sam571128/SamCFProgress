#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll x[8][3];
ll vx[8][3];
const ll inf = (ll)1e18;

void dfs(int v){
	if(v==8){
		ll side = -1;
		for(int i = 0;i < 8;i++){
			ll di = inf;
			int a = -1, b = -1, c = -1,d = -1;
			for(int j = 0;j < 8;j++){
				if(i==j) continue;
				ll dist = 0;
				for(int k = 0;k < 3;k++){
					vx[j][k] = x[j][k]-x[i][k];
					dist += vx[j][k]*vx[j][k];
				}
				if(dist < di){
					di = dist;
					a = -1;
					b = -1;
					c = -1;
					d = -1;
				}
				if(dist == di){
					d = c;
					c = b;
					b = a;
					a = j;
				}
			}
			if(d!=-1||c==-1) return;
			if(di==0) return;
			if(side==-1) side = di;
			if(side!=di) return;
			if(vx[a][0]*vx[b][0]+vx[a][1]*vx[b][1]+vx[a][2]*vx[b][2]!=0) return;
			if(vx[a][0]*vx[c][0]+vx[a][1]*vx[c][1]+vx[a][2]*vx[c][2]!=0) return;
			if(vx[c][0]*vx[b][0]+vx[c][1]*vx[b][1]+vx[c][2]*vx[b][2]!=0) return;
		}
		cout << "YES" << "\n";
		for(int i = 0;i < 8;i++){
			for(int j = 0;j < 3;j++) cout << x[i][j] << " ";
			cout << "\n";
		}
		exit(0);
		return;
	}
	sort(x[v],x[v]+3);
	do{
		dfs(v+1);
	}while(next_permutation(x[v],x[v]+3));
}

int main(){
	//fastio
	for(int i = 0;i < 8;i++) cin >> x[i][0] >> x[i][1] >> x[i][2];
	dfs(1);
	cout << "NO";
	return 0;
}