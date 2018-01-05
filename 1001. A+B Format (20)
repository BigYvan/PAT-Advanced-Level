#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    int a , b , sum;
    stack<int>temp;
    
    cin >> a >> b;
    sum = a + b;
    if (sum < 0) {
        cout << "-";
        sum = - sum;
    }
    if (sum == 0) {
        cout << "0";
    }
    
    while (sum != 0) {
        temp.push(sum % 10);
        sum /= 10;
    }
    int count = temp.size() % 3;
    if (count == 0) {
        count = 3;
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
        count--;
        if (count == 0 && !temp.empty()) {
            cout << ",";
            count = 3;
        }
    }
    return 0;
}


//更优解，参考liuchuo博主
//#include <iostream>
//using namespace std;
//int main() {
//    int a, b;
//    cin >> a >> b;
//    string s = to_string(a + b);
//    int len = s.length();
//    for (int i = 0; i < len; i++) {
//        cout << s[i];
//        if (s[i] == '-') continue;
//        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
//    }
//    return 0;
//}
