//recursive and backtracking soln
void helper(vector<int> &a, int n, int i, int idx, int r, vector<int> &curr, vector<vector<int>> &ans){
	if(idx == r){
		ans.push_back(curr);
		return;
	}	

	if(i >= n)
		return;
	
	curr.push_back(a[i]);
	helper(a, n, i+1, idx + 1, r, curr, ans); 	
	while(a[i] == a[i+1])
		i++;
	curr.pop_back();
	helper(a, n, i+1, idx, r, curr, ans);

}

vector<vector<int>> printCombinations(vector<int> &a, int n, int r){
	vector<int> curr;
	vector<vector<int>> ans;
	sort(all(a));
	helper(a, n, 0, 0, r, curr, ans);
	return ans;
}

void solve(int t){
	int n, r;
	cin >> n >> r;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	vector<vector<int>> ans = printCombinations(a, n, r);
	debug(ans)
}


int main() {

	fastio();
	int t;
	cin >> t;
	int T = 0;
	while(T++<t)
		solve(T);
	return 0;
}
