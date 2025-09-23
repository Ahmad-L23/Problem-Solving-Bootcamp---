#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from a sorted array
// It modifies the array in-place and returns the number of unique elements
int removeDuplicates(vector<int>& nums) {
    // If array is empty, there are no unique elements
    if(nums.empty()) return 0;

    int left = 0; // "left" points to the position of the last unique element

    // Start "right" from index 1 and move through the array
    for(int right = 1; right < nums.size(); right++){
        // If we find a new unique element (different from nums[left])
        if(nums[right] != nums[left]){
            left++;                  // Move left forward
            nums[left] = nums[right]; // Place the new unique element
        }
    }

    // The number of unique elements is left + 1 (since index starts at 0)
    return left + 1;
}

// Function to read the input array from the user
vector<int> readArray() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements in sorted order: ";
    for(int i = 0; i < n; i++) 
        cin >> nums[i];

    return nums;
}

// Function to print the result after removing duplicates
void printResult(const vector<int>& nums, int k) {
    cout << "Number of unique elements: " << k << endl;
    cout << "Unique elements: ";
    for(int i = 0; i < k; i++) 
        cout << nums[i] << " "; // print only the unique part of the array
    cout << endl;
}

int main() {
    // Step 1: Read the sorted array
    vector<int> nums = readArray();

    // Step 2: Remove duplicates and get the count of unique elements
    int k = removeDuplicates(nums);

    // Step 3: Print the result
    printResult(nums, k);
}
