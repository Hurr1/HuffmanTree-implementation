#include "Algorithm.hpp"
#include <cstring>
#include <algorithm>
#include <ctype.h>

std::string chars;

std::string alg::getInputChar()
{
    std::string buffer;
    while(true)
    {
        std::cout<<"Character: ";
        std::getline(std::cin,buffer);
        if(buffer.find("stop") == 0 || buffer.find("STOP") == 0) return "STOP";
        if(buffer.size() > 1)
        {
            std::cout<<"Invalid input, you need to provide only one character"<<'\n';
            return getInputChar();
        }
        std::transform(buffer.begin(),buffer.end(),buffer.begin(),::toupper);
        if(chars.find(buffer[0])!= std::string::npos && chars.size() != 0)
        {
            std::cout<<"Character "<<buffer[0] << " is already in Tree."<<'\n';
            return alg::getInputChar();
        }
        if(!isalpha(buffer[0]))
        {
            std::cout<<"Invalid input, you need to provide a character from A to Z"<<'\n';
            return alg::getInputChar();
        }
        chars += buffer[0];
        return buffer;
    }
}
int alg::getInputDigit()
{
    std::string buffer;
    while (true)
    {
        std::cout<<"Frequency: ";
        std::getline(std::cin,buffer);
        if(!isNumber(buffer))
        {
            std::cout<<"Invalid input, you need to provide a non-negative number"<<'\n';
            return alg::getInputDigit();
        }
        int number = std::stoi(buffer);
        if(!number)
        {
            std::cout<<"0 frequency"<<'\n';
            return alg::getInputDigit();
        }
        return number;
    }
    
}


bool alg::isNumber(const std::string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

std::vector<std::shared_ptr<Block>> alg::getBlocks()
{
    std::vector<std::shared_ptr<Block>> blocks;
    while(true)
    {
        std::string letter = alg::getInputChar();
        if(letter.find("STOP") == 0) break;
        int value = alg::getInputDigit();

        blocks.emplace_back(std::shared_ptr<Block>(new Block({letter,value})));
    }
    return std::move(blocks);
}

std::shared_ptr<Block> alg::makeTree(std::vector<std::shared_ptr<Block>>blocks)
{
    while(blocks.size()>1)
    {
        std::sort(blocks.begin(),blocks.end(),[](auto _1, auto _2){return _1->_chars[0] < _2->_chars[0];});
        std::sort(blocks.begin(),blocks.end(),[](auto _1, auto _2){return _1->_value < _2->_value;});

        std::shared_ptr<Block> newBlock(new Block({blocks[0]->_chars + blocks[1]->_chars,blocks[0]->_value + blocks[1]->_value}));
        newBlock->_left = blocks[0];
        newBlock->_right = blocks[1];

        blocks.erase(blocks.begin(),blocks.begin()+2);

        blocks.emplace_back(newBlock);
    }
    return blocks[0];
}

void alg::getPathToChar(std::shared_ptr<Block> block, std::string prevPath)
{
    if(block->_right != nullptr || block->_left != nullptr)
    {
        if(block->_right!= nullptr) getPathToChar(block->_right,prevPath+'1');
        if(block->_left!= nullptr) getPathToChar(block->_left,prevPath+'0');
    }
    else
    {
        std::cout<< "For " << block->_chars << " the compressed format is " << prevPath <<'\n';
    }
}