#include <bits/stdc++.h>
using namespace std;

typedef struct Item
{
    int startingTime;
    int finishingTime;
};

bool compare(Item a, Item b);
int maxActivity(Item activities[], int numberOfActivity);

int main(void)
{
    int weight = 15, numberOfActivity = 6;
    Item activities[] = {{1, 2}, {3, 4}, {0, 6},{5, 7}, {8 ,9}, {5, 9}};

    int result = maxActivity(activities, numberOfActivity);
    cout << "Maximum activity: " << result << endl;

    return 0;
}

bool compare(Item a, Item b)
{
    return a.finishingTime < b.finishingTime;
}

int maxActivity(Item activities[], int numberOfActivity)
{
    //sort activities based on finishing time
    sort(activities, activities+numberOfActivity, compare);

    cout << "Activities are selected: " << endl;
    cout << activities[0].startingTime << " " << activities[0].finishingTime << endl;
    int finishingTime = activities[0].finishingTime;
    int counter  = 1;

    for(int i = 1; i < numberOfActivity; i++)
    {
        if(finishingTime <= activities[i].startingTime)
        {
            cout << activities[i].startingTime << " " << activities[i].finishingTime << endl;
            counter++;
            finishingTime = activities[i].startingTime;
        }
    }

    return counter;
}
