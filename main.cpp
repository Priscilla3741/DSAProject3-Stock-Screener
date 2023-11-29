#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Stocks.h"
using namespace std;



int main() {
    string sector;
    float price;

    ifstream stockInfo("Stocks.csv");
    stockInfo.open ("Stocks.csv");




    if (!stockInfo.is_open()) {
        cout << "Error opening file Stocks.csv" << endl;
    }

    unordered_map<string, vector<Stock>> stockMap;

    if (stockInfo.is_open()) {
        string fileData;
        getline(stockInfo, fileData);

        while (getline(stockInfo, fileData)) {
            string symbol, name, sector, sec;
            string p,pe,dy,es,wl,wh,mc,eb,ps,pb;
            istringstream stream (fileData);

            getline(stream, symbol, ',');
            getline(stream, name, ',');
            getline(stream, sector, ',');

            getline(stream, p, ',');
            getline(stream, pe, ',');
            getline(stream, dy,',');
            getline(stream, es,',');
            getline(stream, wl,',');
            getline(stream, wh,',');
            getline(stream, mc,',');
            getline(stream, eb,',');
            getline(stream, ps,',');
            getline(stream, pb,',');

            float price = stof(p);
            float pricePerEarnings = stof(pe);
            float dividendYield = stof(dy);
            float earningsPerShare = stof(es);
            float weekLow52 = stof(wl);
            float weekHigh52 = stof(wh);
            float marketCap = stof(mc);
            float ebitda = stof(eb);
            float pricePerSale = stof(ps);
            float pricePerBook = stof(pb);

            getline(stream, sec, ',');

            Stock stock(symbol, name, sector, price, pricePerEarnings, dividendYield, earningsPerShare, weekLow52, weekHigh52, marketCap, ebitda, pricePerSale, pricePerBook);

            stockMap[sector].push_back(stock);
        }



        std::cout << "Sector: "<< endl;
        std:: cin >> sector;

        std::cout << "Price: "<< endl;
        std:: cin >> price;

//         iterate through map
//        for (const auto& inputs : stockMap) {
//            const string& secName = inputs.first;
//            const vector<Stock>& sectorStocks = inputs.second;
//        }

    }

    return 0;
}

