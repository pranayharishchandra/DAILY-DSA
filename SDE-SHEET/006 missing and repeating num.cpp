https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


/*
APPROCH 3 - OPTIMAL
MISSING AND REPEATING

X - Y
X2 - Y2 

(using above 2 find X + Y by diving 2 equations)

X -> REPEATING NUM
Y -> MISSING NUM

then can be found out SOLVING:  X + Y AND X - Y

*/
class Solution {
public:
    vector<int> findTwoElement(vector<int> a, int nn) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
    }
};

/*
APPROCH 2 - better
USING HASH ARRAY
array with freq of n elements initially 0
inc the freq as u get traverse elements

freq[arr[i]]++

then again use a for loop to traverse over freq arr
to find element 0 -> missing num, 2 -> repeating num

TC: O(n) + O(n)
SC: O(n)

*/



// TC:o(n), SC: o(1)

/*
APPROCH 1 - opitmal
(missing number)  =  (sum of all elements in array) - (sum of first n numbers)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total_sum = (n*(n+1))/2;
        for(auto x: nums){
            total_sum -=x;
        }
        return total_sum;
    }
};

