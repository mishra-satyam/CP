mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int myrand(int b) {
    return rng() % (b);
}

random_shuffle(all((a)), myrand);
