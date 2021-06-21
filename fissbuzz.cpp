class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // loop
        // per iteration
        // check if divisible by 3 and 5
        // check if divisible by 3
        // check if divisible by 5
        // if non are true we print out the current i
        vector<string> res;
        
        for(int i = 1; i <= n; i++) {
            if ((i % 3 == 0) && (i % 5 == 0) ) {
                res.push_back("FizzBuzz");
            }
            else if (i % 3 == 0){
                res.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                res.push_back("Buzz");
            }
            else {
                res.push_back(to_string(i));
            }
            
        }
        return res;
    }
};

// without if else
//
Read More
Good approach and leads to good discussion with interviewer. Division/mod can be expensive operation. Writing to memory will often be cheaper, so doing extra writes is probably better than expensive arithmetic.
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};