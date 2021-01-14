#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	int num[8] = {};
	for(auto c : s){
		num[(c-'0')%8]++;
	}
	int n = s.size();
	for(int i = 0;i < 8;i++){
		if(num[i]||s.size()<3&&i==0){
			if(s.size()>=3) num[i]--;
			for(int j = 0;j < 8;j++){
				if(num[j]||s.size()<2&&i==0&&j==0){
					if(s.size()>=2) num[j]--;
					for(int k = 0;k < 8;k++){
						if(num[k]){
							num[k]--;
							if((i*100+j*10+k)%8==0){
								cout << "Yes\n";
								return 0;
							}
							num[k]++;
						}
					}
					if(s.size()>=2)num[j]++;
				}
			}
			if(s.size()>=3)num[i]++;
		}
	}
	cout << "No\n";
}