#include <bits/stdc++.h>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	int count[4];
	for(int i = 0;i < 4;i++){
		count[i] = 0;
	}
	while(t--){
		int temp;
		cin >> temp;
		count[temp-1]++;
	}
	int result = 0;
	
	//Add 4s to the result
	result+=count[3];
	//Pair 1,3
	while(count[0]>0&&count[2]>0){
		result++;
		count[0]-=1;
		count[2]-=1;
	}
	//If 1s has left
	count[1]+=count[0]/2;
	count[0]%=2;
	
	//If 3s has left
	result+=count[2];
	//Pair 2s
	result+=count[1]/2;
	count[1]%=2;
	
	//Pair 1,2
	while(count[0]>0&&count[1]>0){
		result++;
		count[0]-=1;
		count[1]-=1;
	}
	//If 1 has left
	result+= count[0]/4;
	count[0]%=4;
	if(count[0]>0){
		result++;
	}
	//If 2 has left
	if(count[1]>0){
		result++;
	}
	
	
	
	cout<<result;
	
}