// Source : https://oj.leetcode.com/problems/clone-graph/
// Author : zheng yi xiong 
// Date   : 2014-12-06

/********************************************************************************** 
* 
* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


* OJ's undirected graph serialization:
* Nodes are labeled uniquely.

* We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
* As an example, consider the serialized graph {0,1,2#1,2#2,2}.

* The graph has a total of three nodes, and therefore contains three parts as separated by #.

* First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
* Second node is labeled as 1. Connect node 1 to node 2.
* Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
* Visually, the graph looks like the following:

*    1
*   / \
*  /   \
* 0 --- 2
*      / \
*      \_/
*               
**********************************************************************************/

#include "stdafx.h"
#include <map>
#include <stack>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class CClone_Graph {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node)
		{
			return NULL;
		}

		stack<UndirectedGraphNode *> stack_unSearchNode;
		map<int, UndirectedGraphNode *> map_undirectedGraph;
		UndirectedGraphNode *pRoot = new UndirectedGraphNode(node->label);
		map_undirectedGraph.insert(map<int, UndirectedGraphNode *>::value_type(node->label, pRoot));
		stack_unSearchNode.push(node);
		UndirectedGraphNode *pOld = NULL, *pNew = NULL, *pTemp = NULL;
		while(!stack_unSearchNode.empty())
		{
			pOld = stack_unSearchNode.top();
			stack_unSearchNode.pop();
			if (!pOld->neighbors.empty())
			{
				pNew = map_undirectedGraph[pOld->label];
				for (int i = 0; i < pOld->neighbors.size(); ++i)
				{
					if (map_undirectedGraph.end() != map_undirectedGraph.find(pOld->neighbors[i]->label))
					{
						pNew->neighbors.push_back(map_undirectedGraph[pOld->neighbors[i]->label]);
					}
					else
					{
						pTemp = new UndirectedGraphNode(pOld->neighbors[i]->label);
						map_undirectedGraph.insert(map<int, UndirectedGraphNode *>::value_type(pOld->neighbors[i]->label, pTemp));
						stack_unSearchNode.push(pOld->neighbors[i]);
						pNew->neighbors.push_back(pTemp);
					}
				}
			}
		}

		return pRoot;
    }
};