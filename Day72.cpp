class Solution {
public:
    int minReorder(int n1, vector<vector<int>>& test) {
        int result = 0;
        vector<bool> ans(n1, false);
        ans[0] = true;
        vector<vector<int>> n2(n1);
        for (const auto& val : test) {
            n2[val[0]].push_back(-1 * val[1]);
            n2[val[1]].push_back(val[0]);
        }
        stack<int> stk;
        stk.push(0);

        while (!stk.empty()) {
            int curr = stk.top();
            stk.pop();
            for (const auto& elem : n2[curr]) {
                if (!ans[abs(elem)]) {
                    if (elem < 0) result++;
                    ans[abs(elem)] = true;
                    stk.push(abs(elem));
                }
            }
        }

        return result;
    }
};
