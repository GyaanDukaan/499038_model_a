#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring> // For strcpy and strlen
#include <vector>

struct MarketData {
    std::string symbol;
    double price;
    int volume;
};

// Function to read data from CSV file using string streams
std::vector<MarketData> readMarketData(const std::string& filename) {
    std::vector<MarketData> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string symbol;
        std::string priceStr;
        std::string volumeStr;

        // Assuming the format is "Symbol,Price,Volume"
        std::getline(ss, symbol, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, volumeStr, ',');

        // Convert strings to appropriate types
        MarketData md;
        md.symbol = symbol;
        md.price = std::stod(priceStr);
        md.volume = std::stoi(volumeStr);
        data.push_back(md);
    }

    file.close();
    return data;
}

// Example usage of strcpy and strlen
void demonstrateStrCopyAndLength() {
    const char* original = "MarketData";
    char copy[50]; // Make sure the array is large enough to hold the string

    strcpy(copy, original); // Copy original to copy
    std::cout << "Original: " << original << ", Length: " << strlen(original) << std::endl;
    std::cout << "Copy: " << copy << ", Length: " << strlen(copy) << std::endl;
}

int main() {
    const std::string filename = "market_data.csv"; // Example CSV filename

    // Read market data from the CSV file
    std::vector<MarketData> marketData = readMarketData(filename);

    // Display the data
    for (const auto& data : marketData) {
        std::cout << "Symbol: " << data.symbol << ", Price: " << data.price << ", Volume: " << data.volume << std::endl;
    }

    // Demonstrate usage of strcpy and strlen
    demonstrateStrCopyAndLength();

    return 0;
}