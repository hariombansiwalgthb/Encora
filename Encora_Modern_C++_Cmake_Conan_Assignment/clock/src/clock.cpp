/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// DO NOT MODIFY ANY CODE BELOW THIS POINT
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include <cassert>
#include "clock.h"
#include "constants.h"

void createBlockNames() {
    std::ostringstream s;
    for (int i = 0; i < s_distinctBlocks; ++i) {
        s << s_blockBaseName;
        s_blockNames.push_back(s.str());
    }
}

void createAttrNames() {
    for (int i = 0; i < s_distinctAttributes; ++i) {
        std::ostringstream s;
        s << s_attrBaseName << i;
        s_attrs.push_back(s.str());
    }
}

std::chrono::milliseconds Measure_AddBlocks(Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    int blockNum = 0;
    int attrNum = 0;

    for (int i = 0; i < s_blockQuantity; ++i)
    {
        ++blockNum;
        blockNum %= s_distinctBlocks;
        std::unique_ptr<Block> b = std::make_unique<Block>();
        b->SetName(s_blockNames[blockNum]);
        for (int j = 0; j < s_attributesPerBlock; ++j)
        {
            ++attrNum;
            attrNum %= s_distinctAttributes;
            b->AddAttribute(s_attrs[attrNum]);
        }
        graph.AddBlock(std::move(b));
    }
    auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

std::chrono::milliseconds Measure_FindAttributesByBlock(const Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    size_t compareLength = s_attrBaseName.length();

    for (const auto& pair : graph.GetAllBlocks()) {
        const auto& block = pair.second;  // Access the Block via pair.second (the unique_ptr<Block>)

        if (block) {
            for (const auto& attr : block->GetAttributes()) {
                assert(attr.compare(0, compareLength, s_attrBaseName) == 0);
            }
        }
    }


    auto end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

std::chrono::milliseconds Measure_FindBlocksByAttribute(const Graph& graph)
{
    auto start = std::chrono::system_clock::now();
    size_t compareLength = s_blockBaseName.length();

    for (const auto& attr : s_attrs) {
        for (auto block : graph.GetBlocksWithAttribute(attr)) {
            assert(block->GetName().compare(0, compareLength, s_blockBaseName) == 0);
        }
    }
    auto end = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

