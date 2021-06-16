class Solution
{
public:
    vector<string> s;

    void solve(int left, int right, int x, string y)
    {
        if (right > left || left > x)
        {
            return;
        }

        if (right == left && right == x)
        {
            s.push_back(y);
            return;
        }

        solve(left + 1, right, x, y + "(");
        solve(left, right + 1, x, y + ")");
    }

    vector<string> generateParenthesis(int n)
    {
        solve(0, 0, n, "");
        return s;
    }
};