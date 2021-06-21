// XOR solution
// when exclusive or occurs the number will produce 0 when find a pair
// 1 ^ 1 = 0
// 2 ^ 2 = 0
// 1 ^ 2 ^ 1 ^ 2 ^ 4 = 4
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }
        return result;

    }
};

// Hashtable solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // set up hash set
        unordered_set<int> set;
        for (int i; i < nums.size(); i++) {
            if (set.find(nums[i]) == set.end()) { // if nums[i] is not in the map
                set.insert(nums[i]); // insert it in the map
            }
            else {
                set.erase(nums[i]);// if nums[i] is in the map you erase it
            }
        }
        
        return *set.begin(); // return the only value which is non repeated
    }
};
/*
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1

*/

//other hashmap solution
// use of auto
    unordered_set<int> mySet;
    for(int i = 0;i < nums.size();++i){
        if(mySet.find(nums[i]) == mySet.end()) mySet.insert(nums[i]);
        else mySet.erase(nums[i]);
    }
    auto it = mySet.begin();
    return *it;


