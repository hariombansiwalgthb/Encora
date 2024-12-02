#include "graph.h"

Block::Block() { }
Block::~Block() { }
const std::string& Block::GetName() const { return m_name; }
void Block::SetName(const std::string& name) { m_name = name; }
void Block::AddAttribute(const std::string& attribute) { m_attributes.insert(attribute); }
std::unordered_set<std::string>& Block::GetAttributes() { return m_attributes; }


// Adds the passed block to this graph. Potentially renames the block prior to insertion to guarantee
// each block in the graph has a unique name.
void Graph::AddBlock(Block* block)
{
    std::string uniqueName = GetUniqueBlockNameInGraph(block->GetName());
    block->SetName(uniqueName);

    std::unique_ptr<Block> blockPtr(block);
    for (const auto& attribute : block->GetAttributes()) {
        m_attributeIndex.emplace(attribute, block);
    }

    m_blocksByName[uniqueName] = std::move(blockPtr);
}

std::unordered_set<Block*> Graph::GetBlocks() {
    std::unordered_set<Block*> result;
    for (auto& pair : m_blocksByName) {
        result.insert(pair.second.get());
    }
    return result;
}

std::unordered_set<Block*> Graph::GetBlocksWithAttribute(const std::string& attribute)
{
    std::unordered_set<Block*> result;
    auto range = m_attributeIndex.equal_range(attribute);

    for (auto it = range.first; it != range.second; ++it) {
        result.insert(it->second);
    }
    return result;
}


// Generate a unique name for this block within the graph.
// If there's no name collision, then the original Block name is returned.
// If there is a name collision, then we will appends numbers to the name to make unique.
// So if you call with a block named "a" and there's already a block named "a", then it will return "a1".
// If there's already an "a1" then it will return "a2", and so on.

std::string Graph::GetUniqueBlockNameInGraph(const std::string& baseName)
{

    std::string potentialName = baseName;
    int count = 0;

    while (m_blocksByName.find(potentialName) != m_blocksByName.end()) {
        potentialName = baseName + std::to_string(count++);
    }

    return potentialName;
}
