Find an alignment of three strings.

*Input*: Strings r, s, and t.

*Output*: The maximum score of a multiple alignment of these three strings, followed by a multiple alignment of the three strings achieving this maximum using a scoring function in which the score of an alignment column is 1 if all three symbols are identical and 0 otherwise.

    You are a Bioinformatician and you have obtained three DNA sequences. You want to line up the amino acids of the three sequences to find positions at which they are similar.  The score of an alignment is defined as the sum of the scores of each position of the alignment, where the score of a position i is 1 if all 3 characters match, otherwise 0.

*Input Format*. The first line of the input contains a string r, the second line of the input contains a string s, and the third line of the input contains a string t.

*Output Format*. The first line of the output should contain the maximum score of an alignment between the three input strings, and the next three lines should contain an alignment achieving this maximum score. Specifically, the second line should contain r with gaps placed appropriately, the third line should contain s with gaps placed appropriately, and the fourth line should contain t with gaps placed appropriately.


*Constraints*. |r| ≤ 10; |s| ≤ 10; |t| ≤ 10