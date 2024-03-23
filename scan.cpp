#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int g_size = 8;
int disk_size = 200;

void SCAN(int arr[], int head, string direction)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;
	if (direction == "left")
		left.push_back(0);
	else if (direction == "right")
		right.push_back(disk_size - 1);

	for (int i = 0; i < g_size; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	int run = 2;
	while (run--) {
		if (direction == "left") {
			for (int i = left.size() - 1; i >= 0; i--) {
				cur_track = left[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "right";
		}
		else if (direction == "right") {
			for (int i = 0; i < right.size(); i++) {
				cur_track = right[i];
				seek_sequence.push_back(cur_track);
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "left";
		}
	}

	cout << "Total Head Movement is " << seek_count << endl;

	cout << "Average Seek Time is " << seek_count/g_size << endl;
}
int main()
{
	int arr[] = {33, 72, 47, 8, 99, 74, 52, 75};
	int head = 63;
	string direction = "left";

	SCAN(arr, head, direction);

	return 0;
}
