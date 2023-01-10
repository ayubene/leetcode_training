int maxProfit(int* prices, int pricesSize) {
	int minprices = prices[0];
	int maxprices = 0;
	int profit;
	for (int i = 0; i < pricesSize; i++) {
		if (minprices > prices[i]) {
			minprices = prices[i];
		}
		profit = prices[i] - minprices;
		if (maxprices < profit) {
			maxprices = profit;
		}
	}
	return maxprices;
}