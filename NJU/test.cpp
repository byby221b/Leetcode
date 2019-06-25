#include <cstdio>
#include <algorithm>
using namespace std;
int const MAX = 1e3 + 5;
double a[MAX], lstk[MAX], rstk[MAX];
int l[MAX], r[MAX], n;
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    int top = 0;
    for (int i = 0; i < n; i++) {
        if (top == 0 || lstk[top] < a[i]) {
            lstk[++top] = a[i];
        } else {
            int pos = lower_bound(lstk, lstk + top, a[i]) - lstk;
            lstk[pos] = a[i];
        }
        l[i] = top;
    }
    top = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (top == 0 || rstk[top] < a[i]) {
            rstk[++top] = a[i];
        } else {
            int pos = lower_bound(rstk, rstk + top, a[i]) - rstk;
            rstk[pos] = a[i];
        }
        r[i] = top;
    }
    int ma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ma = max(ma, l[i] + r[j]);
        }
    }
    printf("%d\n", n - ma);
}
