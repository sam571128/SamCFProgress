#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int x,y,x1,y1,x2,y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if((x-a+b)>=x1&&(x-a+b)<=x2&&(y-c+d)>=y1&&(y-c+d)<=y2&&(x2>x1||a+b==0)&&(y2>y1||c+d==0)){
		cout<<"YES\n";
	}else{
		cout <<"NO\n";
	}
	
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}