# Love Rescue

[link](https://codeforces.com/problemset/problem/939/D)

1. Create a set for each letter
2. Lopp on each corresponding letters
3. If the 2 letters are not similar, we would like to buy a new Mana ONLY IF there are no way to reach one letter from the other. So store these 2 letters and unifiy their sets.
4. Print the number of your stored pairs of letters then print each pair.

Space complexity: O(n)
Time complexity: O(n)

`n->length of the strings'
