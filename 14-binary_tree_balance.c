#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
    size_t left = 0, right = 0;

    if (!tree)
        return (0);

    if (tree->left)
        left = 1 + tree_height(tree->left);
    if (tree->right)
        right = 1 + tree_height(tree->right);

    return ((left > right) ? left : right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left_h = 0, right_h = 0;

    if (!tree)
        return (0);

    if (tree->left)
        left_h = 1 + tree_height(tree->left);

    if (tree->right)
        right_h = 1 + tree_height(tree->right);

    return (left_h - right_h);
}
