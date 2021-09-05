//iterative version
for(int mask = 0; mask < (1<<N); ++mask){
	dp[mask][-1] = A[mask];	//handle base case separately (leaf states)
	for(int i = 0;i < N; ++i){
		if(mask & (1<<i))
			dp[mask][i] = dp[mask][i-1] + dp[mask^(1<<i)][i-1];
		else
			dp[mask][i] = dp[mask][i-1];
	}
	F[mask] = dp[mask][N-1];
}



//memory optimized, super easy to code.
for(int i = 0; i<(1<<N); ++i)
	F[i] = A[i];
for(int i = 0;i < N; ++i) {
	for(int mask = 0; mask < (1<<N); ++mask){
		if(mask & (1<<i))
			F[mask] += F[mask^(1<<i)];
	}
}

// sum over superset
for(int i = 0;i < N; ++i) {
	for(int mask = (1<<N)-1; mask >= 0; --mask){
		if(!(mask & (1<<i)))
			F[mask] += F[mask^(1<<i)];
	}
}

/*
IMPORTANT POINTS
1.	We cant change the order of loop for second code as we dont have i
	subscript for the stored information. But we can in first code.
2.	Iterating over subset of a mask is same as iterating over superset of
	complement of that mask
	complement => ((1 << B) - 1) & (~x)
	B is bit size
3.	Here we can even use inclusion exclusion in certain questions.
	In inclusion exclusion princliple we can ignore -1 in (2^x - 1)
	ans it will result in no change.
	(sum of odd and even binomial coefficient are same)
	But this thing is not valid in general
	only valid for supersets of 0 or subsets of 1111....111
4.
*/
