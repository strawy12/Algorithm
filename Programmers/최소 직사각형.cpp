#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {

    int width = 0, height = 0;

    for (auto size : sizes)
    {
        if (size[0] < size[1])
        {
            swap(size[0], size[1]);
        }

        if (width < size[0])
        {
            width = size[0];
        }

        if (height < size[1])
        {
            height = size[1];
        }
    }

    return height * width;
}