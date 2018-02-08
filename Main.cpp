/*
 * Demonstrates usage of a json library in C++
 * Provides parsing example
 * Date : 2018/02/07
 * meta : tag-json, tag-a-list, tag-angel-list
 */

#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// can be replaced with Dictionary <id, name>
// However this one helps this implementation of searching
// not used yet.. moved to C# before implementing the Graph Algorithm
typedef struct sTreeNode {
  int id;
  std::string name;
  // vector<struct sTreeNode> children;
} TreeNode;

class Graph {
public:
  Graph(int n) :
    rootIndex(0),
    numNodes(n) {
    AdjList.resize(numNodes);
  }

  // update it
  const int rootIndex;
  const int numNodes;
  std::vector<std::vector<int>> AdjList;

};

int main() {
  std::string line;
  /* this worked in A-List coding IDE online
  json j;
  while (std::getline(std::cin, line)) {
    j = json::parse(line);
  }*/
  std::getline(std::cin, line);
  json j = json::parse(line);

  int numNodes = j[0]["id"];
  for (int i = 1; i<(int)j.size(); i++)
    if (numNodes < j[i]["id"])
      numNodes = j[i]["id"];

  Graph graphDemo(++numNodes);

  /*
    Another way to parse json object
    for (int i = 0; i<(int)j.size(); i++)
    // each record
      for (json::iterator it = j[i].begin(); it != j[i].end(); ++it) {
        // string key = it.key();   i.e., "id"
        // string val = it.value();   i.e., 1
      }
  */

  // build adjacency list
  for (int i = 0; i<(int)j.size(); i++) {
    std::string s = j[i]["name"];

    if (s.front() == '"') {
      s.erase(0, 1); // erase the first character
      s.erase(s.size() - 1); // erase the last character
    }

    std::cout << "name : " << s << "\n";
    if (j[i]["parent_id"] == nullptr)
      graphDemo.AdjList[graphDemo.rootIndex].push_back(j[i]["id"]);
    else {
      int pIndex = j[i]["parent_id"];
      graphDemo.AdjList[pIndex].push_back(j[i]["id"]);
    }
  }
  std::cout << " root index " << graphDemo.rootIndex << std::endl;

  return 0;
}
