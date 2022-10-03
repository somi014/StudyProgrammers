#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int minW = 0;
    int minH = 0;
    for (int i = 0; i < sizes.size(); ++i) {
        if(minW > sizes[i][0]) {
            minW = sizes[i][0];
        }
        if(minH > sizes[i][1]){
            minH = sizes[i][1];
        }
    }

    int size = minW * minH;
    for (int i = 0; i < sizes.size(); ++i) {
        int tempW = minW;
        int tempH = minH;
        if(minW < sizes[i][0]) {
            tempW = sizes[i][0];
        }
        if(minH <sizes[i][1]) {
            minH = sizes[i][1];
        }
        int total1 = tempW * tempH;
        if(size > total1) {

        }

        if(minH < sizes[i][1]) {

        }

    }

    return answer;
}

int main()
{
    vector<vector<int>> sizes = { {60, 50}};
    solution(sizes);

    return 0;
}
