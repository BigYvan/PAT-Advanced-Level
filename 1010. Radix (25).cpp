//
//  main.cpp
//  1010
//
//  Created by Bigyvan on 2018/1/11.
//  Copyright © 2018年 Bigyvan. All rights reserved.
//此题坑太大，测试数据巨多，又是黑盒数据，第一遍过了十个，纠结了一天在网络大神的帮助下陆陆续续把坑填上
/*1.input 中两个数字可以是 10 位数，虽然没有告诉 radix 的范围，radix 也可以很大。所以将 radix 和两个数值都设定为 longlong。
2.在计算另一个数的 radix 时，简单的遍历会超时，使用二分查找。
3.下界选数字的所有位上的最大值+1；上界容易想当然的认为就是题中给定了 radix 的数的值。实际上，示例11 b 1 10就是一个反例，原因在于这个假设忽略了一位数的可能性，解决方案是在取给定 radix 的数值和下界中较大的那个数。
4.在二分查找时，不可直接计算出某个 radix 下数的值，因为可能会 longlong 溢出
 */

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

long long t = 0;

long long convertNumber(string n, long long radix){
    long long j = 0;
     long long temp = 0;
    for (long long i = (int)n.size() - 1; i >= 0; i--) {
        if (n[i] >= '0' && n[i] <= '9') {
            temp += (n[i] - '0') * pow(radix, j++);
        }else if (n[i] >= 'a' && n[i] <= 'z')
            temp += (n[i] - 'a' + 10) * pow(radix, j++);
    }
    return temp;
}

int findLargeDigit(string n){
    char result = '0', len = (int)n.size();
    for (int i = 0; i < len; i++) {
        if (n[i] > result) {
            result = n[i];
        }
    }
    if (result >= '0' && result <= '9') {
        return result - '0' + 1;
    }else if (result >= 'a' && result <= 'z')
        return result - 'a' + 11;
    return 0;
}

int cmp(string n, long long radix){
    long long num = convertNumber(n, radix);
    if (num < 0) return 1;//！！！！！！如果溢出，则直接返回1！！！！！！！
    if (num < t)    return -1;
    return (t == num) ? 0 : 1;
}

long long binarySearch(string n, long long left, long long right){
    long long mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int flag = cmp(n, mid);
        if (flag == 0) return mid;
        if (flag == -1) left = mid + 1;
        else right = mid - 1;
    }
    return  -1;
}

int main(int argc, const char * argv[]) {
    string n1, n2;
    long long tag, radix1, radix2, temp;
    cin >> n1 >> n2 >> tag;
    cin >> radix1;
    if (tag == 2) {
        swap(n1, n2);
    }
    temp = convertNumber(n1, radix1);
    t = temp;
    long long low = findLargeDigit(n2);
    long long high = max(low, t) + 1;
    radix2 = binarySearch(n2, low, high);
    if (radix2 == -1) {
        printf("Impossible");
    }else
        printf("%lld",radix2);
    return 0;
}
