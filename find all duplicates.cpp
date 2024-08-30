#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
        // Ensure each number is at its correct index
        if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        } else {
            i++;
        }
    }

    vector<int> duplicates;
    // Find all numbers that are not in their correct position
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            duplicates.push_back(nums[i]);
        }
    }
    return duplicates;
}

int main() {
    vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result1 = findDuplicates(nums1);
    cout << "Output: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl; // Output: [2, 3]

    vector<int> nums2 = {1, 1, 2};
    vector<int> result2 = findDuplicates(nums2);
    cout << "Output: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl; // Output: [1]

    vector<int> nums3 = {1};
    vector<int> result3 = findDuplicates(nums3);
    cout << "Output: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl; // Output: []

    return 0;
}

