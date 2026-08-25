# DSA Learning Notes

## Recursion

### Palindrome Check

Mistake:
I initially called:

reverse(&s, 0, n - 1);

while the function expected:

void reverse(string& s, int left, int right)

`string&` is a reference to a string,
while `&s` is the address of the string.

Therefore:

reverse(s, 0, n - 1);   // correct
reverse(&s, 0, n - 1);  // incorrect

### C++ Reference Learning

string s
→ pass by value

string& s
→ pass by reference, can modify original

const string& s
→ pass by reference, cannot modify original
