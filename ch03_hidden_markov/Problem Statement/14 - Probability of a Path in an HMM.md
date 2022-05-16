Compute the probability of a hidden path in an HMM.

*Input*: A hidden path π in an HMM (Σ, States, Transition, Emission).

*Output*: The probability of this path, Pr(π).

*Input Format*. The first line of the input contains the path π in the HMM The second line of the input is “--------” (a delimiter). The third line of the input is the list of states States (space-separated). The fourth line of the input is “--------” (a delimiter). The remaining lines are the transition matrix Transition, depicted as a tab-delimited |States| by |States| matrix. You may assume that transitions from the initial state occur with equal probability.

*Output Format*. The probability of this path, Pr(π), to at least 3 significant figures.


*Constraints*. 50 ≤ |π| ≤ 100; |States| = 10