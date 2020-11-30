//
//  main.cpp
//  tree23
//
//  Created by 謝育斌 on 2020/11/26.
//
#include "tree23.h"

int main() {
    std::vector<std::string>number_string;
    std::string str;
    std::stringstream ss;
    getline(std::cin, str);
    ss << str;
    while (getline(ss, str, ' ')) {
        number_string.push_back(str);
    }
    ss.clear();
    str.clear();
    std::vector <int> input(number_string.size());
    for (int i = 0; i < number_string.size(); i++) {
        input[i] = stoi(number_string[i]);
    }

    Node* root = new Node();
    root->leftdata=input[0];
    tree23 tree=tree23(root);
    for (int i = 1; i < input.size(); ++i) {
        tree.insert(tree.root, input[i]);
    }

    std::vector < std::vector< std::vector <int> > > level_numbers;
    tree.traverse(tree.root, level_numbers, 1);

    for (int i = 0; i < level_numbers.size(); ++i) {
        for (int j = 0; j < level_numbers[i].size(); ++j) {
            for (int k = 0; k < level_numbers[i][j].size(); ++k) {
                std::cout << level_numbers[i][j][k];
                if (k != level_numbers[i][j].size() - 1) {
                    std::cout << " ";
                }
            }
            if (j != level_numbers[i].size() - 1) {
                std::cout << " / ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
