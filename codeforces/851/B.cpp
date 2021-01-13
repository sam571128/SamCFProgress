#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	if((a-c)*(a-c)+(b-d)*(b-d)==(c-e)*(c-e)+(d-f)*(d-f)&&(a-c)*(d-f)-(b-d)*(c-e)!=0){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}