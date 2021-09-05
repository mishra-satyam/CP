const int N = 1e5;
bool prime[N+1];
// vi prime_list;

void SieveOfEratosthenes(int n)
{
	memset(prime, true, sizeof(prime));
	int p = 2;
	for ( ; p*p<=n; p++)
	{
		if (prime[p] == true)
		{
			// prime_list.pb(p);
			for (int i=p*p; i<=n; i += p)
				prime[i] = false;
		}
	}
	// for (;p<=n;p++){
	// 	if(prime[p]) prime_list.pb(p);
	// }
}

// O( n*log(log(n)) )

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
                int x = j;
                while (x%i==0) {
                    fac[j].pb(i);
                    x/=i;
                }
			}
		}
		primes[i]^=1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
// can be changed for all prime factors of a number
// O(nlogn)
