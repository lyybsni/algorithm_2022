Find a highest-scoring fitting alignment between two strings.

*Input*: A match score m, a mismatch penalty μ, a gap penalty σ, and two DNA strings s and t.

*Output*: The maximum alignment score of a fitting alignment between s and t followed by a fitting alignment achieving this maximum score.

    We wish to compare the approximately 60,000 nucleotide-long antibiotics-producing gene (NRP synthetase) from Bacillus brevis with the approximately 1,800 nucleotide-long segment of an antibiotics-producing gene (A-domain) from Streptomyces roseosporus, the bacterium that produces the powerful antibiotic daptomycin. We hope to find a region within the longer sequence s that has high similarity with ALL of the shorter sequence t. Global alignment will not work because it tries to align all of s to all of t; local alignment will not work because it tries to align substrings of both s and t. Thus, we have a distinct application called the Fitting Alignment Problem. “Fitting” t to s requires finding a substring s’ of s that maximizes the global alignment score between s’ and t among all substrings of s.

*Input Format*. The first line of the input contains m followed by μ followed by σ (separated by spaces), the second line of the input contains a string s, and the third line of the input contains a string t.

*Output Format*. The first line of the output should contain the score of an optimal fitting alignment between s and t, and the next two lines should contain a fitting alignment achieving this maximum score. Specifically, the second line should contain a substring of s with gaps placed appropriately, and the third line should contain t with gaps placed appropriately.
S

*Constraints*. |t| ≤ 100; |t| ≤ |s| ≤ 1,000