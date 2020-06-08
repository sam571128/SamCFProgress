#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int t = 0;
	stack<int> temp;
	map<int,int> m1;
	for(int i = 0,tmp;i < n;i++,t++){
		cin >> tmp;
		m1[tmp] = t;
		temp.push(tmp);
	}
	map<int,int> m2;
	t = 0; 
	for(int i = 0,tmp;i < n;i++,t++){
		cin >> tmp;
		m2[tmp] = t;
	}
	map<int,int> check;

	while(!temp.empty()){
		int x = temp.top();
		temp.pop();
		if(m2[x]>=m1[x]){
			check[m2[x]-m1[x]]++;
		}else{
			check[m2[x]+n-m1[x]]++;
		}
	}
	int ans = 0;
	for(auto itr = check.begin(); itr != check.end();itr++){
		ans = max(ans,itr->second);
	}
	cout << ans << "\n";
}