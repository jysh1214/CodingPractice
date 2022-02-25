# preorder

```c++
void preorder(TreeNode* root)
{
    visit(root);
    preorder(root->left);
    preorder(root->right);
}
```

# preorder

```c++
void inorder(TreeNode* root)
{
    inorder(root->left);
    visit(root);
    inorder(root->right);
}
```

# postorder

```c++
void inorder(TreeNode* root)
{
    inorder(root->left);
    inorder(root->right);
    visit(root);
}
```