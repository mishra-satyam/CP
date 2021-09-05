ll b1s = 0;
ll b2s = accumulate(b2.begin(),b2.end(),0ll);
// cout << "b2s = " << b2s << "\n";
int i = 0,j=b2.size()-1;
int ans = INT_MAX;
while(i <= b1.size() && j>=-1){
    if (b1s + b2s < m){
        if (i < b1.size()){
            b1s += b1[i];
            i++;
        }
        else
            break;
    }
    if ( b1s + b2s >= m){
        ans = min(ans,(i+2*(j+1)));
        // cout << "ans is " << ans << "\n";
        if (j >=0){
            b2s -= b2[j];
            j--;
        }
        else
            break;
    }
}

cout << ( (ans == INT_MAX) ? -1 : ans ) << "\n";
