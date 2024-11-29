#include <graph.h>

Block::Block() { }
Block::~Block() { }
std::string Block::GetName() { return m_name; }
void Block::SetName(std::string name) { m_name = name; }
void Block::AddAttribute(std::string attribute) { m_attributes.push_back(attribute); }
std::list<std::string> Block::GetAttributes() { return m_attributes; }


// Adds the passed block to this graph. Potentially renames the block prior to insertion to guarantee
// each block in the graph has a unique name.
void Graph::AddBlock(Block* block)
{
    // Make sure we have a unique name for this block within the content of this Graph object.
    std::string uniqueName = GetUniqueBlockNameInGraph(block);
    block->SetName(uniqueName);
    // Add it to our collection of blocks.
    m_blocks.push_back(block);
}

std::list<Block*> Graph::GetBlocks() {
    return m_blocks;
}

std::list<Block*> Graph::GetBlocksWithAttribute(std::string attribute)
{
    std::list<Block*> blocksWithAttribute;
    for (Block* b : m_blocks)
    {
        std::list<std::string> attributes = b->GetAttributes();
        for (std::string s : attributes)
        {
            if (s == attribute)
            {
                blocksWithAttribute.push_back(b);
                break;
            }
        }
    }
    return blocksWithAttribute;
}

// Determines if the specified blockName is already the name of a block in this Graph.
bool Graph::BlockNameExistsInGraph(std::string blockName)
{
    bool exists = false;
    for (auto i = m_blocks.begin(); i != m_blocks.end(); i++)
    {
        Block* iterBlock = *i;
        std::string iterName = iterBlock->GetName();
        if (iterName == blockName)
        {
            exists = true;
        }
    }
    return exists;
}

// Generate a unique name for this block within the graph.
// If there's no name collision, then the original Block name is returned.
// If there is a name collision, then we will appends numbers to the name to make unique.
// So if you call with a block named "a" and there's already a block named "a", then it will return "a1".
// If there's already an "a1" then it will return "a2", and so on.
std::string Graph::GetUniqueBlockNameInGraph(Block* block)
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
