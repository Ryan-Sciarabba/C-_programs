/*
Purpose: To take in a list of stock prices to manipulate and display the data
Written by: Ryan Sciarabba
Language: C++ (g++ target)
Version: 2.7.4
Date of Creation: 4/15/2019
Date of Last Revision: 4/15/2019
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int day = 1, //Day counter
        diff = 1; //Price difference counter

    double price; //Input price

    vector<double> vPrice; //Vector for prices
    vector<double> pDiff(16); //Vector for price differences

    //Store prices in a vector
    while(day <= 15){
        cout<<"Please input the stock price on day "<<day<<": ";
        cin>>price;
        vPrice.push_back(price);
        day++;
        vPrice.erase(price);
    }
    cout<<endl;

    //Find highest and lowest trading prices
    cout<<"Lowest Price: "<<*min_element(vPrice.begin(), vPrice.end())<<endl;
    cout<<"Highest Price: "<<*max_element(vPrice.begin(), vPrice.end())<<endl<<endl;

    //Find differences per day of trade prices
    adjacent_difference(vPrice.begin(), vPrice.end(), pDiff.begin());

    while(diff <= 14){
        cout<<"Price difference between day "<<diff<<" and "<<diff + 1<<": "<<pDiff[diff]<<endl;
        diff++;
    }
    cout<<endl;

    //Sort prices from low to high
    sort(vPrice.begin(), vPrice.end());

    day = 1;

    cout<<"Prices from low to high: ";
    while(day <= 15){
        cout<<vPrice.at(day - 1)<<" ";
        day++;
    }
    cout<<endl;

    return 0;
}
