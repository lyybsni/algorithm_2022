Find a highest-scoring alignment between two strings using only linear space.

*Input*: A match score m, a mismatch penalty μ, a gap penalty σ, and two DNA strings s and t.

*Output*: The maximum alignment score of s and t followed by an alignment achieving this maximum score.

    You are a Bioinformatician and you you want to compare two very long genes of length n on your fast laptop that however has small memory, e.g., 10*n. The score of an alignment is defined as the sum of the scores of each position of the alignment, the score of a match is +m, the score of a mismatch is -μ, and the score of a gap is -σ. You have already implemented the global alignment problem using the quadratic O(n2) memory, Now, you have to do it in O(n) memory,

*Input Format*. The first line of the input contains m followed by μ followed by σ (separated by spaces), the second line of the input contains a string s, and the third line of the input contains a string t.

*Output Format*. The first line of the output should contain the maximum score of an alignment between s and t, and the next two lines should contain an alignment achieving this maximum score. Specifically, the second line should contain s with gaps placed appropriately, and the third line should contain t with gaps placed appropriately.


*Constraints*. |s| ≤ 10,000; |t| ≤ 10,000