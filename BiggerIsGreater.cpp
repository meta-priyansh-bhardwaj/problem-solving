//Bigger Is Greater question on hackerrank.

#include <bits/stdc++.h>
using namespace std;

//  the biggerIsGreater function .
string biggerIsGreater(string w) {
int i=w.length()-1;
int j=i;
while(i>0 && w[i-1]>=w[i])
i--;

if(i==0)
return "no answer";


while(w[j]<=w[i-1]){
    j--;
}

char temp=w[i-1];
w[i-1]=w[j];
w[j]=temp;

j=w.length()-1;

while(i<j){
    temp=w[i];
    w[i]=w[j];
    w[j]=temp;
    i++;
    j--;
}

return w;
}

int main()
{
    int T;
    cin >> T;
     while(T--) {
        string inp;
        cin >> inp;
       string result = biggerIsGreater(inp);

        cout << result << "\n";
    }
    return 0;
}
