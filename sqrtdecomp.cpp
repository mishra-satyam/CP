
const int N = 1e5;
// const int Q = 1e5;

#define B 300

struct query{
	int i, l, r;
};
query q[N];
int cur_ans;
int ans[N];
int a[N];

bool comp(query q1 , query q2)
{
	return ((q1.l/B < q2.l/B) || (q1.l/B == q2.l/B and q1.r < q2.r));
}

void add(int pos)
{

}

void remove(int pos)
{

}

int main()
{
	int n , qn;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];

	cin>>qn;
	for(int i=0;i<qn;i++){
		cin>>q[i].l>>q[i].r;
		q[i].i = i , q[i].l-- , q[i].r--;
	}

	sort(q , q+qn , comp);

	int L = 0 , R = -1;
	for(int i=0;i<qn;i++)
	{
		while(R < q[i].r) add(++R);
		while(L > q[i].l) add(--L);
		while(R > q[i].r) remove(R--);
		while(L < q[i].l) remove(L++);

		ans[q[i].i] = cur_ans;
	}

	for(int i=0;i<qn;i++)
	cout<<ans[i]<<'\n';

}

// O( B*Q + N*N/B )  *  time taken to do add/remove
// so in general case B = (n/sqrt(Q))

/*____________________________________________________________________________________*/

struct update{
	int i, new, prev;
};
update u[Q];
bool use[N];

int B;
// B = pow(n, 2.0/3.0);

// set "use of idx" to be true if this index is being used, else set it to false

void reflect_update(int x, int y){
	// set A[x] = y;
	if (!use[x]){
		A[x] = y;
		return;
	}
	remove(x);
	A[x] = y;
	add(x);
}

void do_update(int i){ reflect_update(u[i].i, u[i].new) };
void undo_update(int i){ reflect_update(u[i].i, u[i].prev) };

void cmp(query a,query b){
	return (a.l/B < b.l/B) || (a.l/B == b.l/B && a.r/B < b.r/B)
	|| (a.l/B == b.l/B && a.r/B == b.r/B && a.t < b.t) ;
}

int T=-1, L=0, R=-1;
FOR(i,0,qn){
	while(T < q[i].t) do_update(++T);
	while(T < q[i].t) undo_update(T--);
}
