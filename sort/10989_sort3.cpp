#include <iostream>

using namespace std;

int arr[10001];
int main () {

    int n, temp, max;

    scanf("%d", &n);

    max = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        arr[temp]++;
        if (temp > max) max = temp;
    }

    for (int i = 0; i <= max; i++) {
        for(int j = 0; j < arr[i]; j++) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
