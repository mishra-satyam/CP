// the modulous in which we are working 
const int mod = 998244353;
// primitive root of mod
// calculate if mod is differenet
const int root = 3;
// inverse of root in mod
const int root_1 = 332748118;
// max power of two in mod
const int root_pw = 1 << 23;

int power(int x, int y){
	int res = 1;     // Initialize result
	while (y){
		// If y is odd, multiply x with result
		if (y & 1)
			res = res * 1ll * x % mod;

		// y must be even now
		y = y>>1; // y = y/2
		x = x * 1ll * x % mod;  // Change x to x^2
	}
	return res;
}

int inverse(int n, int mod) {
	return power(n, mod-2);
}

void fft(vector<int> & a, bool invert) {
	int n = a.size();

	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for (; j & bit; bit >>= 1)
			j ^= bit;
		j ^= bit;

		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		int wlen = invert ? root_1 : root;
		wlen = power(wlen, (mod-1)/len);

		for (int i = 0; i < n; i += len) {
			int w = 1;
			for (int j = 0; j < len / 2; j++) {
				int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
				a[i+j] = u + v < mod ? u + v : u + v - mod;
				a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
				w = (int)(1LL * w * wlen % mod);
			}
		}
	}

	if (invert) {
		int n_1 = inverse(n, mod);
		for (int & x : a)
			x = (int)(1LL * x * n_1 % mod);
	}
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
	vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < a.size() + b.size()) 
		n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; i++)
		fa[i] = fa[i] * 1ll * fb[i] % mod;
	fft(fa, true);

	vector<int> result(n);
	for (int i = 0; i < n; i++)
		result[i] = (fa[i]);
	return result;
}

// NOTES:
// (i) one point to remember is that n after resizing must divide (p-1)