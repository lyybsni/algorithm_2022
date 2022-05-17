Find an optimal hidden path in an HMM given a string of its emitted symbols.

*Input*: A string x emitted by an HMM (Σ, States, Transition, Emission).

*Output*: A path π that maximizes the probability Pr(x, π) over all possible paths through this HMM. Please be as close to the book as possible.

*Input Format*. The first line of the input contains the outcome string x. The second line of the input is “--------” (a delimiter). The third line of the input is the list of symbols in the alphabet Σ (space-separated). The fourth line of the input is “--------” (a delimiter). The fifth line of the input is the list of states States (space-separated). The sixth line of the input is “--------” (a delimiter). The next |States|+1 lines are the transition matrix Transition, depicted as a tab-delimited |States| by |States| matrix as shown in the sample dataset. The next line is “--------” (a delimiter). The remaining lines are the emission matrix Emission, depicted as a tab-delimited |States| by |Σ| matrix as shown in the sample dataset. You may assume that transitions from the initial state occur with equal probability.

*Output Format*. A path π that maximizes the probability Pr(x, π) over all possible paths through this HMM. Each probability should be written to at least 3 decimal places. (Note: more than one solution may exist, in which case you may output any one.)


*Constraints*. |x| = |π| = 100; 2 ≤ |States| ≤ 4; |Σ| = 3