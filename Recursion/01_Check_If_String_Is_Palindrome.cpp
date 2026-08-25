/*
Problem: Check if String is Palindrome
Topic: Recursion
Source: Striver A2Z DSA Sheet

==================================================
WHAT I LEARNED WHILE SOLVING THIS PROBLEM
==================================================

APPROACH 1: Reverse the string recursively
------------------------------------------
My first approach was:

1. Store the original string.
2. Recursively reverse the given string.
3. Compare the reversed string with the original string.

This approach works, but it does unnecessary work.
We don't actually need to reverse the whole string to check
whether it is a palindrome.

I then improved the solution using direct recursion.

--------------------------------------------------
MISTAKE I MADE: string& vs &s
--------------------------------------------------

My reverse function was:

    void reverse(string& s, int left, int right)

While calling it, I initially wrote:

    reverse(&s, 0, n - 1);    // WRONG

The correct call is:

    reverse(s, 0, n - 1);     // CORRECT

Why?

    string& s
    -> means s is a reference to a string.

    &s
    -> means the address of s is being taken.
       This gives a pointer (string*).

Therefore, &s cannot be passed to a function expecting
string&.

Important distinction:

    s      -> the string
    &s     -> address of the string
    string& -> reference to the string

--------------------------------------------------
PASS BY VALUE vs PASS BY REFERENCE
--------------------------------------------------

If I write:

    void check(string s, ...)

the string is passed by value.
A copy of the string is created.

If I write:

    void check(string& s, ...)

the string is passed by reference.
No copy of the string is created.

So reference passing is useful when I don't want to
create an unnecessary copy of a large string.

--------------------------------------------------
WHAT I LEARNED ABOUT const
--------------------------------------------------

In this problem, I only READ the string.

I don't modify it anywhere.

Therefore, the technically cleaner version is:

    const string& s

This means:

    const
    -> the function cannot modify the string.

    &
    -> the string is passed by reference, so no copy is made.

For example:

    void check(const string& s)

allows:

    cout << s[0];       // CORRECT
    if (s[0] == 'a')    // CORRECT

but prevents:

    s[0] = 'x';         // WRONG

So:

    string s
        -> pass by value, creates a copy

    string& s
        -> pass by reference, can modify original

    const string& s
        -> pass by reference, cannot modify original

For this problem, const string& is the best choice because
the string is only being read.

==================================================
APPROACH 2: DIRECT RECURSIVE PALINDROME CHECK
==================================================

Instead of reversing the string:

1. Compare the first and last characters.
2. If they are different -> not a palindrome.
3. If they are equal -> move both pointers towards the center.
4. Continue recursively.

Example:

    "madam"

     m a d a m
     ^       ^
     |       |
    left   right

Compare m and m -> equal

      a d a
      ^   ^
      |   |

Compare a and a -> equal

        d
        ^
        |

Pointers meet -> palindrome.

==================================================
COMPLEXITY
==================================================

Time Complexity: O(n)

Space Complexity: O(n)

The recursion goes approximately n/2 levels deep,
so the recursive call stack uses O(n) space.
*/


class Solution {
public:

    bool palindromeCheck(const string& s) {
        return check(s, 0, s.length() - 1);
    }

private:

    bool check(const string& s, int left, int right) {

        // Base case:
        // If the pointers meet or cross,
        // all corresponding characters matched.
        if (left >= right)
            return true;

        // If characters from opposite ends don't match,
        // the string is not a palindrome.
        if (s[left] != s[right])
            return false;

        // Move both pointers towards the center
        // and check the remaining substring recursively.
        return check(s, left + 1, right - 1);
    }
};
