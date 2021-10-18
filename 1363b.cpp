#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define endl "\n"

/*
Understanding : 
There are only 4 ypes of good string:
11110000
00001111
0000000
1111111
Type three and four can easily be checked by counting the numbers of one and zeros 
in the array
for type 1 and type 2 we will solve:
First, let us compute the total number of 1's and 0's in the string, denoted by num_ones and num_zeros. Now, as we iterate through the string, let us also maintain done_ones and done_zeros, which denote the number of 1's and 0's encountered so far.

Let us iterate through the string. When we are at position i (indexed from 1), 
we want to answer two questions: what is the cost for changing the string into 11..000 (where number of 1's = i)
and what is the cost for changing the string into 00..111 (where number of 0's = i).

Assuming that done_zeros and done_ones also consider the current index, the answer to the first question is done_zeros + num_ones - done_ones. 
This is because done_zeros 0's must be converted to 1's, and num_ones - done_ones 1's must be converted to 0's. 
Similarly, the answer for the second question is done_ones + num_zeros - done_zeros.

The answer is the minimum over all such changes possible. Please do not forget to consider the all 1's and all 0's string in the above solution.

*/

void solve()
{
    string str;cin>>str;
    int num0,num1;
    num0 = num1 = 0;
    for(auto &it:str)
    {
        num0+=(it == '0');
        num1+=(it == '1');
    }
    int ans = min(num0,num1); // make the whole array 0/1
    int done0=0,done1=0;
    for(auto &it : str)
    {
        done0 += (it == '0');
        done1 += (it == '1');
        ans = min(ans,done0+num1-done1);///convert to 11000
        ans = min(ans,done1+num0-done0);///convert to 00111
    }
    cout<<ans<<endl;

}
signed main()
{
 ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
 lli t;cin>>t;while(t--)
 solve();
 return 0;
}