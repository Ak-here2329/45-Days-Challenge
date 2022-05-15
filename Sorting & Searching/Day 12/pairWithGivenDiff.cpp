bool findPair(int arr[], int size, int n){
    //code
    sort(arr ,arr+size);
    for(int i=0; i<size; i++){
        int target = abs(n - arr[i]);
        int s = 0, e = size - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[mid] == target and mid != i)
                return true;
            else if (arr[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return false;
}
