#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	string s;
	cin >> n >> s;
	int dx = 0,dy = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i]=='U') dy++;
		if(s[i]=='D') dy--;
		if(s[i]=='R') dx++;
		if(s[i]=='L') dx--;
	}
	int x,y;
	cin >> x >> y;
	if(dx==x&&dy==y){
		cout << 0 << "\n";
		return 0;
	}else if(abs(x)+abs(y)>s.size()||s.size()%2!=(abs(x)+abs(y))%2){
		cout << -1 << "\n";
		return 0;
	}
	int l = 0,r = 0,ans = INT_MAX,check = true;
	while(l < n){
		while(r < n){
			if(check){
				if(s[r]=='U') dy--;
				if(s[r]=='D') dy++;
				if(s[r]=='R') dx--;
				if(s[r]=='L') dx++;
			}else{
				check = true;
			}
			//cout << l << " " << r << " " << dx << " " << dy << " " <<abs(x-dx)+abs(y-dy) << "\n";
			if(abs(x-dx)+abs(y-dy)<=r-l+1&&(abs(x-dx)+abs(y-dy))%2==(r-l+1)%2) break;
			r++;
		}

		if(abs(x-dx)+abs(y-dy)<=r-l+1&&(abs(x-dx)+abs(y-dy))%2==(r-l+1)%2) ans = min(r-l+1,ans);
		if(s[l]=='U') dy++;
		if(s[l]=='D') dy--;
		if(s[l]=='R') dx++;
		if(s[l]=='L') dx--;
		l++;
		check = false;
	}
	cout << ans << "\n";
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
}