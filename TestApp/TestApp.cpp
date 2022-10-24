#include "PhraseGenerator.h"

int main()
{
    TwoDVector Items = TwoDVector();
    std::vector<std::string> list1 = std::vector<std::string>();
    list1.push_back("Hello");
    list1.push_back("Goodbye");
    list1.push_back("Salutations");
    list1.push_back("PeaceOut");

    std::vector<std::string> list2 = std::vector<std::string>();
    list2.push_back("Brave");
    list2.push_back("New");
    list2.push_back("Ugly");

    std::vector<std::string> list3 = std::vector<std::string>();
    list3.push_back("World");
    list3.push_back("Planet");
    list3.push_back("Humanity");

    Items.push_back(list1);
    Items.push_back(list2);
    Items.push_back(list3);

    new PhraseGenerator(Items, "\n");

    return 0;
};

