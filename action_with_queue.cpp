#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void add(std::queue<int>& q,int number) {
    q.push(number);
}

int ret(std::queue<int>& q) {
    return q.front();
}

void del(std::queue<int>& q) {
    q.pop();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::queue<int> q;
    int n, type, number;
    std::cin >> n ;
    for (int i = 0; i < n; i++) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> number;
            add(q, number);
        }
        if (type == 2) {
            del(q);
        }
        if (type == 3) {
            std::cout << ret(q)<<"\n";
        }
    }

    return 0;
}
