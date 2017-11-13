/*
The largest number can any 2 number AND is the upper bound, but we cannot have the upper bound B since there is no way 2 distinct numbers in range can give that number. Lower the answer by 1. Now there are 2 choices either choose number (b-1 and b-2) or (b and b-1) because one of them HAS TO BE DIFFERENT IN ONE BIT ONLY.
Example: A = 0000, B = 1001
Clearly answer cannot be B because there is no way a 2 distinct numbers AND together to have 1001
Lower the answer to 1000, now 1000 can be obtain by a number 1xxx & 1yyy where x,y can be 0 or 1. but clearly you can't have 1111 or 1010 or 1110 for 1xxx and similarly for yyy because they are all out of range, now they can only be 2 numbers that are nearest to the current answer since the difference in only one bit will always produce a better result.
1000 = (1001 & 1000) [differ in 1 bit] or (0111 & 1000) [differ in too many bits]

Case 1
so suppose if b is odd then the last binary bit of b will be 1 and b-1 will have last binary bit as 0
now since b and b-1 are last and secpnd last nuber and they differ by only the last bit their and will be b-1
//example 4, 9 here a=4, b=9;
binary of 9 is 10001 and b-1=1000 ie 8 so the maximum and u can get is 8

Case 2
if the b is even then b ends with 0 and subtacting 1 from it will all the 0 in b until a 1 is found which is turned to a 0
example b=8 ie 1000 now b-1=1000-1=0111 
b=10 ie 1010 now b-1 =1001 2nd (notic e all 0 are flipped to 1s in b until a 1 is gound which is turned to 0)
so if b is even b-1 is odd and b-2 is even b-1 and b-2 will only differ in last bit as explained in prev post.

Case 3
if by above methods u find a number that does not lie in [a,b] then a&b will be the answer
*/

#include <iostream>
using namespace std;
int main()	{
int T;
cin>>T;
while(T--)	{
	long long a,b,ans;
	cin>>a>>b;
	if(b%2==0)
		ans=b-2;
	else
		ans=b-1;
	if(ans>=a and ans<=b)
		cout<<ans<<endl;
	else  { //b-a==1 cases
		ans = a&b;
		cout<<ans<<endl;
	}
	return 0;
}