Find a highest-scoring overlap alignment between two strings.

*Input*: A match score m, a mismatch penalty μ, a gap penalty σ, and two DNA strings s and t.

*Output*: The maximum alignment score of an overlap alignment between s and t followed by an overlap alignment achieving this maximum score.

    Biologists use overlapping reads to assemble a genome, a problem that is complicated by errors in reads. To find overlaps between error-prone reads, we define an overlap alignment of strings s = s1 ... sn and t = t1 ... tm as a global alignment of a suffix of s with a prefix of t. An optimal overlap alignment of strings s and t maximizes the global alignment score between an i-suffix of s and a j-prefix of t (i.e., between si ... sn and t1 ... tj) among all i and j.

*Input Format*. The first line of the input contains m followed by μ followed by σ (separated by spaces), the second line of the input contains a DNA string s, and the third line of the input contains a DNA string t.

*Output Format*. The first line of the output should contain the maximum score of an overlap alignment between s and t, and the next two lines should contain an overlap alignment between a suffix of s and a prefix of t achieving this maximum score. Specifically, the second line should contain a suffix of s with gaps placed appropriately, and the third line should contain a prefix of t with gaps placed appropriately.


*Constraints*. |s| ≤ 1,000; |t| ≤ 1,000