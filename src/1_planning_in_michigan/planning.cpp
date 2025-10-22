#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "planning.h"


void printPath(std::vector<int>& path, Graph& g) {

    if (path.size() < 1)
    {
        std::cout << "No path found :(\n";
        return;
    }

    std::cout << "Path: ";
    for (int i = 0; i < path.size() - 1; i++)
    {
        std::cout << g.data[path[i]] << " -> ";
    }
    std::cout <<  g.data[path.back()] << "\n";
};

std::vector<int> tracePath(int n, Graph& g) {
    std::vector<int> path;
    int curr = n;
    do {
        path.push_back(curr);
        curr = getParent(curr, g);
    } while (curr != -1);

    // Since we built the path backwards, we need to reverse it.
    std::reverse(path.begin(), path.end());
    return path;
};

std::vector<int> getNeighbors(int n, Graph& g)
{
    return g.edges[n];
}

std::vector<float> getEdgeCosts(int n, Graph& g)
{
    return g.edge_costs[n];
}

int getParent(int n, Graph& g)
{
    // *** Task: Implement this function *** //
    if(g.nodes[n].parent.empty())
    {
        return -1;    
    }
    return g.nodes[n].parent;
    // *** End student code *** //
}

void initGraph(Graph& g)
{
    g.nodes.clear();
    for (int i = 0; i < g.data.size(); i++)
    {
        Node n;
        n.city = g.data[i];
        g.nodes.push_back(n);
    }
}

std::vector<int> bfs(int start, int goal, Graph& g)
{
    initGraph(g);
    std::vector<int> path;

    std::queue<int> visit_queue;

    // *** Task: Implement this function *** //

    //Initialize
    for(int i = 0; i < g.nodes.size(); i++)
    {
        g.nodes[i].parent = NULL;
        g.nodes[i].cost = HIGH;
        g.nodes[i].visited = false;
    }

    g.nodes[start].parent = NULL;
    g.nodes[start].cost = 0;
    
    visit_queue.push(start);

    //Iterate
    while((visit_queue.empty() == false) && visit_queue.front() != goal)
    {
        
        std::vector <int> temp_neighbors = getNeighbors(visit_queue.front(), g)
        for(int i = 0; i < temp_neighbors.size(); i++)
        {
            if(!(g.nodes[temp_neighbors(i)].visited) && !(visit_queue.contains(temp_neighbors(i))))
            {
                visit_queue.push(temp_neighbors(i));
            }
        }


        g.nodes[visit_queue.front()].visited = true;
        visit_queue.pop();
    }


    









    // *** End student code *** //

    return path;
}

std::vector<int> dfs(int start, int goal, Graph& g)
{
    initGraph(g);
    std::vector<int> path;

    std::stack<int> visit_stack;

    // *** Task: Implement this function if completing the advanced extension *** //

    // *** End student code *** //

    return path;
}
