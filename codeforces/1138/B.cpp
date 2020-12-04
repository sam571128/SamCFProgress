#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> a,b,c,d;
signed main(){
	fastio	
	int n;
	cin >> n;
	string s1,s2;
	cin >> s1 >> s2;
	for(int i = 0;i < n;i++){
		if(s1[i]=='0'&&s2[i]=='0') 
			a.push_back(i+1);
		if(s1[i]=='0'&&s2[i]=='1') 
			b.push_back(i+1);
		if(s1[i]=='1'&&s2[i]=='0') 
			c.push_back(i+1);
		if(s1[i]=='1'&&s2[i]=='1') 
			d.push_back(i+1);
	}
	for(int i = 0;i <= (int)c.size();i++){
		for(int j = 0;j <= (int)d.size()&&i+j<=n/2;j++){
			int k = (int)b.size()+(int)d.size()-i-2*j;
			int l = n/2-i-j-k;
			if(i+j+k+l != n/2) continue;
			if(l <= (int)a.size()&&l >= 0&&k <= (int)b.size()&&k>=0&&i+j+k+l == n/2){
				for(int x = 0; x < l; x++) cout << a[x] << " ";
				for(int y = 0; y < k; y++) cout << b[y] << " ";
				for(int z = 0; z < i; z++) cout << c[z] << " ";
				for(int w = 0; w < j; w++) cout << d[w] << " ";
				return 0;
			}
		}
	}
	cout << -1 << "\n";
}