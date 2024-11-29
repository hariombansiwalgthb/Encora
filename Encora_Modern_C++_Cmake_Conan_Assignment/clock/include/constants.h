#pragma once

#include <string>
#include <vector>

static constexpr int s_blockQuantity = 1000;
static constexpr int s_attributesPerBlock = 250;

static constexpr int s_distinctAttributes = 300;
static constexpr int s_distinctBlocks = 10;
static std::string s_blockBaseName("blockNameBase_");
static std::string s_attrBaseName("attributeBase_");

//HB: should not use globals, should be wrapped, keeping here just for sake of example
static std::vector<std::string> s_attrs;
static std::vector<std::string> s_blockNames;

