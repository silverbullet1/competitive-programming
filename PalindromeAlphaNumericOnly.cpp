int Solution::isPalindrome(string A) {
    string::iterator end_pos = remove(A.begin(), A.end(), ' ');
    A.erase(end_pos, A.end());
    A.erase(remove_if(A.begin(), A.end(), [](char c) { return !isalnum(c); } ), A.end());
    bool flag=true;
    for(int i=0; i<A.length()/2; i++) {
        if(tolower(A[i]) != tolower(A[A.length()-1-i])) {
            flag=false;
            break;
        }
    }
    if(flag) return 1;
    return 0;
}