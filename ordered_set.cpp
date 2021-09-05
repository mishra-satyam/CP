#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds;

// order_of_key (number of items that are strictly smaller(come before) than given value)
// (a.order_of_key(int_arg))

// find_by_order (kth element in 0 base indexing) (a.find_by_order(int_arg))

// for multiset use:
//      t = 0
//      a.insert({x, t++});
//      int_arg => ({x, 0})
