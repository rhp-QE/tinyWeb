#include <iostream>
#include <bits/stdc++.h>

using namespace ::std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    unordered_set<int> sum, sub, cow;
    int n;
    vector<string> vec;
    vector<vector<string>> res;

    void solve(int row) {
        if (row == n) {
            res.push_back(vec);
            return;
        }
        string str(n,'.');
        for (int i = 0; i < n; ++i) {
            if (sum.find(i + row) != sum.end()) continue;
            if (sub.find(row - i) != sub.end()) continue;
            if (cow.find(i) != cow.end()) continue;
            str[i]='Q';
            vec.push_back(str);

            sum.insert(row+i),sub.insert(row-i),cow.insert(i);

            solve(row+1);

            sum.erase(row+i),sub.erase(row-i),cow.erase(i);;
            vec.pop_back();
            str[i]='.';
        }
    }

    int totalNQueens(int c) {
        n=c;
        solve(0);
        return res.size();
    }
};

int main(){
    cout<<"modify"<<endl;
    cout<<"fadsf"<<endl;
}