Find the probability that an HMM emits a given string.

*Input*: A string x emitted by an HMM (Σ, States, Transition, Emission).

*Output*: The probability Pr(x) that the HMM emits x.

*Input Format*. The first line of the input contains the outcome string x. The second line of the input is “--------” (a delimiter). The third line of the input is the list of symbols in the alphabet Σ (space-separated). The fourth line of the input is “--------” (a delimiter). The fifth line of the input is the list of states States (space-separated). The sixth line of the input is “--------” (a delimiter). The next |States|+1 lines are the transition matrix Transition, depicted as a tab-delimited |States| by |States| matrix as shown in the sample dataset. The next line is “--------” (a delimiter). The remaining lines are the emission matrix Emission, depicted as a tab-delimited |States| by |Σ| matrix as shown in the sample dataset. You may assume that transitions from the initial state occur with equal probability. 

*Output Format*. The probability Pr(x) that the HMM emits x to at least 3 significant figures.


*Constraints*. |x| = |π| = 100; 2 ≤ |States| ≤ 4; |Σ| = 3