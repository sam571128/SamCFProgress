#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int count=0;
	while(n--){
		int count1 = 0,temp;
		for(int i = 0;i < 3;i++){
			cin >> temp;
			if(temp==1){
				count1++;
			}
		}
		if(count1>=2){
			count++;
		}
		
	}
	cout << count;
}