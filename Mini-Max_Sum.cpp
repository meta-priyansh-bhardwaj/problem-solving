//To print two space-separated integers on one line: the minimum sum and the maximum sum of (n-1) of (n) elements.

//The numbers are 1,2,3,4, and 5 . Calculate the following sums using four of the five integers:

//Sum everything except 1, the sum is 2+3+4+5=14.
//Sum everything except 2, the sum is 1+3+4+5=13.
//Sum everything except 3, the sum is 1+2+4+5=12.
//Sum everything except 4, the sum is 1+2+3+5=11.
//Sum everything except 5, the sum is 1+2+3+4=10.


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.

void miniMaxSum(vector<int> arr) {
    int n;
    n=arr.size();
    long long min ,max=0,sum=0;
    int i,j,k;
    for(i=0;i<n;i++)
    {if(arr[i]>max)
    max=arr[i];}

    min=arr[0];
    for(j=0;j<n;j++)
    { if(arr[j]<min)
    min=arr[j];}

    for(k=0;k<n;k++)
    {sum+=arr[k];}


    cout<<sum-max<<" "<<sum-min;
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
