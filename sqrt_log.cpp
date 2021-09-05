int sq(int x){
    int k = sqrt(x);
    while(k*k < x) k++;
    while(k*k > x) k--;
    return k;
}

int lg(int x){
    int k = log2(x);
    while(1<<k < x) k++;
    while(1<<k > x) k--;
    return k;
}
