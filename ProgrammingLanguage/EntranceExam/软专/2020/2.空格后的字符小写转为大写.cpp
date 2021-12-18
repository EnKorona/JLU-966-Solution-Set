int main() {
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length() - 1; i++) { //无需考虑最后一个字符是不是空格
            if (s[i] == ' ' && s[i + 1] > 'a' && s[i + 1] < 'z') {
                s[i + 1] = s[i + 1] + 'A' - 'a';
            }
        }
    }
    cout << s << endl;
}