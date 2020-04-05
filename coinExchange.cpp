#include <bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(coins) / sizeof(coins[0]);

int minimumCoin(long amount);

int main(void)
{
    long amount;

    cout << "Enter amount : " ;
    cin >> amount;

    int numberOfCoins = minimumCoin(amount);
    cout << "The minimum number of coin is: " << numberOfCoins << endl;

    return 0;
}

int minimumCoin(long amount)
{
    vector<int> result;

    for(int i = n - 1; i >= 0; i--)
    {
        while(amount >= coins[i])
        {
            amount -= coins[i];
            result.push_back(coins[i]);
        }
    }

    //print resulting coins
    cout << "Coins needed: ";
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return result.size();
}
