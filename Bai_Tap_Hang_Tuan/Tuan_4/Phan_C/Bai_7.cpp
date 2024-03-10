#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void printLargeWord(const string& word) {
    map<char, vector<string>> patterns = {
        {'A', {"  #   ", " # #  ", "#   # ", "##### ", "#   # ", "#   # "}},
        {'B', {"####  ", "#   # ", "####  ", "#   # ", "#   # ", "####  "}},
        {'C', {" #### ", "#    #", "#     ", "#     ", "#    #", " #### "}},
        {'D', {"###   ", "#  #  ", "#   # ", "#   # ", "#  #  ", "###   "}},
        {'E', {"##### ", "#     ", "##### ", "#     ", "#     ", "##### "}},
        {'F', {"##### ", "#     ", "##### ", "#     ", "#     ", "#     "}},
        {'G', {" #### ", "#    #", "#     ", "#  ###", "#    #", " #### "}},
        {'H', {"#   # ", "#   # ", "##### ", "#   # ", "#   # ", "#   # "}},
        {'I', {"##### ", "  #   ", "  #   ", "  #   ", "  #   ", "##### "}},
        {'J', {"  ### ", "    # ", "    # ", "    # ", "#   # ", " ###  "}},
        {'K', {"#   # ", "#  #  ", "###   ", "#  #  ", "#   # ", "#   # "}},
        {'L', {"#     ", "#     ", "#     ", "#     ", "#     ", "##### "}},
        {'M', {"#   # ", "## ## ", "# # # ", "#   # ", "#   # ", "#   # "}},
        {'N', {"#   # ", "##  # ", "# # # ", "#  ## ", "#   # ", "#   # "}},
        {'O', {" ###  ", "#   # ", "#   # ", "#   # ", "#   # ", " ###  "}},
        {'P', {"####  ", "#   # ", "####  ", "#     ", "#     ", "#     "}},
        {'Q', {" ###  ", "#   # ", "#   # ", "# # # ", "#  ## ", " ####+"}},
        {'R', {"####  ", "#   # ", "####  ", "#  #  ", "#   # ", "#   # "}},
        {'S', {" #### ", "#     ", " ###  ", "    # ", "#   # ", "####  "}},
        {'T', {"##### ", "  #   ", "  #   ", "  #   ", "  #   ", "  #   "}},
        {'U', {"#   # ", "#   # ", "#   # ", "#   # ", "#   # ", " ###  "}},
        {'V', {"#   # ", "#   # ", "#   # ", "#   # ", " # #  ", "  #   "}},
        {'W', {"#   # ", "#   # ", "#   # ", "# # # ", "## ## ", "#   # "}},
        {'X', {"#   # ", " # #  ", "  #   ", "  #   ", " # #  ", "#   # "}},
        {'Y', {"#   # ", " # #  ", "  #   ", "  #   ", "  #   ", "  #   "}},
        {'Z', {"##### ", "   #  ", "  #   ", " #    ", "#     ", "##### "}},
        {' ', {"      ", "      ", "      ", "      ", "      ", "      "}}
    };

    for (int i = 0; i < 6; ++i) {
        for (char letter : word) {
            cout << patterns[toupper(letter)][i] << "  ";
        }
        cout << endl;
    }
}

int main() {
    string word;
    cin >> word;

    if (word.length() <= 12) {
        printLargeWord(word);
    } else {
        cout << "Độ dài từ vượt quá 12 ký tự!" << endl;
    }

    return 0;
}
