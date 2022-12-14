/*

CodeStudios Weekend Contest - 43 (Q-3 Medium)


Problem:

A kingdom consists of 'N' cities, where the 'ith' city has an 'A[i]' population.
For better governance, the king wants to divide his kingdom into more and more sub-kingdoms with an even
population. Any two cities belong to the same sub-kingdom if connected via some sequence of paths.

The king wants to remove some of the paths from his kingdom to achieve maximum sub-kingdoms with an
even population.
You must return the maximum number of sub-kingdoms with an even population that can be obtained after
removing some of the paths from the kingdom.

input:
5
1 2 3 4 5
0 1
1 2 
2 3
3 4

output:
2

Remove paths (0,1) and (2,3) to obtain the following
The sub-kingdom with city 0 has a population of 1.
The sub-kingdom with city 1 has a population of 2.
The sub-kingdom with cities 2, 3, and 4  has a population of 12.

Hence we have two sub-kingdoms with an even population which is the maximum.

DFS

Approach:
If we add an even population sub-kingdom with an odd population sub-kingdom, we will have none of the sub-kingdom with an even population. 
If we add an even population sub-kingdom with an even population sub-kingdom, we will have only one subkingdom with an even population. 
Hence, disconnecting an even population sub-kingdom from any other cities is better.
Hence we will join cities only when we currently have an odd population sub-kingdom. 
Else we will form a new sub-kingdom leaving the previous one as a separate sub-kingdom with an even population.


code:
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the number of cities.
*/

int dfs(int currentCity, int parentCity, vector<int>&a, vector<int>adj[], int &answer) {

    // stores the current population of the sub-kingdom.
    int population = a[currentCity];

    // For all cities that are connected to 'currentCity'.
    for (auto city : adj[currentCity]) {

        if (city != parentCity) {

            // Add population of its child to the 'currentCity'.
            population += dfs(city, currentCity, a, adj, answer);
        }
    }

    /*
    If the total population in the sub-kingdom is even, there is no benefit
    in connecting it with other cities. So mark it a new sub-kingdom, increase 'answer'
    by one, and disconnect it from other cities by returning zero.
    */

    if (population % 2 == 0) {
        answer++;
        return 0;
    }

    // Else return the 'population' till now.
    else {
        return population;
    }
}

int evenKingdom(vector<int>&a, vector<vector<int>>&edges) {

    int n = a.size();

    // Create an adjacency list to represent the kingdom as a graph.
    vector<int>adj[n];

    // For each edge, create an undirected edge between 'city1' and 'city2'.
    for (int i = 0; i < n - 1; i++) {
        int city1, city2;
        city1 = edges[i][0];
        city2 = edges[i][1];
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    // 'answer' variable stores the count of even population sub-kingdoms.
    int answer = 0;

    // Calling dfs function with (initialNode, ParentNode, Array a, Adjacency List, answer)
    dfs(0, -1, a, adj, answer);

    // Return the count of even population sub-kingdoms, stored in 'answer'.
    return answer;
}










