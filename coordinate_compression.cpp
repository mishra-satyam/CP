sort(all(points));
uniq(points);

debug(points);
map<int, int> idx;
FOR(i,0,sz(points)) idx[points[i]] = i;
