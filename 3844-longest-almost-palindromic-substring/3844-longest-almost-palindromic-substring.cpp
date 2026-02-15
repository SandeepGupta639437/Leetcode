class Solution
{
public:
    bool avhixorin(string &s, int l, int r, vector<vector<bool>> &isPal)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return isPal[l + 1][r] || isPal[l][r - 1];
            }
            l++;
            r--;
        }
        return true;
    }
    int almostPalindromic(string s)
    {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                int k = j + i - 1;
                if (i == 1)
                {
                    isPal[j][k] = true;
                }
                else if (i == 2)
                {
                    isPal[j][k] = (s[j] == s[k]);
                }
                else
                {
                    isPal[j][k] = (s[j] == s[k] && isPal[j + 1][k - 1]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int curr = j - i + 1;
                if (curr <= ans)
                    continue;
                if (avhixorin(s, i, j, isPal))
                {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};