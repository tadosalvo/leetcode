// Brute force solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result;
        int value1 = 0;
        int value2 = 0;
        for(int i = 0; i < size - 1; i++) {
            value1 = nums[i];
            for(int j = 0; j < size - 1; j++) {
                value2 = nums[j];
                if(value1 + value2 == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

// Hashmap solution One pass solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // key is the num and val is index in vector
        unordered_map<int, int> hash;
        vector<int> result;
        
        int size = nums.size();
        
        for(int i = 0; i < size; i++) {
            
            int complement = target - nums[i];
            // if compliment is in map return both
            if (hash.find(complement) != hash.end()) { // if complement is in the container
                result.push_back(hash[complement]); // value is complements index
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i; // inputing as we iterate through the array
        }
        return result;
    }
};