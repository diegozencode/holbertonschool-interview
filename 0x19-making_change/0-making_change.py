"""
Making change - Change comes from within
"""


def makeChange(coins, total):
    """
    :param coins: list of coins
    :param total: total amount
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        count += total // coin
        total = total % coin
    if total:
        return -1
    return count
