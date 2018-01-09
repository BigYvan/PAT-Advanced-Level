
#include <iostream>

using namespace std;

void printChinese(char temp){
    switch (temp) {
        case '1':
            printf("one");
            break;
        case '2':
            printf("two");
            break;
        case '3':
            printf("three");
            break;
        case '4':
            printf("four");
            break;
        case '5':
            printf("five");
            break;
        case '6':
            printf("six");
            break;
        case '7':
            printf("seven");
            break;
        case '8':
            printf("eight");
            break;
        case '9':
            printf("nine");
            break;
        case '0':
            printf("zero");
            break;
        default:
            break;
    }
}
int main(int argc, const char * argv[]) {
    string N;
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N.size(); i++) {
        sum += N[i] - '0';
    }
    string final = to_string(sum);
    printChinese(final[0]);
    for (int i = 1; i < final.size(); i++) {
        printf(" ");
        printChinese(final[i]);
    }
    return 0;
}
