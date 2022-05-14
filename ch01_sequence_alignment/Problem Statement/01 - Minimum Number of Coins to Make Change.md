Find the minimum number of coins needed to make change.

*Input*: An integer money and an integer array Coins = (coin1, ..., coind).

*Output*: The minimum number of coins with denominations Coins that changes money

Imagine that you bought a textbook for $69.24, which you paid for with $70 in cash. You are due 76 cents in change, and the cashier now must make a decision whether to give you a fistful of 76 1-cent coins or just four coins (25 + 25 + 25 + 1 = 76). Making change in this example is easy, but it casts light on a more general problem — how can a cashier make change using the fewest number of coins? Different currencies have different possible coin values, or denominations. In the US, the coin denominations are (1, 5, 10, 25, 50 100); in the Roman Republic before Julius Caesar’s assassination, they were (1, 4, 5, 10, 24, 30, 40, 120).

*Input Format*. The first line of the input contains the positive integer money. The second line contains a comma-delimited list of positive integers Coins.

*Output Format*. The minimum number of coins with denominations Coins that changes money.


*Constraints*. money ≤ 20,000; |Coins| ≤ 7, 1 ≤ |coini| ≤ 100 for all i.