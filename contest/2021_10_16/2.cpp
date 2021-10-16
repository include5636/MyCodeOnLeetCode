#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0, len = colors.length(), numA = 0, numB = 0;
        for (int i = 0; i < len; i++) {
            if (colors[i] == 'A') {
                numB = 0;
                numA++;
                if (numA >= 3) {
                    alice++;
                }
            } else {
                numA = 0;
                numB++;
                if (numB >= 3) {
                    bob++;
                }
            }
        }
        if (alice > bob) {
            return true;
        } else {
            return false;
        }
    }
};