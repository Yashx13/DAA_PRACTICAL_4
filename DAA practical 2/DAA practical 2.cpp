#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


int maxCrossSum(std::vector<int>& arr, int low, int mid, int high,int constraint) {

    int sum = 0;
    int leftSum = sum;
    for (int i = mid; i >= low; i--) {
        sum += arr[i]; // first calculate
		if (sum <= constraint) {
			leftSum = std::max(leftSum, sum);
		}
    }

    sum = 0;
    int rightSum = sum;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum <= constraint) {
            rightSum = std::max(rightSum, sum);
        }
        
    }
	int max = std::max(leftSum, rightSum);

    return max;
}


int maxSubArray(std::vector<int>& arr, int low, int high,int constraint) {

    if (low == high) return arr[low];
    int mid;
    mid = (low + high) / 2;

    int left = maxSubArray(arr, low, mid, constraint);
    int right = maxSubArray(arr, mid + 1, high, constraint);
    int cross = maxCrossSum(arr, low, mid, high, constraint);

    for (int i = low; i <= high; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Low:" << low << " High:" << high <<std::endl;
    std::cout << std::endl;
   

    int maximum = std::max({ left,right,cross });

    return maximum;
}

int main() {
    std::vector<int> arr = { 2, 1, 3, 4 };
    int size = arr.size(); 
    int constraint = 5;

    int high = size - 1;
    int low = 0;

    int MAAAA = maxSubArray(arr, low, high, constraint);

    std::cout << "Maximum Value " << MAAAA << std::endl;

    return 0;

}








