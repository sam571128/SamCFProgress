#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int ans = 0;
	stack<int> s; //For speed;
	int nowspeed = 0, sign = 0;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a;
		if(a==1||a==3){
			cin >> b;
		}
		if(a==1){
			nowspeed = b;
			while(!s.empty()&&b > s.top())
				s.pop(), ans++;
		}else if(a==2){
			ans += sign;
			sign = 0;
		}else if(a==3){
			if(nowspeed > b) ans++;
			else s.push(b);
		}else if(a==4){
			sign = 0;
		}else if(a==5){
			while(!s.empty()) s.pop();
		}else if(a==6){
			sign++;
		}
	}
	cout << ans << "\n";
}