#include <bits/stdc++.h>
using namespace std;

typedef struct Item
{
    int value;
    int weight;
};

bool compare(Item a, Item b);
double maxValue(int weight, Item itemList[], int itemNumber);

int main(void)
{
    int weight = 50, itemNumber = 3;
    Item itemList[] = {{60, 10}, {100, 20}, {120, 30}};

    double result = maxValue(weight, itemList, itemNumber);
    cout << "Maximum value: " << result << endl;

    return 0;
}

bool compare(Item a, Item b)
{
    double aRatio = (double)a.value / a.weight;
    double bRatio = (double)b.value / b.weight;

    return aRatio > bRatio;
}

double maxValue(int totalWeight, Item itemList[], int itemNumber)
{
    sort(itemList, itemList+itemNumber, compare);

    double answer = 0;
    for(int i = 0; i < itemNumber; i++)
    {
        cout << itemList[i].value << " " << itemList[i].weight << endl;
        int currentValue = itemList[i].value;
        int currentWeight = itemList[i].weight;

        if(totalWeight - currentWeight >= 0)
        {
            totalWeight -= currentWeight;
            answer += currentValue;
        }
        else
        {
            double fraction = (double)totalWeight / (double)currentWeight;
            totalWeight = (int)(totalWeight - (fraction*currentWeight));
            answer += fraction*currentValue;
        }
    }

    return answer;
}
