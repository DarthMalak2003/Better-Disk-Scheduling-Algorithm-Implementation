#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void SSTF(int request[], int size, int head)
{
    vector<int> tracks(request, request + size);

    int totalSeekCount = 0;
    int curTrack, distance;

    for (int i = 0; i < size; i++)
    {
        auto minTrack = min_element(tracks.begin(), tracks.end(),
                                    [head](int a, int b)
                                    { return abs(a - head) < abs(b - head); });

        curTrack = *minTrack;
        distance = abs(curTrack - head);
        totalSeekCount += distance;
        head = curTrack;
        tracks.erase(minTrack);
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

    SSTF(request, size, head);

    return 0;
}
