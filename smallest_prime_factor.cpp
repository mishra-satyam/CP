const int MAXN = 1e5;

int spf[MAXN];

void sieve()
{
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)

		spf[i] = i;

	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++)
	{
		if (spf[i] == i)
		{
			for (int j=i*i; j<MAXN; j+=i)

				if (spf[j]==j)
					spf[j] = i;
		}
	}
}
// including both 1 and that number itself
int factor_count(int n)
{
    if (n == 1)
        return 1;

    int ans = 1;

    int dup = factor[n];

    int c = 1;

    int j = n / factor[n];

    while (j != 1) {
        if (factor[j] == dup)
            c += 1;

        else {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }

        j = j / factor[j];
    }

    ans = ans * (c + 1);

    return ans;
}

// sieve => O( n* log(log(n)) )
// factor_count => O( logn )

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

// including 1 excluding that number itself
int factor_count[N];
for (int i = 1; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
        factor_count[j]++;
    }
}


// O( n*log(n) )

// the same code can even be used to iterate over all
// multiples of i in logn time
// so total time taken is NlogN
int N = 3e5+1;
for (int i = 1; i < N; i++) {
	for (int j = i; j < N; j += i) {
		int x = i, y = j/i;
	}
}
