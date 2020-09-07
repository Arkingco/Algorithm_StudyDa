#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int lcs[1001][1001];
int n;
string str1,str2;
int main(){
	string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
 
    // LCS 알고리즘을 위해 앞에 '0'을 붙여준다.
    str1 = '0' + tmp1;
    str2 = '0' + tmp2;
 
    int len1 = str1.size();
    int len2 = str2.size();

	 for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
                continue;
            }
			if(str1[i] == str2[j])lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else if(str1[i] != str2[j]) lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);
			
			
		}
	 }
	cout << lcs[len1-1][len2-1] << endl;
}