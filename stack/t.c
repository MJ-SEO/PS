#include <cstdio>
#include <stack>
#include <vector>
 
using namespace std;
 
int main() {
    int t, index = 1;
    scanf("%d", &t);
    stack<int> st;
    vector<char> v;
    while (t--) {
        int num;
        scanf("%d", &num);
        if (st.empty()) {
            st.push(index);
            index += 1;
            v.push_back('+');
        }
        if (!st.empty() && st.top() > num) {
            printf("NO");
            return 0;
        }
        while (!st.empty() && st.top() < num) {
            st.push(index);
            index += 1;
            v.push_back('+');
        }
        if (!st.empty() && st.top() == num) {
            st.pop();
            v.push_back('-');
        }
    }
    for (int i = 0; i < v.size(); i++) {
        printf("%c\n", v[i]);
    }
    return 0;
}

