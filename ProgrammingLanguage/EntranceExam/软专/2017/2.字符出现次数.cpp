

int *count(string s, int a[], int n) {
    int *ans = new int[n];
    memset(ans, 0, sizeof(int) * n);
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == a[j]) {
                ans[j]++;
                break;
            }
        }
    }
    return ans;
}