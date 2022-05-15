void countSort(vector<int> &a, int power){
	map<int, vector<int>> m;
	for(int i=0; i<a.size(); i++){
		int curr = (a[i] % power - a[i] % (power / 10)) / 10;
		m[curr].push_back(a[i]);
	}
	int i = 0;
	for(auto e : m){
		int s = e.second.size();
		for(int j=0; j<s; j++){
			a[i] = e.second[j];
			i++;
		}
	}
	debug(a)
}

void radiaxSort(vector<int> &a){
	int n = a.size();
	int high = *max_element(a.begin(), a.end()), power = 10;
	while(high){
		countSort(a, power);
		high /= 10;
		power *= 10;
	}
}
