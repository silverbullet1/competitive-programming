string Solution::intToRoman(int A) {
    map<int, string> mp;
    mp.clear();
    mp.insert(make_pair(1, "I"));
    mp.insert(make_pair(4, "IV"));
    mp.insert(make_pair(5, "V"));
    mp.insert(make_pair(9, "IX"));
    mp.insert(make_pair(10, "X"));
    mp.insert(make_pair(40 ,"XL"));
    mp.insert(make_pair(50, "L"));
    mp.insert(make_pair(90, "XC"));
    mp.insert(make_pair(100, "C"));
    mp.insert(make_pair(400, "CD"));
    mp.insert(make_pair(500, "D"));
    mp.insert(make_pair(900, "CM"));
    mp.insert(make_pair(1000, "M"));
    mp.insert(make_pair(4000, "SHIVAM"));
    string str = "";
    map<int,string>::iterator it;
    while(A!=0)
        for(it = mp.begin(); it!=mp.end(); it++) {
            if(it->first == A) {
               A -= it->first;
               str += it->second;
               break;
            }
            else if(it->first > A) { //Finding the largest value smallest than the current number..Let's say input was 14 and we reached 40 in our map..so go back one step and subtract that value..keep
              // doing this till the number becomes 0
               auto it1 = prev(it, 1);
               A -= it1->first;
               str += it1->second;
               break;
            }
            // cout << str <<" " ;
    }
    return str;

}
