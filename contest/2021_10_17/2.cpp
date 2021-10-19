#include<bits/stdc++.h>
using namespace std;

class Bank {
public:
    vector<long long> bal;
    int n = 0;
    Bank(vector<long long>& balance) {
        n = balance.size();
        for (int i = 0; i < n; i++){
            bal.push_back(balance[i]);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n || bal[account1 - 1] < money) {
            return false;
        }
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) {
            return false;
        }
        bal[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n || bal[account - 1] < money) {
            return false;
        }
        bal[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */