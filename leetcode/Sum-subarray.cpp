#include <iostream>
using namespace std;
// Maximum subarray sum

int main()
{
    int array[] = {0, 1, 2, 3, 4, 5, 6};
    int n = 7;
    int best = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int sum = 0;
            for (int k = a; k <= b; k++)
            {
                sum += array[k];
            }
            best = max(best, sum);
        }
    }
    cout << best << "\n";

    int best = 0;
    for (int a = 0; a < n; a++)
    {
        int sum = 0;
        for (int b = a; b < n; b++)
        {
            sum += array[b];
            best = max(best, sum);
        }
    }
    cout << best << "\n";

    int best = 0, sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    cout << best << "\n";
}