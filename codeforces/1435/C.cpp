// C++ program to finds out smallest range that includes 
// elements from each of the given sorted lists. 
#include <bits/stdc++.h> 
  
using namespace std; 
  
// This function takes an k sorted lists in the form of 
// 2D array as an argument. It finds out smallest range 
// that includes elements from each of the k lists. 
void smallestRange(vector<vector<int>>& nums) {
    int rangeLeft = 0, rangeRight = INT_MAX;
    int size = nums.size();
    vector<int> next(size);
    
    auto cmp = [&](const int& u, const int& v) {
        return nums[u][next[u]] > nums[v][next[v]];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    int minValue = 0, maxValue = INT_MIN;
    for (int i = 0; i < size; ++i) {
        pq.emplace(i);
        maxValue = max(maxValue, nums[i][0]);
    }

    while (true) {
        int row = pq.top();
        pq.pop();
        minValue = nums[row][next[row]];
        if (maxValue - minValue < rangeRight - rangeLeft) {
            rangeLeft = minValue;
            rangeRight = maxValue;
        }
        if (next[row] == nums[row].size() - 1) {
            break;
        }
        ++next[row];
        maxValue = max(maxValue, nums[row][next[row]]);
        pq.emplace(row);
    }

    cout << rangeRight-rangeLeft << "\n";
}

  
// Driver program to test above function 
int main() 
{ 
	int a[6];
	for(auto &x : a) cin >> x;
	sort(a,a+6,greater<int>());
	int n;
	cin >> n;
    vector<vector<int>> arr(n,vector<int>(6)); 
  	for(int i = 0, tmp;i < n;i++){
  		cin >> tmp;
  		for(int j = 0;j < 6;j++){
  			arr[i][j] = tmp-a[j];
  		}
  	}
  
    smallestRange(arr); 
  
    return 0; 
} 