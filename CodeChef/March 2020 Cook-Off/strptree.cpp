#include <bits/stdc++.h>

using namespace std;

long long C(long long a)
{
    return (a * (a - 1)) / 2ll;
}

int main()
{
    int t;
    cin >> t;

    int D;

    long long P, Q;

    for (int i = 0; i < t; i++)
    {
        P = 0ll;
        Q = 0ll;
        cin >> D;
        long long curr_pow2 = 1ll;
        long long temp = pow (2ll, D);

        long long mult = 1ll, temp2 = 0ll, temp3 = 2ll;
        for (long long k = 1ll; k <= D; k++)
        {   
            if (mult == 2ll)
            {
                temp2 += 2ll * temp3;
                mult = 1ll;
            }
            else
            {
                temp2 += temp3;
                mult = 2ll;
            }
            
            temp3 *= 2;
        }
        int z;
        if (D & 1)
            z = 1;
        else
        {
            z = 0;
        }
        
        for (long long j = 0ll; j <= D; j++)
        {
            Q += 2ll * C(curr_pow2);
            Q += curr_pow2 * // no of nodes in other subtree * // no of nodes at that level;
            
            // add no of fail in own subtree for every node at that level
            Q += (curr_pow2) * temp3;
           
            curr_pow2 *= 2ll;
            
            temp /= 2;
            if (z)
                temp3 -= (pow(2ll, D - j));
            else
            {
                temp3 -= 2 * (pow(2ll, D - j));
            }
            
            z ^= 1;
        }

        



        int zero;
        if (D & 1)
            zero = 1;
        else
        {
            zero = 0;
        }
        
        long long p_power = 1ll, q_power = 2ll;
        long double fraction;
        for (long long j = (long long)(D) - 1ll; j >= 0ll; j--)
        {
            if (zero)
                P += (pow(2ll, j)) * (pow(2ll, p_power));
            
            Q += (pow(2ll, j)) * pow(2ll, q_power);

            zero ^= 1;
            p_power++;
            q_power++;

        }

        cout << "P: " << P << "\nQ: " << Q << "\n";
        fraction = ((long double)(P)) / ((long double)(Q));
        long double res = fraction * 1000000007ll;
        cout << res << "\n";
    }

}