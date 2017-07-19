In graph theory, a bi=connected component (also known as a <b>block or 2-connected component</b>) is a maximal bi-connected subgraph. Any connected graph decomposes into a tree of bi-connected components called the<b> block-cut tree</b> of the graph. The blocks are attached to each other at shared vertices called <b>cut vertices or articulation points</b>. Specifically,</b> a cut vertex is any vertex whose removal increases the number of connected components.</b>

The classic sequential algorithm for computing bi-connected components in a connected undirected graph is due to <b> John Hopcroft and Robert Tarjan (1973).</b> It runs in <strong>linear time</strong>, and is based on <b> depth-first search.</b>

<strong>The idea is to run a depth-first search while maintaining the following information:</strong>

<i>The depth of each vertex in the depth-first-search tree (once it gets visited), and for each vertex v, the lowest depth of neighbors of all descendants of v (including v itself) in the depth-first-search tree, called the low-point. The depth is standard to maintain during a depth-first search. The low-point of v can be computed after visiting all descendants of v (i.e., just before v gets popped off the depth-first-search stack) as the minimum of the depth of v, the depth of all neighbors of v (other than the parent of v in the depth-first-search tree) and the low-point of all children of v in the depth-first-search tree. The key fact is that a non-root vertex v is a cut vertex (or articulation point) separating two bi-connected components if and only if there is a child y of v such that low-point(y) ≥ depth(v). This property can be tested once the depth-first search returned from every child of v (i.e., just before v gets popped off the depth-first-search stack), and if true, v separates the graph into different bi-connected components. This can be represented by computing one bi-connected component out of every such y (a component which contains y will contain the subtree of y, plus v), and then erasing the subtree of y from the tree. The root vertex must be handled separately: it is a cut vertex if and only if it has at least two children. Thus, it suffices to simply build one component out of each child subtree of the root (including the root). </i>

<b>Pseudo code: </b>

		GetArticulationPoints(i, d)
   			visited[i] = true
    		depth[i] = d
    		low[i] = d
    		childCount = 0
    		isArticulation = false
    		for each ni in adj[i]
        		if not visited[ni]
            		parent[ni] = i
            		GetArticulationPoints(ni, d + 1)
            		childCount = childCount + 1
           			if low[ni] >= depth[i]
               		 	isArticulation = true
            		low[i] = Min(low[i], low[ni])
        		else if ni <> parent[i]
            		low[i] = Min(low[i], depth[ni])
			if (parent[i] <> null and isArticulation) or (parent[i] == null and childCount > 1)
        			Output i as articulation point
