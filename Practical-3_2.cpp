#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int iterativeSum(const vector<int>& arr)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    return sum;
}

int recursiveSum(const vector<int>& arr, int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start_iter = high_resolution_clock::now();
    int sum_iterative = iterativeSum(arr);
    auto end_iter = high_resolution_clock::now();
    auto duration_iter = duration_cast<nanoseconds>(end_iter - start_iter);

    auto start_rec = high_resolution_clock::now();
    int sum_recursive = recursiveSum(arr, n);
    auto end_rec = high_resolution_clock::now();
    auto duration_rec = duration_cast<nanoseconds>(end_rec - start_rec);

    cout << "\n--- Results ---" << endl;
    cout << "Iterative Sum: " << sum_iterative << endl;
    cout << "Time taken (Iterative): " << duration_iter.count() << " ns" << endl;

    cout << "Recursive Sum: " << sum_recursive << endl;
    cout << "Time taken (Recursive): " << duration_rec.count() << " ns" << endl;


    cout << endl;
    cout << "Ridham Lakkad : 24CE059" << endl;

    return 0;
}
