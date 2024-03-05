#include <vector>
using namespace std;
/* BRUTE APPROCH
Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
 */

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size();

    int len = 0;
    for (int i = 0; i < n; i++) {     // starting index
        for (int j = i; j < n; j++) { // ending index
              // add all the elements of subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int f(vector<int> a, int k) {
    int len = getLongestSubarray(a, k);
    return len;
}

/** BETTER APPROCH
Time Complexity: O(N2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.
*/
#include <vector>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        int s = 0;
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int f(vector<int> a, int k) {
    int len = getLongestSubarray(a, k);
    return len;
}

/** OPTIMAL APPROCH
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)
(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) 
but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N)
as we are using a loop to traverse the array.

Space Complexity: O(1) as we are not using any extra space.
*/
#include <vector>
#include <map>
using namespace std;
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int f(vector<int> a, int k) {
    int len = getLongestSubarray(a, k);
    return len;
}


/** OPTIMAL APPROCH (works on negative + postive elements containing mixture)
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)
(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) 
but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N)
as we are using a loop to traverse the array.

Space Complexity: O(1) as we are not using any extra space.
*/
int getLongestSubarray(vector<int>& arr, int k){

	// int    k = 0; // sum of each subarray should 0
	int    n = arr.size();
	int maxi = 0; // stores largest length of subarray found 
	int   ps = 0;
	
	unordered_map <int, int> um;  // storing {ps, idx}
	um.insert({0,-1});            // before 0th idx we have subarray sum = 0, i.e. empty subarray

	for (int i=0; i<n; i++)
	{
		ps += arr[i];
		int remove = ps - k;

		// IF REMAINIG PART i.e. remove IS AVALIBLE IN um
		if (um.find(remove) != um.end()) {
			int currLength = i - um[remove]; // length of current subarray with sum = 0
			maxi = max (maxi, currLength);
		}
		// IF ps NOT PRESENT THEN JUST ADD PS INTO HASHMAP WITH THE IDX, 
		// IF IT'S PRESENT THEN MAKE SURE YOU DON'T UPDATE THE LENGTH, SINCE YOU WANT LONGEST SUBARRAY, 
		// so min idx for max length
		if (um.find(ps) == um.end()) {
			um[ps] = i;
		}
	}
	return maxi;
}


/** MOST OPTIMAL APPROCH - (BUT WORKS ONLY FOR POSITIVE NUMBERS ONLY CONTAING ARRAY)
Time Complexity: O(N)

Space Complexity: O(1) as we are not using any extra space.
*/
int getLongestSubarray(vector<int>& arr, int k){
  // works only on array with positive elements

	int    n = arr.size();
	int maxi = 0; // stores largest length of subarray found till now

  int right = 0, left = 0;
  int sum = 0; // sum from left to right
	
  while (right < n && left < n) {

    if (sum == k) {
      maxi = max(right - left + 1, maxi);
      right++;
      sum += arr[right];
    }
   
    else if (sum < k) {  // you need to increase the sum by adding elements
      right++;
      sum += arr[right];
    }

    else {
      sum -= arr[left];
      left++;
    }
  }
	return maxi;
}

