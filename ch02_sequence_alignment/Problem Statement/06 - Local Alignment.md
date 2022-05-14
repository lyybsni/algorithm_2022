Find a highest-scoring local alignment between two strings using a scoring matrix.

*Input*: A match score m, a mismatch penalty μ, a gap penalty σ, and two DNA strings s and t.

*Output*: The maximum alignment score of a local alignment between s and t followed by a local alignment achieving this maximum score.

    You are a Bioinformatician and you have obtained two gene sequences, s and t. You want to line up the nucleotides of the two sequences to find positions at which the two sequences are similar. However, these genes are so distant that the majority of the positions will be different. Nevertheless, conserved substrings between the two may be responsible for  similar biological function. The score of an alignment is defined as the sum of the scores of each position of the alignment of the found substrings, the score of a match is +m, the score of a mismatch is -μ, and the score of a gap is -σ. A local alignment is simply an alignment between any substring of s and any substring of t, and you wish to find the highest-scoring local alignment.

*Input Format*. The first line of the input contains m followed by μ followed by σ (separated by spaces), the second line of the input contains a DNA string s, and the third line of the input contains a DNA string t.

*Output Format*. The first line of the output should contain the score of an optimal local alignment between s and t, and the next two lines should contain a local alignment between substrings of s and t achieving this maximum score. Specifically, the second line should contain s with gaps placed appropriately, and the third line should contain t with gaps placed appropriately.

*Constraints*. |s| ≤ 1,000; |t| ≤ 1,000