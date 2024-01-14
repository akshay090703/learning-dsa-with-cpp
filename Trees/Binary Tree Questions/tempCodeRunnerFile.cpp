int heightOfBT(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);

    return max(leftHeight, rightHeight) + 1;
}