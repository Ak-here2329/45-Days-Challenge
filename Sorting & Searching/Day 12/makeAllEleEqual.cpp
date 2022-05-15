int compute(vector<int> &a, int n, int x){
	int ans = 0;
	for(int i=0; i<n; i++)
		ans += abs(a[i] - x);
	return ans;
}

int minCost(vector<int> a, int n){
	int low = *min_element(a.begin(), a.end()), high = *max_element(a.begin(), a.end());
	while((low - high) > 2){
		int mid1 = low + (high - low) / 3, mid2 = high - (high - low) / 3;
		int cost1 = compute(a, n, mid1), cost2 = compute(a, n ,mid2);
		if(cost1 < cost2)
			high = mid2;
		else
			low = mid1;
	}
	return compute(a, n , (low + high) / 2);
}
