class Solution {
public:
    bool palindromeCheck(string& s) {
        return check(s, 0, s.length() - 1);
    }

    bool check(string& s, int left, int right) {
        if (left >= right)
            return true;

        if (s[left] != s[right])
            return false;

        return check(s, left + 1, right - 1);
    }
};
