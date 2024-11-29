/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// DO NOT MODIFY ANY CODE BELOW THIS POINT
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <graph.h>
#include <clock.h>

int main(int argc, char* argv[])
{
    Graph graph;
    createBlockNames();
    createAttrNames();

    auto timeAddBlocks = Measure_AddBlocks(graph);
    std::cout << "Measure_AddBlocks took: " << timeAddBlocks.count() << "ms.\n";

    auto timeFindAttributesByBlock = Measure_FindAttributesByBlock(graph);
    std::cout << "Measure_FindAttributesByBlock took: " << timeFindAttributesByBlock.count() << "ms.\n";

    auto timeFindBocksByAttribute = Measure_FindBlocksByAttribute(graph);
    std::cout << "Measure_FindBlocksByAttribute took: " << timeFindBocksByAttribute.count() << "ms.\n";

    std::getchar();
    return 0;
}
