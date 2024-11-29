/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/// DO NOT MODIFY ANY CODE BELOW THIS POINT
/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#pragma once

#include <graph.h>

static const int s_blockQuantity = 1000;
static const int s_attributesPerBlock = 250;

static const int s_distinctAttributes = 300;
static const int s_distinctBlocks = 10;
static std::string s_blockBaseName("blockNameBase_");
static std::string s_attrBaseName("attributeBase_");

static std::vector<std::string> s_attrs;
static std::vector<std::string> s_blockNames;

void createBlockNames();

void createAttrNames();

std::chrono::milliseconds Measure_AddBlocks(Graph& graph);

std::chrono::milliseconds Measure_FindAttributesByBlock(Graph& graph);

std::chrono::milliseconds Measure_FindBlocksByAttribute(Graph& graph);