Compute the probability that an HMM will emit a string given its hidden path.

*Input*: A string x emitted by an HMM (Σ, States, Transition, Emission) and a hidden path π.

*Output*: The conditional probability Pr(x|π) that x will be emitted given that the HMM follows the hidden path π.

*Input Format*. The first line of the input contains the outcome string x. The second line of the input is “--------” (a delimiter). The third line of the input is the list of symbols in the alphabet Σ (space-separated). The fourth line of the input is “--------” (a delimiter). The fifth line of the input contains the hidden path π. The sixth line of the input is “--------” (a delimiter). The seventh line of the input is the list of states States (space-separated). The eighth line of the input is “--------” (a delimiter). The remaining lines are the emission matrix Emission, depicted as a tab-delimited |States| by |Σ| matrix as shown in the sample dataset. You may assume that transitions from the initial state occur with equal probability.

*Output Format*. The conditional probability Pr(x|π) that x will be emitted given that the HMM follows the hidden path π. Your answer should be accurate up to at least 3 significant figures. For example, if the answer is 0.001234678 (three significant figures are shown in bold) then even an imprecise answer like 0.00123 will be accepted by the grader because it is within 0.00001 from the correct solution. 

*Constraints*. |x| = |π| = 50; |States| = 2; |Σ| = 3