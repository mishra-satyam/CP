struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};


mp.reserve(1<<18);
mp.max_load_factor(0.25);

// for vpii to do binary search wrt first value
bool comp(pli it, ll val){
    return it.fi < val;
}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct hash_pair {
    // template <class T1, class T2>
    size_t operator()(const pii& p) const
    {
        auto hash1 = custom_hash{}(p.first);
        auto hash2 = custom_hash{}(p.second);
        return hash1 ^ hash2;
    }
};
