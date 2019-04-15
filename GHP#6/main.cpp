/*
Purpose: To take in a list of stock prices to manipulate and display the data
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 1.7.4
Date of Creation: 4/15/2019
Date of Last Revision: 4/15/2019
*/
#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

using namespace std;

int main()
{
    int day = 1, //Day counter
        diff = 1; //Price difference counter

    double price; //Input price

    array<double,15> aPrice;
    array<double,14> pDiff;

    //Store prices in a stack
    while(day <= 15){
        cout<<"Please input the stock price on day "<<day<<": ";
        cin>>price;
        aPrice[day - 1] = price;
        day++;
    }
    cout<<endl;

    //Find highest and lowest trading prices
    cout<<"Lowest Price: "<<*min_element(aPrice.begin(), aPrice.end())<<endl;
    cout<<"Highest Price: "<<*max_element(aPrice.begin(), aPrice.end())<<endl<<endl;

    //Find differences per day of trade prices
    adjacent_difference(aPrice.begin(), aPrice.end(), pDiff.begin());

    while(diff <= 14){
        cout<<"Price difference between day "<<diff<<" and "<<diff + 1<<": "<<pDiff[diff]<<endl;
        diff++;
    }
    cout<<endl;

    //Sort prices from low to high
    sort(aPrice.begin(), aPrice.end());

    day = 1;

    cout<<"Prices from low to high: ";
    while(day <= 15){
        cout<<aPrice[day - 1]<<" ";
        day++;
    }

    return 0;
}
