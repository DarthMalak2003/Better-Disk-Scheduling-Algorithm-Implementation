#include <iostream>

using namespace std;

void FCFS(int request[], int size, int head)
{
    int totalSeekCount = 0;
    int curTrack, distance;

    for (int i = 0; i < size; i++)
    {
        curTrack = request[i];
        distance = abs(curTrack - head);
        totalSeekCount += distance;
        head = curTrack;
    }

    cout << "Total Head Movement = " << totalSeekCount << endl;
    double averageSeekTime = static_cast<double>(totalSeekCount) / size;
    cout << "Average Seek Time = " << averageSeekTime << endl;
}

int main()
{
    int request[] = {33, 72, 47, 8, 99, 74, 52, 75};
    int size = sizeof(request) / sizeof(request[0]);
    int head = 63;

    FCFS(request, size, head);

    return 0;
}
