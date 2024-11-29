/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// DO NOT MODIFY ANY CODE BELOW THIS POINT
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#pragma once

#include <chrono>
#include "graph.h"

//moved constants and globals to constants.h

void createBlockNames();
void createAttrNames();
std::chrono::milliseconds Measure_AddBlocks(Graph& graph);
std::chrono::milliseconds Measure_FindAttributesByBlock(const Graph& graph);
std::chrono::milliseconds Measure_FindBlocksByAttribute(const Graph& graph);
