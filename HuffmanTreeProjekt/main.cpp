#include <iostream>
#include <memory>
#include <vector>
#include "Algorithm.hpp"
#include "Block.hpp"

int main()
{
    std::vector<std::shared_ptr<Block>>blocks = alg::getBlocks();
    auto root = alg::makeTree(blocks);
    if(!root->_left && !root->_right)
        std::cout<< "For " << root->_chars << " the compressed format is 0"<<'\n';
    else 
        alg::getPathToChar(root);
}

