Given an array with n - 1 elements having one missing element, and every element is in the range [1, n]. Find the missing element.

i/p - 2 1 3 5 6
0/p - 4

appr - XOR  - 2^1^3^5^6 ^ (range(n))
    - hashmap
    - summation - OverflowError
    - sorting