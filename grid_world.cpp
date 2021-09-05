int n, m;

bool isvalid(int x, int y){
    if (x < 0 || y < 0 || x >= n || y >= m)
        return 0;

    if (BLOCKED)
        return 0;
    return 1;
}

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

const int N=2e3+5;

bool visited[N][N];
ll dist[N][N];

void bfs(){
    queue<int> qx,qy;
    // to see the left points
    FOR(i,0,n){
        FOR(j,0,m){
            dist[i][j] = 1e18;
            visited[i][j] = 0;
        }
    }

    //for multisource bfs
    // add rest sources here
    qx.push(0);
    qy.push(0);
    dist[0][0] = 0;
    visited[0][0] = true;

    while(!qx.empty()){
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();

        FOR(i,0,4){
            if ( !isvalid(x+dx[i], y+dy[i]) ) continue;
            if (!visited[x+dx[i]][y+dy[i]]){
                visited[x+dx[i]][y+dy[i]] = true;
                qx.push(x+dx[i]); qy.push(y+dy[i]);
                dist[x+dx[i]][y+dy[i]] = dist[x][y] + EDGE_WEIGHT;
            }
        }
    }
}

// print the grid
FOR(i,0,n){
    FOR(j,0,m)
        if (distnm[i][j] == 1e18)
            cout << "x ";
        else
            cout << distnm[i][j] << " ";
    cout << "\n";
}


// visualiser
vector<string> s(100);
int n, m;
cin >> n >> m;
FOR(i,0,n) cin >> s[i];

FOR(i,0,n){
    FOR(j,0,m) (s[i][j] == '.') ? (cout << ".\t") : (cout << m*i+j << "\t") ;
    cout << "\n";
}

/*
// IMPORTANT POINTS
1.  Grid ques wastes a lot of time so better to have all kind of code
    saved here
2.  
*/
