#include <iostream>

using namespace std;

struct person{
    string ID;
    int SignInTime;
    int SignOutTime;
}student[100];

int main(int argc, const char * argv[]) {
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a1, b1, c1, a2, b2, c2;
        char temp;
        cin >> student[i].ID >> a1 >> temp >> b1 >> temp >> c1 >> a2 >> temp >> b2 >> temp >> c2;
        student[i].SignInTime = a1 * 3600 + b1 * 60 + c1;
        student[i].SignOutTime = a2 * 3600 + b2 * 60 + c2;
    }
    int MinSignIn = 999999, MaxSignOut = 0;
    int unlock = 0, lock = 0;
    for (int i = 0; i < M; i++) {
        if (student[i].SignInTime < MinSignIn) {
            MinSignIn = student[i].SignInTime;
            unlock = i;
        }
        if (student[i].SignOutTime > MaxSignOut) {
            MaxSignOut = student[i].SignOutTime;
            lock = i;
        }
    }
    cout << student[unlock].ID << " " << student[lock].ID;
    return 0;
}
