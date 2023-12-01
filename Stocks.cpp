#include "Stocks.h"

void Stocks::insertStocks(unordered_map<string, vector<StockInfo>> &stockMap) {
    ifstream stockInfo("Stocks.csv");

    if (!stockInfo.is_open()) {
        cout << "Error opening file Stocks.csv" << endl;
    }

    if (stockInfo.is_open()) { // ensure file is open
        string fileData;
        getline(stockInfo, fileData);

        while (getline(stockInfo, fileData)) { // go through file
            string symbol, name, sector, sec;
            string p, pe, dy, es, wl, wh, mc, eb, ps, pb;
            istringstream stream(fileData);

            getline(stream, symbol, ',');
            getline(stream, name, ',');
            getline(stream, sector, ',');

            getline(stream, p, ',');
            getline(stream, pe, ',');
            getline(stream, dy, ',');
            getline(stream, es, ',');
            getline(stream, wl, ',');
            getline(stream, wh, ',');
            getline(stream, mc, ',');
            getline(stream, eb, ',');
            getline(stream, ps, ',');
            getline(stream, pb, ',');

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

            // insert stock into object
            StockInfo stock(symbol, name, sector, price, pricePerEarnings, dividendYield, earningsPerShare,
                        weekLow52, weekHigh52, marketCap, ebitda, pricePerSale, pricePerBook);

            // push the stock into its sector group
            stockMap[sector].push_back(stock);
        }
    }
}

void Stocks::quickSort(vector<StockInfo> &stocks, int start, int end) {
    if (start < end) {
        int partitionIndex = partition(stocks, start, end);
        quickSort(stocks, start, partitionIndex - 1);
        quickSort(stocks, partitionIndex + 1, end);
    }
}

int Stocks::partition(vector<StockInfo>& stocks, int start, int end) {
    int index = 0;
    float pivotElement = stocks[end].getPrice();
    int pivotIndex = start;
    float* temp = new float[end - start + 1];

    for (int i = start; i <= end; i++) {
        if (stocks[i].getPrice() < pivotElement) {
            temp[index] = stocks[i].getPrice();
            index++;
        }
    }

    pivotIndex = start + index - 1;
    temp[index] = pivotElement;
    index++;

    for (int i = start; i < end; i++) {
        if (stocks[i].getPrice() > pivotElement) {
            temp[index] = stocks[i].getPrice();
            index++;
        }
    }
    index = 0;
    for (int i = start; i <= end; i++) {
        if (i == pivotIndex) {
            stocks[i].price = temp[index];
        }
        else {
            stocks[i].price = temp[index];
        }
        index++;
    }
    return pivotIndex;
}




