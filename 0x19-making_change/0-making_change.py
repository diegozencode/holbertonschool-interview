""""
Making change - Change comes from within
""""


def makeChange(coins, total):
    """
    :param coins: list of coins
    :param total: total amount
    """
    if total == 0:
        return 0
    if total < 0:
        return float('inf')
    if len(coins) == 0:
        return float('inf')
    return min(makeChange(coins, total - coins[i]) + 1 for i in range(len(coins)))
