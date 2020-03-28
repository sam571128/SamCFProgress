#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	vector<string> v;
	while(n--){
		string temp;
		cin >> temp;
		v.push(temp);
	}
	int count = 1;
	for(int i = 1;i < v.size();i++){
		if(v[i]!=v[i-1])
			count++;
	}
	cout << count;
}