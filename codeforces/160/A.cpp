#include <bits/stdc++.h>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	vector<int> values;
	int sum = 0;
	while(a--){
		int temp;
		cin >> temp;
		sum+=temp;
		values.push_back(temp);
	}
	sort(values.rbegin(),values.rend());
	int sum2 = 0;
	int result = 0;
	for(int i = 0;i < values.size();i++){
		result++;
		sum-=values[i];
		sum2+=values[i];
		if(sum2>sum){
			break;
		}
	}
	cout<<result;
}