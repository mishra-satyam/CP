void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
            printf("%d ", i);

            else // Otherwise print both
            printf("%d %d ", i, n/i);
        }
    }
}

// including 1 and that number itself

// vi v[2001];
// void divisors()
// {
//     FOR(n,1,2001){
//     	for (int i = 1; i <= sq(n); i++) {
//     		if (n % i == 0) {
//
//     			if (n / i == i)
//     				v[n].pb(i);
//     			else {
//     				v[n].pb(i);
//
//     				v[n].pb(n / i);
//     			}
//     		}
//     	}
//     }
// 	return;
// }

// O( n^(1/2) )
