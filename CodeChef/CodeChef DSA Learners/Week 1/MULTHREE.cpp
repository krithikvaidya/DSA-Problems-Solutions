#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long int d0, d1, digits_used;
        long long k;

        cin >> k >> d0 >> d1;

        long long curr_sum = 0ll;
        digits_used = 2ll;

        curr_sum += d0 + d1;
        bool flag = false;

        while ( digits_used < k && ((digits_used == 2ll) || (curr_sum % 10ll != 8ll )))
        {
            curr_sum += (curr_sum % 10ll);
            digits_used++;
            if (curr_sum % 10ll == 0ll)
            {
                flag = true;
                break;
            }
        }

        if (digits_used == k || flag)
        {
            if (curr_sum % 3ll == 0ll)
                cout << "YES\n";
            else
            {
                cout << "NO\n";
            }
            continue;
        }


        long long rem = k - digits_used;
        curr_sum += (20ll) * (rem / 4ll);
        
        if (rem % 4ll == 3ll)
            curr_sum += 16ll;
        else if (rem % 4ll == 2ll)
            curr_sum += 14ll;
        else if (rem % 4ll == 1ll)
            curr_sum += 8ll;

        if (curr_sum % 3ll == 0ll)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
        


    }
}