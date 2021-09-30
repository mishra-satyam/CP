const int N = 1e5+10;

int z[N];

void z_function(string& s) {
    int n = (int) s.length();
    for(int i = 0; i < n; i++) z[i] = 0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

// time complexity is O(N)

// this gives longest suffix that also a proper prefix
// that starts at this point (and this cant go beyond the end character)

/*
// Pattern Matching
1.  Pattern + "extra character" + Text
    if at some point z[i] = len(Patter), then Pattern found
2.
*/
