# Router Problem

Alice just bought a very big house with N rooms and N-1 doors, which each door connected to two rooms. Each room has at least one door and at most 3 doors. Alice can go to every room in this house. 


However, a modern person cannot live without Wifi, so Alice wants to put M wireless routers in several rooms. Since routers are cheap, only adjacent rooms (which have a door connect to this room) can receive wifi and each router works independently.
As M routers may not cover every room, Alice tells you the satisfaction point S[i] she could have if room i has Wifi.
Please help Alice calculate the maximum satisfaction point she can get in total.

Input

The first line composes of two integers N(2 <= N <= 1000), M(1 <= M <= N, M <= 100) followed by N lines, where each shows the satisfaction S[i](1 <= S[i] <= 10) point of room i. After that are N - 1 lines, with each containing two integers x, y, which represents a door between room x and y.

Output

Just output the maximum point of satisfaction.

Limits

-Memory limit per test: 256 megabytes

-Time limit per test: The faster the better 

Compile

C++, JAVA

Sample Test

Input

5 1

1 2 3 4 5

2 1

3 2

4 2

5 3

Output

10
