const int N = 1e5+10;

int lps[N];

// Fills lps[] for given patttern s[0..M-1]
void computeLPSArray(string& s)
{
    // length of the previous longest prefix suffix
    int len = 0;
    int M = sz(s);
    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (s[i] != s[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// this gives longest suffix that also a proper prefix
// that ends at this point

// TC is O(N)

/*
// Pattern Matching
1.  Pattern + "extra character" + Text
    if at some point lps[i] = len(Patter), then Pattern found
2.
*/
