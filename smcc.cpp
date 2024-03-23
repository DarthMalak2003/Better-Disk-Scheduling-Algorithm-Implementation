#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A = {33, 72, 47, 8, 99, 74, 52, 75};
int N = A.size();
int CHP = 63;
int THM = 0;
int AST;
int MPR;
int low = 0;
int high = N - 1;
using namespace std;

void SMCC()
{   
    sort(A.begin(), A.end());
    MPR = (A[low] + A[high]) / 2;
    if (CHP < MPR)
    {
        for(int i=0; i<N; i++)
        {
            THM += abs(A[i]-CHP);
            CHP = A[i];
        }
    }
    else if (CHP > MPR)
    {
        for(int i=N-1; i>=0; i--)
        {
            THM += abs(A[i]-CHP);
            CHP = A[i];
        }
    }
    AST = THM/N;
}

int main()
{
    SMCC();
    cout << "Total Head Movement is " << THM << endl << "Average Seek Time is " << AST << endl;
    return 0;
}