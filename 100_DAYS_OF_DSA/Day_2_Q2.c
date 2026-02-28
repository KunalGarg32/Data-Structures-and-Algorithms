int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize <= 1)
    {
        return 0; // Cannot buy and sell with 0 or 1 day
    }

    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        // Update minimum buy price if current day is cheaper
        if (prices[i] < min_price)
        {
            min_price = prices[i];
        }
        // Check if selling today gives a better profit
        else if (prices[i] - min_price > max_profit)
        {
            max_profit = prices[i] - min_price;
        }
    }

    return max_profit;
}