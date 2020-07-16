#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	unordered_map<string,int> mp;
	
	for(int i = 0;i < n;i++){
		string tmp;
		cin >> tmp;
		mp[tmp]++;
	}
	for(int i = 0;i < m;i++){
		unordered_map<string,int> mp2;
		int ans = 0;
		string tmp;
		cin >> tmp;
		vector<int> v;
		for(int j = 0;j < tmp.size();j++){
			if(tmp[j]=='?') v.push_back(j);
		}
		for(int j = 0;j < 6;j++){
			char c[3];
			c[0] = 'a' + j;
			for(int k = 0;k < 6;k++){c[1] = 'a' + k;
				for(int l = 0;l < 6;l++){
					c[2] = 'a' + l;
					string tmp2 = tmp;
					int cnt = 0;
					for(int pos = 0;pos < v.size();pos++){
						tmp2[v[pos]] = c[pos];
					}
					for(int pos = 0;pos < tmp2.size();pos++){
						if(tmp2[pos]=='f'){
							tmp2.erase(pos,1);
							pos--;
						}
					}
					if(!mp2[tmp2]&&mp[tmp2]){
						ans += mp[tmp2];
					}
					mp2[tmp2]++;
				}
			}
		}
		cout << ans << "\n";
	}
}