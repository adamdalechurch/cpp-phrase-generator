#include <iostream>
#include <string>
#include <vector>
#include <cmath>;

struct TwoDVector : std::vector<std::vector<std::string>> {};

/**
 * Class for taking multiple lists of words and a seperator ouputting each possible string combination
 */
class PhraseGenerator {
public:
    PhraseGenerator(TwoDVector items, std::string seperator) {
        _items = items;
        _seperator = seperator;
        CalcPermutations();

        if (_num_permutations >= MAX_CHARS)
            std::cout << "List cannot exceed " << MAX_CHARS << " characters.";
        else {
            Permute();
            std::cout << print();
        }
    }

private:
    TwoDVector _items;
    TwoDVector _output;
    int _num_permutations = 1;
    std::string _seperator;
    const int MAX_CHARS = 1000000;

    // methods:
    std::string print() {
        std::string res = "";
        for (int x = 0; x < _output.size(); x++) {
            for (int y = 0; y < _output[x].size(); y++) {
                res += _output[x][y] + " ";
            }

            res += _seperator;
        }
        return res;
    }

    void Permute() {
        for (int x = 0; x < _items.size(); x++) {
            if (_output.size() == _num_permutations)
                return;
            PermuteNext(_items[x], 0, std::vector<std::string>());
        }
    }

    void PermuteNext(std::vector<std::string> item, int index, std::vector<std::string> perm) {
        int i = index;

        for (int x = 0; x < item.size(); x++) {
            if (i >= perm.size())
                perm.push_back(item[x]);
            else
                perm[i] = item[x];

            if (_output.size() == _num_permutations)
                return;

            if (i < _items.size() - 1)
                PermuteNext(_items[i + 1], i + 1, perm);
            else
                _output.push_back(perm);
        }
    }

    void CalcPermutations() {
        for (int i = 0; i < _items.size(); i++)
            _num_permutations *= _items[i].size();
    }
};