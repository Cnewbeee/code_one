#include <stdio.h>
#include <string.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char s1[1005], s2[1005];
    scanf("%s", s1);
    scanf("%s", s2);
    int a[1005];
    for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);

    int cnt1[26] = {0}, cnt2[26] = {0};
    for (int i = 0; i < n; ++i) {
        cnt1[s1[i] - 'A']++;
        cnt2[s2[i] - 'A']++;
    }
    int maxMatches = 0;
    for (int i = 0; i < 26; ++i) maxMatches += (cnt1[i] < cnt2[i]) ? cnt1[i] : cnt2[i];

    int best = a[0];
    for (int i = 0; i <= maxMatches; ++i) if (a[i] > best) best = a[i];
    printf("%d\n", best);
    return 0;
}
