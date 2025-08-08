#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums, int left, int mid, int right, int& inversion_count){
    vector<int> tp;
    int i = left, j = mid+1;
    while(i <= mid and j <= right){
        if(nums[i] <= nums[j]){
            tp.push_back(nums[i]);
            i++;
        }
        else{
            inversion_count += (mid - i + 1); // Count inversions
            // All elements from i to mid are greater than nums[j]
            // because nums[i] > nums[j] and i < j
            // So, we can add the count of these elements to inversion_count
            // as they form inversions with nums[j]
            // This is because the array is sorted in the left half
            // and nums[j] is less than all elements from i to mid.
            // Hence, we can directly count them.
            tp.push_back(nums[j]);
            j++;
        }   
    }
    while(i <= mid){
        tp.push_back(nums[i]);
        i++;
    }
    while(j <= right){
        tp.push_back(nums[j]);
        j++;
    }
    for(int k = left; k<= right;k++){
        nums[k] = tp[k - left];
    }

}
void ms(vector<int>& nums, int left, int right, int& inversion_count){
    if(left >= right) return; // base case
    int mid = left + (right - left) / 2;
    ms(nums, left,mid,inversion_count);
    ms(nums,mid+1,right,inversion_count);
    merge(nums,left,mid,right,inversion_count);
}
int main(){
    //Given an integer array nums. Return the number of inversions in the array.
    //Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
    vector<int> nums = {2, 3, 7, 1, 3, 5};
    int n = nums.size();
    int inversion_count = 0;
    ms(nums, 0, n-1,inversion_count);
    cout << "Number of inversions: " << inversion_count << endl;
    return 0;   
}