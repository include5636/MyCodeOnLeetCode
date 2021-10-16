class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int size = stones.size(), zero = 0, one = 0, two = 0;
        for (int i: stones) {
            if(i % 3 == 0) {
                zero++;
            }
            else if(i % 3 == 1) {
                one++;
            }
            else two++;
        }
        if(one > two) 
            swap(one, two);
        if(one > 1) {
            two -= one - 1;
            one = 1;
        }
        if((one == 0) && (two == 0 || two == 1 || two == 2))
            return 0;
        else if(one == 0)
            return zero % 2;
        else if(one == 1 && two >= 4)
            return 1;
        else
            return 1 - zero % 2;
    }
};

/*

        2 1 2 1 0
            1 2 2
        0 odd -> bob first
        0 even -> no influence

        0 0 / 0 1 / 1 0 / 0 2 / 2 0 -> bob win
        0 3(>=3) / 3(>=3) 0 -> second win 
        1 1 / 1 2(>=2) / 2(>=2) 1 -> first win
        3 3 | 1 1 1 2 2 2 -> 1 1 2 2 -> 1 2
        5 7 -> 1 3
            
            
            X 2 2(>=2) | 1 1 2 ... 2 -> first win
            X 2(>=2) 2 | 1 ... 1 2 2 -> first win
        1 1 2 1 2 1 2
        2 2 1 2 1 2 1

                if(one > 1) {
            two -= one - 1;
            one = 1;
        }
        [20,3,20,17,2,12,15,17,4]
        2 0 2 2 2 0 0 2 1
        3 1 5 ALICEWIN
        bob first
        2 0 0 0 2 

        1 1 4
        0 1 2 2 2

        

        0 1 2 2 2 2 2
        2 0 2 1 2 2 alice win
        2 2 0 1 2 2 alice win

        0 0 1 2 2 2 2 
        X 1 4() -> ALICE WIN
        

*/