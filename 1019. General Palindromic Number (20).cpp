#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int N,b;
    cin >> N >> b;
    if (N == 0) {
        cout << "Yes" << endl << "0";
        return 0;
    }
    vector<int>number;
    vector<int>numberReverse;
    while (N) {
        number.push_back(N % b);
        numberReverse.push_back(N % b);
        N = N / b;
    }
    reverse(numberReverse.begin(), numberReverse.end());
    int yes_no = 1;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] != numberReverse[i]) {
            yes_no = 0;
        }
    }
    if (yes_no) {
        printf("Yes\n");
    }else
        printf("No\n");
    printf("%d",numberReverse[0]);
    for (int i = 1; i < number.size(); i++) {
        printf(" %d",numberReverse[i]);
    }
    return 0;
}
