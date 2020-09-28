#include <unordered_map>
#include <vector>
#include <ctype.h>
#include <iostream>
#include <algorithm>


struct Token {
    std::string payload;
    int count;
};


std::unordered_map<std::string, int> getWordCounts(std::istream& stream) {
    std::unordered_map<std::string, int> counts;
    std::vector<char> buf;
    char ch;

    while (stream.get(ch)) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            buf.push_back(ch);
        } else if (!buf.empty()) {
            std::string word(buf.begin(), buf.end());
            buf.clear();
            ++counts[word];
        }
    }
    
    return counts;
}


int main(int ac, char** av) {
    std::unordered_map<std::string, int> counts = getWordCounts(std::cin);   

    std::vector<Token> res(counts.size());
    int ptr = 0;
    for (const auto& [word, cnt]: counts) {
        res[ptr++] = {word, cnt};
    }
    
    std::sort(res.begin(), res.end(), [](const Token& lhs, const Token& rhs) {
        return std::tie(rhs.count, lhs.payload) < std::tie(lhs.count, rhs.payload);
    });

    for (const auto& item: res) {
        std::cout << item.count << " " << item.payload << std::endl;
    }
}
