#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
// int largestEle(int arr[], int n){
//     int larEle = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i]>larEle){
//             larEle = arr[i];
//         }
//     }
//     return larEle;
// }
// int main(){
//     int arr[6] = {4,52,53,21,55,111};
//     int result = largestEle(arr, 6);

//     cout << "Largest element is: "<< result<< endl;
//     return 0;
// }

// int main(){
//     int arr[5] = {3,5,1,5,11};
//     int key;
//     int sizeArr = sizeof(arr)/sizeof(arr[0]);
//     cout<<"Enter element to search index: ";
//     cin>>key;
//     for (int i=0; i<sizeArr; i++){
//         if(arr[i]==key){
//             cout<< "Element found at "<<i<<endl;
//             return 0;
//         }
//     }
//     cout <<"Element not found"<<endl;
//     return 0;
// }

void printArr(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
}

void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1<size){
            swap(arr[i], arr[i+1]);
        }
    }
}
// int main(){
//     int arr[9] = {5,2,5,6,63,11,24,11,9};
//     swapAlternate(arr,9);
//     cout<<"Result is: "<<endl;
//     printArr(arr, 9);
// }

int printUnique(int arr[],int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
// int main(){
//     int arr[9] = {1,2,2,4,5,4,1,1,1};
//     int result = printUnique(arr, 9);
//     cout << "Result "<<result<<endl; 
// }

// int printDuplicate(int arr[], int size) {
//     int ans = 0;
//     // XOR all array elements
//     for(int i = 0; i < size; i++) {
//         ans = ans ^ arr[i];
//     }
//     // XOR with numbers from 1 to n-1 (where n is the size)
//     for(int i = 1; i < size; i++) {
//         ans = ans ^ i;
//     }
//     return ans;
// }

// int main() {
//     int arr[] = {5, 1, 3, 4, 4};
//     int size = 5; // Actual number of elements
//     int result = printDuplicate(arr, size);
//     cout << "Duplicate number is: " << result << endl;
// }

vector<int> addDuplicate(vector<int>& nums){
    vector<int> ans;
    for(int i=0; i<nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if(nums[index] < 0){
            ans.push_back(abs(nums[i]));

        }
        nums[index] = -nums[index];
    }
    return ans;
}

// int main(){
//     vector<int> nums = {4,5,6,4,5,7};
//     vector<int> ans = addDuplicate(nums);

//     cout <<"Result is: "<< endl;
//     for(int num : ans){
//         cout << num << " ";
//     }
//     return 0;
    
// }

// int main(){
//     vector <char> vect = {'a','b','c'};
//     for(char val: vect){
//         cout << val<< endl;
//     }
//     return 0;
// }    

// void revArr(vector<int>& arr){
//     int start = 0;
//     int end = arr.size()-1;
//     while(start<end){
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }
// }
// int main(){
//    vector <int> arr = {1,5,6,42,21};
//     revArr(arr);

//    for(int num:arr){
//     cout << num<< " ";
//    }
//    return 0;
// }

// int duplicateNum(vector <int> & arr){
//     int ans = 0;
//     for(int i=0; i< arr.size(); i++){
//         ans ^= arr[i];
//     }
//     return ans;
// }
// int main(){
//     vector <int> arr = {6,2,6,2,1,3,4,3,4,1,8};
//     int result = duplicateNum(arr);

//     cout<< result<< endl;
// }

// int main(){
//     int curSum = 0;
//     int maxSum = INT_MIN;
//     vector <int> arr = {3,-4,5,4,-1,7,-8};
//     for(int i=0; i< arr.size(); i++){
//         curSum += arr[i];
//         maxSum = max(curSum, maxSum);
//         if(curSum<0){
//             curSum = 0;
//         }
//     }
//     cout<< maxSum<< endl;
//     return maxSum;
// }

// vector<int> twoSum(vector<int> & nums, int target){
//     unordered_map<int, int> hashMap;
//     for(int i=0; i<nums.size(); i++){

//         int complement = target - nums[i];
//         if(hashMap.find(complement) != hashMap.end()){
//             return {hashMap[complement], i};
//         }
//         hashMap[nums[i]] = i;
//     }
//     return {};
// }

// int main(){
//     vector<int> arr = {2,5,6,7,21,12};
//     int target = 9;
//     vector<int>  result = twoSum(arr, target);

//     if(!result.empty()){
//         cout<< "Indices found: ["<< result[0]<<", "<<result[1]<< "]"<<endl;
//         cout<< "Numbers that sum to "<<target << " are: "<<arr[result[0]]<< " and "<< arr[result[1]]<<endl;
//     }
//     return 0;
// }

// vector <int> mostFreqEle (vector<int> &nums){
//     for(int val: nums){
//         int freq = 0;

//         for(int el: nums){
//             if(el == val){
//                 freq++;
//             }
//         }
//     }
// }
// int main(){
//     vector<int> arr = {1,2,2,1,1};
//     vector<int> result = mostFreqEle(arr);

    
//     cout<< "The freq element is "<<result[0]<<endl;
// }

vector<int> rotateArr(vector<int> &arr, int k){
    int temp = arr[0];
    for (int i = 1; i<k; i++){
        arr[i - 1] = arr[i];
    }
    arr [ k - 1] = temp;
    return arr;
}
int main(){
    vector<int> arr = { 1,2,4,6,8,9};
    int k = 3;
    vector<int> result = rotateArr(arr, k);

    for(int val: result){
        cout<< val<< " ";
    }
}