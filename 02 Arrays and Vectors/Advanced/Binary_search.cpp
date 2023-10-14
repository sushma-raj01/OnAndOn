
#include <algorithm>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int binarySearch(int* searchSpace, int s, int e, int num)
{
	int ans;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (searchSpace[mid] >= num) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}

	return ans;
}

int longestSubArr(int* arr, int n)
{
	
	int searchSpace[n];
	int index[n];

	int j = 0;
	int ans = 0;

	for (int i = 0; i < n; ++i) {

		if (j == 0 or searchSpace[j - 1] < arr[i]) {
			searchSpace[j] = arr[i];
			index[j] = i;
			j++;
		}

		int idx = binarySearch(searchSpace, 0, j - 1, arr[i]);
		//calling binary search to find the element with lowest index and value greater than current index.
		ans = max(ans, i - index[idx] + 1);
	}
	return ans;
}

int main()
{
	int arr[] = { -5, -1, 7, 5, 1, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubArr(arr, n) << endl;
	return 0;
}
