bool isPalindrome(char *str)
{
    int i, n;
    if (str == NULL)
        return 0;
    else if (strlen(str) == 0) 
        return 1;
    n = strlen(str) - 1;
    for (i = 0; i <= n;) {
        // 过滤数字和字母
        if (!isalnum(str[i])) {
            i++;
            continue;
        }
        if (!isalnum(str[n])) {
            n--;
            continue;
        }
        // 判断首尾是否相同，忽略大小写
        if (tolower(str[i]) != tolower(str[n])) {
            return false;  // 不相同，返回不是回文串
        }
        i++;
        n--;
    }
    return true;
}