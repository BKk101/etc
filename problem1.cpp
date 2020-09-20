#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
	string answer;
    string temp1 = new_id;
	string temp2;
    int i,j;
	int len;
	int flag;
    
    for (i=0;i<temp1.size();i++) {
        if (isupper(temp1[i])) {
            temp1[i] += 32;
        }
    }
	for (i=0, j=0;i<temp1.size();i++) {
        if (islower(temp1[i]) || isdigit(temp1[i]) || temp1[i] == '-' || temp1[i] == '.' || temp1[i] == '_')
			temp2.push_back(temp1[i]);
    }
	temp1.clear();
	for (i=0, flag=0;i<temp2.size();i++) {
		if (flag == 0 && temp2[i] == '.') {flag = 1; temp1.push_back(temp2[i]);}
		if (flag == 1 && temp2[i] != '.') flag = 0;
		if (flag == 0) temp1.push_back(temp2[i]);
	}
	if (temp1[0] == '.') temp2 = temp1.substr(1);
	else temp2 = temp1;
	if (temp2[temp2.size()-1] == '.') temp2.pop_back();
	if (temp2.empty()) temp2= "a";
	if (temp2.size()>=16) temp1 = temp2.substr(0,15);
	else temp1 = temp2;
	while (temp1[temp1.size()-1] == '.') temp1.pop_back();
	while (temp1.size() < 3) temp1.push_back(temp1[temp1.size()-1]);
	answer = temp1;
    return answer;
}

int main()
{
	string str1 = "...A...B!@#..c.D..";
	string str2 = "....!@..";
	string str3 = "ab";
	cout<<solution(str2);
}