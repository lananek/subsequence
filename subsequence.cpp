#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    long long n, answer = 0;
    fin >> n;
    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        fin >> num[i];
    }
        
    if (n == 1) { 
        fout << 1; 
        return 0; 
    }
    vector <int> A(n + 1);
    A[0] = INT_MIN;

    for (int i = 1; i < n + 1; i++) {
        A[i] = INT_MAX;
    }
        
    for (int i = 0; i < n; i++)
    {
        long long j = int(upper_bound(A.begin(), A.end(), num[i]) - A.begin());
        if (A[j - 1] < num[i] && num[i] < A[j])
        {
            A[j] = num[i];
            answer = max(j, answer);
        }
    }

    fout << answer << endl;
    fin.close();
    fout.close();
    return 0;
}