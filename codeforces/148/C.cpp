#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,a,b;
	cin >> n >> a >> b;
	vector<int> v(n,1);
	int sum = 1;
	v[0] = 1;
	for(int i = 1;i < n;i++){
		if(b > 0){
			v[i] = sum + 1;
			b--;
		}
		else if(a>0){
			if(!(v[i-1]+1>sum)){
				v[i] = v[i-1] + 1;
				a--;
			}
		}else{
			v[i] = v[i-1];
		}
		sum += v[i];
		if(v[i]>50000){
			cout << -1 << "\n";
			return 0;
		}
	}
	if(a>0||b>0){
		cout << -1 << "\n";
		return 0;
	}
	for(auto x : v) cout << x << " ";
}