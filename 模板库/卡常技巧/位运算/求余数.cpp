#include <bits/stdc++.h>

using namespace std;

/*
 * 注意这个技巧只适用于数组长度是 2 的幂次方的情况，比如 2、4、8、16、32 以此类推。
 * 至于如何将数组长度扩展为 2 的幂次方，这也是有比较巧妙的位运算算法的，
 * 可以参考 https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
 * */

int main() {
    vector<int> arr = {1,2,3,4};
    int index = 0;
    while (true) {
        // 在环形数组中转圈
        cout << (arr[index & (arr.size() - 1)]);
        index++;
    }
// 输出：1,2,3,4,1,2,3,4,1,2,3,4...

}