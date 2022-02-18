//
// Created by dingmao on 2022/2/14.
//

#include "lc_652.h"
#include <gtest/gtest.h>

vector<string> bfs(TreeNode* node) {

    vector<string> result;

    if(node == nullptr) {
        return result;
    }

    queue<TreeNode*> tempQueue;
    tempQueue.push(node);
    while(!tempQueue.empty())
    {
        node = tempQueue.front();
        tempQueue.pop();

        if(node == nullptr) {
//            result.push_back("null");
        } else {
            result.push_back(to_string(node->val));
            tempQueue.push(node-> left);
            tempQueue.push(node-> right);
        }

    }
    return result;
}


TEST(LCTest, lc_652) /* NOLINT */
{
    auto* root = new TreeNode();
    root->val  = 1;
    auto* node1 = new TreeNode();
    node1->val = 2;
    auto* node2 = new TreeNode();
    node2->val = 3;
    root->left = node1;
    root->right = node2;

    auto* node3 = new TreeNode();
    node3->val = 4;
    node1->left = node3;
    auto* node4 = new TreeNode();
    node4->val = 2;
    node2->left = node4;
    auto* node5 = new TreeNode();
    node5->val = 4;
    node2->right = node5;
    auto* node6 = new TreeNode();
    node6->val = 4;
    node4->left = node6;


    auto *s = new Solution();
    auto result = s->findDuplicateSubtrees(root);

    for ( const auto& v : result )
    {
        std::cout << "[";
        const vector<string> &vector = bfs(v);
        int idx = 1;
        for(const auto& x : vector) {
            std::cout << x ;
            if(idx == vector.size()) {

            }else{
                std::cout << "," ;
                idx++;
            }
        }

        std::cout << "]" << std::endl;
    }
}