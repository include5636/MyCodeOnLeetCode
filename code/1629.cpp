class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int maxTime = releaseTimes[0];
        char key = keysPressed[0];
        for (int i = 1; i < n; i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if ((duration > maxTime) || (duration == maxTime && keysPressed[i] > key)) {
                maxTime = duration;
                key = keysPressed[i];
            }
        }
        return key;
    }
};