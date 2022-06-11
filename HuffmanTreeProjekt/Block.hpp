#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <memory>
#include <string>

class Block : std::enable_shared_from_this<Block>
{
public:
    Block(const std::pair<std::string,int>&);
    std::shared_ptr<Block> getptr();

public:
    std::string _chars;

    std::shared_ptr<Block> _left;
    std::shared_ptr<Block> _right;
    int _value;
};
#endif // __BLOCK_H__