Find a highest-scoring global alignment between two strings (with affine gap penalties).

*Input*: A match score m, a mismatch penalty μ, a gap opening penalty σ, a gap extension penalty ε, and two DNA strings s and t.

*Output*: The maximum alignment score of an alignment between s and t (using affine gap penalties) followed by an alignment achieving this maximum score.

    A gap is a contiguous sequence of spaces in a row of an alignment. One way to score gaps more appropriately is to define an affine penalty for a gap of length k as σ + ε · (k − 1), where σ is the gap opening penalty, assessed to the first symbol in the gap, and ε is the gap extension penalty, assessed to each additional symbol in the gap. We typically select ε to be smaller than σ so that the affine penalty for a gap of length k is smaller than the penalty for k independent single-nucleotide indels (σ · k).

*Input Format*. The first line of the input contains m followed by μ followed by σ followed by ε (separated by spaces), the second line of the input contains a DNA string s, and the third line of the input contains a DNA string t.

*Output Format*. The first line of the output should contain the maximum score of an alignment between s and t using affine gap penalties, and the next two lines should contain an alignment achieving this maximum score. Specifically, the second line should contain s with gaps placed appropriately, and the third line should contain t with gaps placed appropriately.


*Constraints*. |s| ≤ 1,000; |t| ≤ 1,000