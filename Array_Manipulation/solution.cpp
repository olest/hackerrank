#include <iostream>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin >> n;
    cin >> m;
    using ll = long long;
    map<ll,ll> ops;
    while (m--) {
        ll start, end, val;
        cin >> start >> end >> val;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        ops[start] += val;
        ops[end+1] -= val;
    }

    ll max = 0, sum = 0;
    auto acc_max_val = [x=ll(0),&max](auto y) mutable{x+=y.second; if (x>max) max=x;};
    std::for_each(ops.begin(),ops.end(),acc_max_val);
    std::cout << max << "\n";
    /*for (auto o : ops)
    {
        sum += o.second;
        if (sum > result)
            result = sum;
    }
    cout << result << "\n";*/

    return 0;
}

