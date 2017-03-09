#include<iostream>
using namespace std;
int subSum(int sub[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += sub[i];
	}
	return sum;
}
int maxSubSum(int arr[], int len) {
	int** sub = new int*[len];
	sub[1] = new int[1]{ arr[0] };
	int sub_sum= subSum(sub[1], 1);
	int max_sub_sum = sub_sum;   //最大和
	int pos_start = 0;  //和最大子数组起始位置
	int pos_end = 0; //和最大子数组结束位置
	for (int i = 1; i < len; i++) {

		
		if (arr[i] + sub_sum >= max_sub_sum && arr[i] + sub_sum >= arr[i]) {
			sub_sum += arr[i];
			max_sub_sum = sub_sum;
			pos_end = i;
		}
		else if (arr[i] >= max_sub_sum) {
			sub_sum = max_sub_sum = arr[i];
			pos_start = pos_end = i;
		}
		else{
			sub_sum += arr[i];
		}
	}
	for (int i = pos_start; i <= pos_end; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << max_sub_sum;
	return max_sub_sum;
}

int main() {
	int arr[8] = { 1,-2,3,10,-4,7,2,-5 };
	maxSubSum(arr, 8);
	system("pause");
}