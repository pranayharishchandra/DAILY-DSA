/*====================================================================================================
          Time complexity: O(nlogn) 

Reason: At each step, we divide the whole array, 
for that logn and we assume n steps are taken to get sorted array, 
so overall time complexity will be nlogn

          Space complexity: O(n)  

Reason: We are using a temporary array to store elements in sorted order.

Auxiliary Space Complexity: O(n)
====================================================================================================*/

// merge 2 sorted arrays : tc: O(n) sc: O(n)
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;      // temporary array
    int left = low;        // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}
