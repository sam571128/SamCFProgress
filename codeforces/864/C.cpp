#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int a,b,f,k;
	cin >> a >> b >> f >> k;
	if(k>2&&f*2 > b||k>1&&(a-f)*2 > b||b<a-f||b<f){
		cout << -1 << "\n";
		return 0;
	}
	int ans = 0;
	int tmp = b;
	for(int i = 0;i < k;i++){
		if(i==k-1&&tmp >= a) break;
		if(i&1^1){
			if(tmp < 2*a-f){
				ans++, tmp = b-(a-f);
			}else tmp-=a;
		}else{
			if(tmp < a+f){
				ans++, tmp = b-f;
			}else tmp-=a; 
		}
	}
	cout << ans << "\n";

}