#include "Block.hpp"


Block::Block(const std::pair<std::string,int>& data)
{
    this->_left = nullptr;
    this->_right = nullptr;

    this->_chars = data.first;
    this->_value = data.second;    
}

std::shared_ptr<Block> Block::getptr()
{
    return shared_from_this();
}
