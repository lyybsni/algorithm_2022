Find a middle edge in the alignment graph in linear space.

*Input*: A match score m, a mismatch penalty μ, a gap penalty σ, and two DNA strings s and t.

*Output*: The maximum alignment score of s and t followed by an alignment achieving this maximum score.

    The quadratic memory required to store the entire alignment matrix can become overly massive for long DNA strings. However, keep in mind that, during the alignment algorithm, we only need two rows (i.e., linear space) at any given time in order to compute the optimal score. It turns out that we can exploit this phenomenon to compute the entire optimal alignment in linear space as well.

    Given strings s1 … sn and and t1 … tm, define middle = ⌊m/2⌋. The middle column of the alignment graph of s and t is the column containing all nodes (i, middle) for 0 ≤ i ≤ n. A longest path from source to sink in the alignment graph must cross the middle column somewhere, and we refer to the node on a longest path belonging to the middle column as a middle node, and we refer to the edge in an optimal path starting at a given middle node as a middle edge.


*Input Format*. The first line of the input contains m followed by μ followed by σ (separated by spaces), the second line of the input contains a DNA string s, and the third line of the input contains a DNA string t.

*Output Format*. The middle edge in the form (i,j) (k,l), where (i,j) and (k, l) are adjacent nodes in the alignment graph, i.e., there is an edge between these nodes.  


*Constraints*. |s| ≤ 1,000; |t| ≤ 1,000.