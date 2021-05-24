/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

void display(TreeNode *root) {
    if(root == NULL) return;
    
    if(root->left)
        cout << root->left->val << " ";
    else 
        cout << "NULL";
    
    cout << " <- " << root -> val << " -> ";
    
     if(root->right)
        cout << root->right->val << " ";
    else 
        cout << "NULL \n";
    
    display(root->left);
    display(root->right);
    return;
}

int sizeofbt(TreeNode *root) { // sizeofbt = no. of nodes 
    if(root == NULL) return 0;
    
    int ls = sizeofbt(root->left);
    int rs = sizeofbt(root->right);
    return 1 + ls + rs;
}

int sumofbt(TreeNode *root) { // sumofbt = sum of all nodes

    if(root == NULL) return 0;
    
    int ls = sumofbt(root->left);
    int rs = sumofbt(root->right);
    return root->val + ls + rs;
}

int findheight(TreeNode *root) {
    if(root == NULL) return 0;
    
    int lh = findheight(root->left);
    int rh = findheight(root->right);
    
    return 1 + max(lh,rh);
}

int findmaxele(TreeNode* root) {
    if(root == NULL) return -1;
    
    int max1 = findmaxele(root->left);
    int max2 = findmaxele(root->right);
    
    int maxlr = max(max1,max2);
    if(root->val > maxlr)
        return root->val;
    return maxlr;
}

void preorder(TreeNode* root) {
    if(root == NULL) return ;
    
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if(root == NULL) return ;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if(root == NULL) return ;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void levelorder(TreeNode *root) {
    if(root == NULL) return;
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if(curr == NULL)
        {
            if(q.empty())
                break;
            cout << endl;
            q.push(NULL);
        }
        else 
        {
            cout << curr->val << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr ->right);
        }
    }
}

void iterativePrePostInorder(TreeNode *root) {
    if(root == NULL) return;
    
    vector<int> pre,post,invec;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
   
    while(!st.empty())
    {
        pair<TreeNode*,int> temp = st.top();
        if(temp.second == 1)
        {
            pre.push_back(temp.first->val);
            temp.second++;
            st.pop();
            st.push(temp);
            if(temp.first->left)
                st.push({temp.first->left, 1});
        }
        else if(temp.second == 2)
        {
            invec.push_back(temp.first->val);
            temp.second++;
            st.pop();
            st.push(temp);
            if(temp.first->right)
                st.push({temp.first->right, 1});
        }
        else if(temp.second == 3)
        {
            post.push_back(temp.first->val);
            st.pop();
        }
    }
//     cout << "Inorder = " ;
//     for(auto x : invec)
//         cout << x << " ";
    
//     cout << "\nPostorder = " ;
//     for(auto x : post)
//         cout << x << " ";
    
//     cout << "\nPreorder = " ;
//     for(auto x : pre)
//         cout << x << " ";
    
}

bool nodetorootpath(TreeNode *root, int key, vector<int> &path) {
    if(root == NULL) return false;
    path.push_back(root->val);
    if(root->val == key) return true;
    
    if(nodetorootpath(root->left,key,path) || nodetorootpath(root->right,key,path))
        return true;
    
    path.pop_back();
    return false;
}

void printatklevel(TreeNode *root, int k) {
    if(root == NULL) return ;
    if(k == 0) 
    {
        cout << root->val;
        return;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if(curr == NULL)
        {
            k--;
            if(q.empty())
                break;
            cout << endl;
            q.push(NULL);
        }
        else 
        {
            if(k == 0)
                cout << curr -> val << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr ->right);
        }
    }
}

bool nodetorootpath2(TreeNode *root, int key, vector<TreeNode*> &path) {
    if(root == NULL) return false;
    path.push_back(root);
    if(root->val == key) return true;
    
    if(nodetorootpath2(root->left,key,path) || nodetorootpath2(root->right,key,path))
        return true;
    
    path.pop_back();
    return false;
}

void printnodeatk(TreeNode *root, int key, int k) {
    if(root == NULL) return ;
    
    vector<TreeNode*> path1;
    if(nodetorootpath2(root,key,path1))
    {
        reverse(path1.begin(),path1.end());
        cout << "Path exist! : ";
        for(auto x : path1)
            cout << x->val << " -> ";
        int i = 0;
        while(k>=0)
        {
            printatklevel(path1[i], k);
            i++;
            k--;
        }
    }
    else 
        cout << "Path doesn't exist!";
    
}


// psi = postorder starting idx 
// pei = postorder end index
// isi = inorder start idx
// iei = inorder end idx
TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder, int psi, int pei, int isi, int iei) {
    if(pei < psi || iei < isi) return NULL;
    TreeNode *root = new TreeNode(preorder[psi]);
    int tempidx = isi ;
    
    while(inorder[tempidx] != preorder[psi])
        tempidx++;
    
    int countlse = tempidx - isi ;
    
    root->left = buildtree(preorder,inorder,psi+1, psi + countlse, isi , tempidx - 1);
    root->right = buildtree(preorder, inorder, psi + countlse + 1, pei, tempidx + 1, iei);
    
    return root;
}



int main() {
    string line;
    while (getline(cin, line)) 
    {
        TreeNode* root = stringToTreeNode(line);
        prettyPrintTree(root);
        cout << findheight(root) << endl;
        display(root);
        // cout << "No of nodes = " << sizeofbt(root) << endl;
        // cout << "Sum of nodes = " << sumofbt(root) << endl;
        // cout << "Height of Binary Tree = " << findheight(root) << endl;
        // cout << "Max ele = " <<  findmaxele(root) << endl;
        // cout << "Preorder = " ;
        // preorder(root);
        // cout << "\n Postorder = ";
        // postorder(root);
        // cout << "\n Inorder = ";
        // inorder(root);
        // levelorder(root);
        // iterativePrePostInorder(root);
        // vector<int> path;
        // if(nodetorootpath(root,70,path))
        // {
        //     reverse(path.begin(),path.end());
        //     cout << "Path exist! : ";
        //     for(auto x : path)
        //         cout << x << " -> ";
        // }
        // else 
        //     cout << "Path doesn't exist!";
        
        // printatklevel(root,2);
        // printnodeatk(root,37,2);
    }
    
    return 0;
}