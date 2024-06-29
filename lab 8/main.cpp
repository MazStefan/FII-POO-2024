#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>

struct cmp {
    bool operator()(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
        if (a.second == b.second)
            return a.first.compare(b.first) > 0;
        return a.second < b.second;
    };
};

int main() {
    std::ifstream f;
    f.open("text_file.txt");
    
    std::string sentence;
    std::getline(f, sentence);
    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
    [](unsigned char c){ return std::tolower(c); });
    std::map<std::string,int> map;

    std::size_t prev = 0, pos;
    std::string word;
    while ((pos = sentence.find_first_of(" .,?!", prev)) != std::string::npos) {
        int count = 0;
        if (pos > prev) {
            int poss = sentence.find(word, 0);
            while (poss != std::string::npos) {
                ++count;
                poss = sentence.find(word, poss + 1);
            }
            word = sentence.substr(prev, pos-prev);
            
            if (word.size() != 0)
                map[word] = count;
        }
        prev = pos+1;
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, cmp> pq;

    for(auto iter = map.begin(); iter != map.end(); ++iter)
    {
        std::pair<std::string, int> p;
        p.first = iter->first;
        p.second = iter->second;
        pq.push(p);
    }

    while (!pq.empty()) {
        std::pair<std::string, int> top = pq.top();
        std::cout << top.first << " => " << top.second << std::endl;
        pq.pop();
    }

    return EXIT_SUCCESS;
}