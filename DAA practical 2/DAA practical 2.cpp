#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxCrossSum(std::vector<int>& arr, int low, int mid, int high) {
    int sum = 0, leftSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = std::max(leftSum, sum);
        //if (sum <= constraint)
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = std::max(rightSum, sum);
        //if (sum <= constraint)
    }

   /* if (leftSum == INT_MIN) leftSum = 0;
    if (rightSum == INT_MIN) rightSum = 0;

    int crossSum = leftSum + rightSum;
    return (crossSum <= constraint) ? crossSum : std::max(leftSum, rightSum);*/
	return leftSum + rightSum;
}

int maxSubArray(std::vector<int>& arr, int low, int high) {
    if (low == high) return arr[low];

    int mid = low + (high - low) / 2;

    int left = maxSubArray(arr, low, mid);
    int right = maxSubArray(arr, mid + 1, high);
    int cross = maxCrossSum(arr, low, mid, high);

    return std::max({ left, right, cross });
}

int main() {
    std::vector<int> arr = { 3,4,5,6,-4,2,-6,-7};

    int result = maxSubArray(arr, 0, arr.size() - 1);
    std::cout << "Maximum Value: " << result << std::endl;

    return 0;
}
