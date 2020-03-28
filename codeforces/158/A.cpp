#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> arr;
    while(n--){
    	int a;
    	cin >> a;
        arr.push_back(a);
    }
    sort(arr.rbegin(),arr.rend());
    int count = 0;
    for(int i = 0;i < arr.size();i++){
    	if(arr.at(i)>=arr.at(k-1)&&arr.at(i)!=0){
    		count++;
		}
	}
	cout << count; 
    return 0;
}