/*=========================================================================================================
  APPROCH: USING MERRGE SORT, the 2 arrays that you will combine, 
  i.e. array1: low   to mid
       array2: mid+1 to hi

  NOTE: YOU MAY USE "cnt" as global variable and avoid recursion 
        OR  YOU MAY PASS "cnt" BY REFERENCE
=========================================================================================================*/


// merge 2 sorted arrays
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;       // temporary array
    int left = low;         // starting index of left half of arr
    int right = mid + 1;    // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);       // left half                  // left  half inversions
    cnt += mergeSort(arr, mid + 1, high);  // right half                 // right half inversions
    cnt += merge(arr, low, mid, high);     // merging sorted halves      // curr  half inversions
    return cnt; 
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}






/*=========================================================================================================
// APPROCH 2 = BRUTE FORCE : tc: O(n2)
int inver(int arr[],int n){
     int count = 0;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j])
             count++;
        }
      }
     return count;
}
=========================================================================================================*/
