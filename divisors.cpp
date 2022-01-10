vi divs1, divs2;
void printDivisors(int n)
{
    divs1.clear();
    divs2.clear();
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
            divs1.pb(i);

            else {
                divs1.pb(i);
                divs2.pb(n/i);
            }
        }
    }
    reverse(all(divs2));
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
