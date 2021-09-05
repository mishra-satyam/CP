void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i*i <= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

// if it is a prime then O(sqrt(n))
// O( log(n) )

//////////////////////////////////////////////////////////////////////////////////////////
int primes[N];
vector<int> pr;
vector<int> fac[N];
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			for(int j=i;j<N;j+=i){
				primes[j]=1;
				fac[j].pb(i);
			}
		}
		primes[i]^=1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
// O(nlog(logn))
// only single occurance of all prime numbers

// prime test
ll sq(ll x){
    ll k = sqrtl(x);
    while(k*k < x) k++;
    while(k*k > x) k--;
    return k;
}

bool isprime(ll x) {
    FOR(i,2,sq(x)+1) {
        if (x%i == 0) return 0;
    }
    return 1;
}
