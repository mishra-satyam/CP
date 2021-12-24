int low = 0, high = N;
int ans = -1;
while (low <= high) {
    int mid = (low+high)/2;
    if (check(mid)) ans = mid, low = mid+1;
    else high = mid - 1;
}