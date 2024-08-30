#include <iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
        // Place each number at its correct index
        if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        } else {
            i++;
        }
    }

    // Find the duplicate and missing numbers
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return {nums[i], i + 1}; // nums[i] is the duplicate, i + 1 is the missing number
        }
    }
    return {};
}

int main() {
    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> result1 = findErrorNums(nums1);
    cout << "Output: [" << result1[0] << "," << result1[1] << "]" << endl; // Output: [2, 3]

    vector<int> nums2 = {1, 1};
    vector<int> result2 = findErrorNums(nums2);
    cout << "Output: [" << result2[0] << "," << result2[1] << "]" << endl; // Output: [1, 2]

    return 0;
}
