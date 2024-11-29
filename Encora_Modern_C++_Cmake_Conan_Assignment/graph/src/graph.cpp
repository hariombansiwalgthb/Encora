#include "graph.h"
#include <iostream>
#include <string>

//Block Impl
std::string Block::GetName() const { return m_name; }
void Block::SetName(const std::string& name)
{
    try
    {
        if (name.empty()) {
            throw std::invalid_argument("Block name cannot be empty");
        }
        m_name = name;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error in SetName: " << e.what() << std::endl;
    }
}

void Block::AddAttribute(const std::string& attribute)
{
    try
    {
        if (attribute.empty()) {
            throw std::invalid_argument("Attribute cannot be empty");
        }
        m_attributes.insert(attribute);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error in AddAttribute: " << e.what() << std::endl;
    }
}
const std::unordered_set<std::string>& Block::GetAttributes() const { return m_attributes; }

//Graph Impl
 // Adds a block to the graph with unique name handling
void Graph::AddBlock(std::unique_ptr<Block> block)
{
    try
    {
        if (!block) {
            throw std::invalid_argument("Cannot add a null block to the graph");
        }
        std::string uniqueName = GetUniqueBlockNameInGraph(block);
        block->SetName(uniqueName);
        m_blocks[uniqueName] = std::move(block);

        // Also map attributes to the blocks
        for (const auto& attribute : m_blocks[uniqueName]->GetAttributes())
        {
            m_attributes[attribute].push_back(m_blocks[uniqueName].get());
        }
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error adding block: " << e.what() << std::endl;
    }

}

// Get all blocks in the graph
const std::unordered_map<std::string, std::unique_ptr<Block>>& Graph::GetAllBlocks() const
{
    return m_blocks;
}

// Get blocks by attribute
std::vector<Block*> Graph::GetBlocksWithAttribute(const std::string& attribute) const
{
    auto it = m_attributes.find(attribute);
    if (it != m_attributes.end())
    {
        return it->second;
    }
    return {}; // Empty vector if no blocks have this attribute
}

// Check if a block's name already exists in the graph
bool Graph::BlockNameExistsInGraph(const std::string& blockName) const
{
    return m_blocks.find(blockName) != m_blocks.end();
}

// Get a unique name for a block
std::string Graph::GetUniqueBlockNameInGraph(const std::unique_ptr<Block>& block) const
{
    std::string originalName = block->GetName();
    std::string potentialName = block->GetName();
    unsigned int count = 0;
    bool foundUniqueName = false;
    while (foundUniqueName == false)
    {
        if (!BlockNameExistsInGraph(potentialName))
        {
            foundUniqueName = true;
        }
        else if (BlockNameExistsInGraph(potentialName))
        {
            std::ostringstream s;
            s << originalName << count;
            potentialName = s.str();
            count++;
        }
    }
    return potentialName;
}

