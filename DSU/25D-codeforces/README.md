# Roads not only in Berland

[Roads not only in Berland](https://codeforces.com/problemset/problem/25/D)

### Notations
k -> number of cities
e -> number of roads (k-1) //Given

### Algorithm
1. Create a set for each city -k sets- initially each one is the root of itself
2. Unify each 2 connected cities
- If the are already unified, the store this extra edge and increment the counter
3. Choose 2 sets to unify , print the output (The pair of the stored edge + the 2 roots of the recently unified cities)
4. Repeat step number 3 `counter` times.
