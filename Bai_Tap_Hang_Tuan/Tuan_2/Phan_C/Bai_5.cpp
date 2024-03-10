#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

string NumberToEnglish(int n){
    if(n==0) return "zero";
    string one_digit[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string thousands[]={"", "thousand", "million", "billion", "trillion"};
    string res = "";

    int billion = n / 1000000000;
    n %= 1000000000;
    if (billion > 0) {
        res += NumberToEnglish(billion) + " " + thousands[4] + " ";
    }

    int million = n / 1000000;
    n %= 1000000;
    if (million > 0) {
        res += NumberToEnglish(million) + " " + thousands[3] + " ";
    }

    int thousand = n / 1000;
    n %= 1000;
    if (thousand > 0) {
        res += NumberToEnglish(thousand) + " " + thousands[2] + " ";
    }

    int hundred = n / 100;
    n %= 100;
    if (hundred > 0) {
        res += one_digit[hundred] + " hundred ";
    }

    if (n >= 20) {
        int ten = n / 10;
        n %= 10;
        res += tens[ten] + " ";
    }

    if (n >= 10 && n < 20) {
        res += teens[n - 10] + " ";
    } else if (n > 0) {
        res += one_digit[n] + " ";
    }

    return res;
}

int main(){
    int num;
    cin >> num;
    cout << NumberToEnglish(num) << endl;
    return 0;
}
