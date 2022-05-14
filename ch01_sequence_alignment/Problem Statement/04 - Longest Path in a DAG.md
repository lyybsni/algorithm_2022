Find a longest path between two nodes in an edge-weighted DAG.

*Input*: An edge-weighted graph, a source node source, and a sink node sink.

*Output*: The length of the longest path from source to sink, followed by a longest path.

A Directed Acyclic Graph (DAG) is a graph that does not contain any directed cycles. The length of a path in an edge-weighted graph is given by the sum of its edge weights. Given nodes source and sink, our goal is to find a longest path from source to sink. We assume that all nodes of the graph have integer labels and ordering the nodes in ascending represents a topological order, i.e., all edges of the graph connect a node with smaller label to a node with a larger label.  

*Input Format*. The first line of the input contains an integer representing source that has the smallest label. The second line of the input contains an integer representing sink that has the largest label. Each of the remaining lines represents an edge in the graph G(V,E) with node-set V and edge-set E, where each line is in the format u->v:w denoting an edge from node u to node v with weight w.

*Output Format*. The first line of the output should contain a number representing the length of the longest path from source to sink. The second line of the output should be a longest path in the format source->a->b->c->...->sink, where each of the items delimited by -> is a node in G. (If multiple longest paths exist, you may return any one.)


*Constraints*. |V| ≤ 50; |E| ≤ 100