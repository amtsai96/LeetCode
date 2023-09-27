// time: O(n), space: O(1)
int maxProfit(int* prices, int pricesSize){
    int profit = 0, i, check_idx = 0, buy_idx = -1;
    
    for(i = 1; i < pricesSize; i++)
    {
        if (buy_idx != -1) // currently hold
        {
            if (prices[i] >= prices[check_idx])
            {
                check_idx = i;
            }
            else
            {
                // sell
                profit += prices[check_idx] - prices[buy_idx];
                check_idx = i;
                buy_idx = -1;
            }
        }
        else
        {
            if (prices[i] < prices[check_idx])
            {
                check_idx = i;
            }
            else
            {
                // buy
                buy_idx = check_idx;
                check_idx = i;
            }
        }
    }
    
    if (buy_idx != -1) // currently hold
    {
        // sell
        profit += prices[pricesSize-1] - prices[buy_idx];
    }
    
    return profit;
}

// time: O(n), space: O(1)
int maxProfit(int* prices, int pricesSize){
    int profit = 0, i;
    
    for(i = 1; i < pricesSize; i++)
    {
        if (prices[i] > prices[i-1])
        {
            profit += prices[i] - prices[i-1];
        }
    }

    return profit;
}