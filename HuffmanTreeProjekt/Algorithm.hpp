#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>
#include "Block.hpp"
#include <vector>

namespace alg
{
    std::string getInputChar();

    int getInputDigit();

    bool isNumber(const std::string& str);

    std::vector<std::shared_ptr<Block>> getBlocks();

    std::shared_ptr<Block> makeTree(std::vector<std::shared_ptr<Block>>blocks);

    void getPathToChar(std::shared_ptr<Block> block, std::string prevPath = "");
}
#endif // __ALGORITHM_H__