#include <iostream>
#include <vector>
using namespace std;
#define null 65535
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) { //结构体的构造函数
    val = x;
    left = NULL;
    right = NULL;
  }
};
TreeNode *CreateTree(vector<int> Data) {
  // vector<int>Data = { 1,2,3,null,4,5,6,7,null };
  TreeNode *root = NULL;
  TreeNode *tmp;
  if (Data[0] == null)
    return root;
  vector<TreeNode *> NodesNow;    //用于存储当前层的结点
  vector<TreeNode *> FatherNodes; //用于存储上一层的结点
  root = new TreeNode(Data[0]);
  FatherNodes.push_back(root);
  int index = 1;
  //用于存储每一层可以存储的最大结点个数，应该是上一层非空结点的2倍
  int MaxNum = FatherNodes.size() * 2;
  int SaveNum = 0; //用于记录当前层已经存储了多少结点
  bool LRFlag = false; //用于记录下一个上上层结点的左孩子还是右孩子
  while (index < Data.size()) {
    if (Data[index] == null && SaveNum < MaxNum) {
      SaveNum++;
      index++;
      if (index == Data.size())
        break;
      if (LRFlag)
        LRFlag = false;
      else
        LRFlag = true;
    }
    if (SaveNum < MaxNum) {
      tmp = new TreeNode(Data[index]);
      NodesNow.push_back(tmp);
      if (LRFlag) {
        FatherNodes[SaveNum / 2]->right = tmp;
        LRFlag = false;
      } else {
        FatherNodes[SaveNum / 2]->left = tmp;
        LRFlag = true;
      }
      SaveNum++;
      index++;
    } else {
      SaveNum = 0;
      MaxNum = NodesNow.size() * 2;
      LRFlag = false;
      FatherNodes.clear();
      for (int i = 0; i < NodesNow.size(); i++) {
        FatherNodes.push_back(NodesNow[i]);
      }
      NodesNow.clear();
    }
  }
  return root;
}