  //sliding window approach  
  int maxScore(vector<int>& a, int k) {
        int n = a.size(), sum = 0;
        for(int i=0; i<k; i++)
            sum += a[i];
		int curr = sum;
        int j = n-1, i = k-1;
        while(i>=0){
			curr = curr - a[i] + a[j];
            sum = max(sum, curr);
            i--, j--;
        }
        return sum;
    }
