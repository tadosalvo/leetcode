class Solution {
public:
    void reverseString(vector<char>& s) {
        // ["h","e","l","l","o"]
        // ["o","l","l","e","h"]
        
        // swap first and last element of array
        // iterate first up and last down
        int end = s.size() - 1;
        int size = s.size();
        char temp = 'a';
        for (int i = 0; i < size / 2; i++) {
            temp = s[i];
            s[i] = s[end - i];
            s[end - i] = temp;
        }
    }
};