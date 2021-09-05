// maxn in sum of all chars in input

const int MAXN = 1e5;
int N = 0;
bool is_terminal[MAXN];
map<char, int> nxt[MAXN];

// initialisation
// n = total length of input(all chars)
N = 0;
FOR(i,0,n){
    is_terminal[i] = 0;
    nxt[i].clear();
}

// here 0 is nothing
for (auto &s : words){
    int node = 0;
    for (auto &c : s){
        if (nxt[node][c] == 0){
            nxt[node][c] = ++N;
        }
        node = nxt[node][c];
    }
    is_terminal[node] = 1;
}

/*
IMPORTANT POINTS

// NUMBER OF NODES = O(TOTAL LENGTH OF INPUT)
// it will be even bounded by (26)*(max length of a word)
// NUM OF TERMINAL NODES = O(TOTAL WORDS)
// TIME FOR CREATING TREE = O(TOTAL LENGTH OF INPUT)

*/
