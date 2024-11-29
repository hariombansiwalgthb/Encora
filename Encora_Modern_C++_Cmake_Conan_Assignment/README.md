

# Welcome to Encora Modern C++ Assignment

* > Kindly read very carefully and we wish you best of luck with your best approach. 
* > If there is any query feel free to contact me. 
* > Nafis Ayaz | Technical Lead 
* > nafis.ayaz@encora.com 

The problem is defined in "Assignment Definition" section and also mentioned in 
graph/include/graph.h for your better understanding. 

## Directory And Dependency
- In the root, there are two sub-directories - graph and clock, each sub-directory is treated as a library. 
- Graph is a base library to clock library that means clock has a dependency on graph library. 
- There is one main application i.e main.cpp file that need to be an executable called "Application". 
- The main application has dependency on graph and clock library. 
- You need to implement Cmake and Conan to create/export conan packages/libraries to local cache.
- Same way you need to implement Cmake and Conan to make executable: main application(main.cpp).


## DO NOT Instructions
- Kindly read very carefully this section
- Do not modify the source code in clock library i.e clock.cpp, clock.h
- Do not modify the main application i.e main.cpp

## DO Instructions
- Kindly read very carefully this section
- Do modify cmake and conan file in clock library folder
- Do modify cmake and conan file in graph library folder
- Do modify cmake and conan file in root folder
- Do modify source code in graph library i.e graph.cpp, graph.h
- Do add comments tagging with few lines of description where you've made changes/implemented 
- Do a brief description of the changes that you made.

## Asignment Definition 
This program is very simple. It contains two classes: Block and Graph.

- Graphs are responsible for ownership of a collection of Blocks.
- Blocks have two pieces of data: A name (std::string) and collection of (std::string) attributes.

This Graph class supports two operations:

1. Add a Block to the Graph (AddBlock)
- When a Block is added to a Graph, it cannot share a name with any Blocks already in the Graph. If the Block's name is
already elsewhere in the graph, its name will be modified to be unique. If the block's name is already unique, it must
not be changed.
- Calling AddBlock is resource acquisition. When it comes to data management, the Graph is the owner of the Block from
this point on.
- The order of blocks in a graph does not need to be preserved.

2. Return a collection of every Block in the Graph that has a specified attribute (GetBlocksWithAttribute)

- Blocks can have any number of attributes. Attributes of a block are assumed to be unique but it is not necessary to 
  validate that. The order of attributes in a block does not need to be preserved.

There are functions below prefixed with Measure_. These Measure_ functions exercise the two Graph operations previously
discussed. The goal of this exercise is to optimize the execution time of these functions:

- Measure_AddBlocks
- Measure_FindAttributesByBlock
- Measure_FindBlocksByAttribute

If you take a look at main() below, you'll see that it sends the execution time of these functions to stdout. Go ahead and
run the program as-is and it's obvious that the initial performance of these operations is very bad. If it doesn't build or
run, fix it so it does.

The program is also written very badly in many ways.

Goal: See how much better you can make it both in performance and coding style and best practices.
For reference, good solutions are able to speed up the execution time of the whole program by well
over 100 times without sacrificing code clarity.

## Here Are The Rules:

- The dynamic behavior of the code cannot change. Don't just write code to generate the expected output, expect your solution
to be tested on different datasets and platforms.
- You ARE NOT allowed to modify the Measure_ functions or main() except to make them compile and run.
- You ARE allowed to modify the Block and Graph classes. Feel free to change the API, data structures, etc. as long as you can
do so without requiring a modification of Measure_ functions or main().
- Feel free to use any C++11, C++14, C++17 and C++20 language features, so long as they are supported on any platform. That means 
  restricting yourself the standard library, and avoiding any platform-specific extensions.
- Feel free to make any obvious, simple improvements generally.

## To Repository
- Create a repository on github or gitlab
- Push your changes 

## What We Expect
When you're done, please send me three things through Email:
- Share repository link
- Execute command - `conan list "*:*"` and take a screenshot.
- A screenshot of the main application output before and after you made your changes.
- A brief description of the changes that you made.

Good luck, and feel free to get in touch if you have any specific questions.
