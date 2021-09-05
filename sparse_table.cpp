const int N = 1e5;
const int LOG = 17;

int table[N][LOG];

int lg(int x){
    int k = log2(x);
    while(1<<k < x) k++;
    while(1<<k > x) k--;
    return k;
}
void make_table(int n){
    int LOG1 = lg(n)+1;
    for (int i=0;i<n;i++){
        table[i][0] = /*given thing*/;
    }

    for (int j = 1; j<LOG1; j++){
        for (int i=0; i + (1<<j) -1 < n; i++){
            table[i][j] = /*operator*/(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r){
    int power = lg(r-l+1);
    return (/*operator*/(table[l][power], table[r-(1<<power)+1][power]));
}

const int N = 1e5;
const int LOG = 17;
struct sparse {

    int table[N][LOG];

    int lg(int x){
        int k = log2(x);
        while(1<<k < x) k++;
        while(1<<k > x) k--;
        return k;
    }
    template<typename T>
    void make_table(const T &arr, int n){
        int LOG1 = lg(n)+1;
        for (int i=0;i<n;i++){
            table[i][0] = arr[i];
        }

        for (int j = 1; j<LOG1; j++){
            for (int i=0; i + (1<<j) -1 < n; i++){
                table[i][j] = /*operator*/(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    int query(int l, int r){
        int power = lg(r-l+1);
        return (/*operator*/(table[l][power], table[r-(1<<power)+1][power]));
    }
};

/*
IMPORTANT POINTS TO REMEMBER
1.  works in case when overlap dosent matter

*/

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e3;
const int LOG = 10;

int a[N][N];
int table[N][N][LOG][LOG];

int lg(int x){
    int k = log2(x);
    while(1<<k < x) k++;
    while(1<<k > x) k--;
    return k;
}

void make_table(int n, int m){
    int LOG1 = lg(n)+1;
    int LOG2 = lg(m)+1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) table[i][j][0][0] = /*given thing*/;
    }

    for (int j=0;j<m;j++){
        for (int l1 = 1; l1<LOG1; l1++){
            for (int i=0; i + (1<<l1) -1 < n; i++){
                table[i][j][l1][0] = /*operator*/(table[i][j][l1-1][0], table[i+(1<<(l1-1))][j][l1-1][0]);
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int l2 = 1; l2<LOG2; l2++){
            for (int j=0; j + (1<<l2) -1 < m; j++){
                table[i][j][0][l2] = /*operator*/(table[i][j][0][l2-1], table[i][j+(1<<(l2-1))][0][l2-1]);
            }
        }
    }

    for (int l1 = 1; l1<LOG1; l1++){
        for (int i=0; i + (1<<l1) -1 < n; i++){
            for (int l2 = 1; l2<LOG2; l2++){
                for (int j=0; j + (1<<l2) -1 < m; j++){
                    table[i][j][l1][l2] = /*operator*/(table[i][j][l1-1][l2-1], table[i+(1<<(l1-1))][j][l1-1][l2-1]
                                                        table[i][j+1<<(l2-1)][l1-1][l2-1], table[i+(1<<(l1-1))][j+1<<(l2-1)][l1-1][l2-1]);
                }
            }
        }
    }
}

int query(int l1,int l2, int r1, int r2){
    int power1 = lg(r1-l1+1);
    int power2 = lg(r2-l2+1);
    return (/*operator*/(table[l1][l2][power1][power2], table[r1-(1<<power1)+1][l2][power1][power2]
                        table[l1][r2-(1<<power2)+1][power1][power2], table[r1-(1<<power1)+1][r2-(1<<power2)+1][power1][power2]));
}
