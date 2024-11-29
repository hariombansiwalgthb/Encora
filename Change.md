# Changes Summary(check output folder for execution time comparison snapshots and conan local package snapshot).
* > Added const and pass by ref.
* > Added unique_ptr.
* > moved constants and global from clock to constants.h and marked constexpr.
* > Implemented conanfile for package creation for  clock & graph and consumption in Main App.
* > Implemented CMakes for clock, graph, Main App.
* > Block: changed container from list to unordered_set of string attributes.
* > Graph: changed the container from list to unordered_map i.e. hash map where key is the block's name and value is unique_ptr to block object. Ensuring uniqueness of attributes and faster lookups.
* > Added a unordered_map std::unordered_map<std::string, std::vector<Block*>> m_attributes: A hash map where each key is an attribute name,
    and the value is a vector of pointers to the Block objects that possess that attribute. This allows efficient retrieval of blocks based on an attribute.
    Ensuring efficient lookups based on block name providing average constant-time complexity for insertions, deletions and lookups.
* > Added `std::unordered_map<std::string, std::vector<Block*>> m_attributes` in graph for faster attributes based searching of block.
* > added skeleton for exception handling  
