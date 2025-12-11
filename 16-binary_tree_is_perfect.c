#include "binary_trees.h"

/**
 * depth - Measures the depth of the leftmost leaf
 * @tree: pointer to root
 * Return: depth
 */
int depth(const binary_tree_t *tree)
{
    int d = 0;

    while (tree)
    {
        d++;
        tree = tree->left;
    }
    return (d);
}

/**
 * is_perfect_recursive - Checks if tree is perfect
 * @tree: pointer to tree root
 * @d: expected depth of all leaves
 * @level: current level
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int d, int level)
{
    if (!tree)
        return (1);

    /* If leaf */
    if (!tree->left && !tree->right)
        return (d == level + 1);

    /* If node has only one child → not perfect */
    if (!tree->left || !tree->right)
        return (0);

    return (is_perfect_recursive(tree->left, d, level + 1) &&
            is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a tree is perfect
 * @tree: pointer to tree root
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int d;

    if (!tree)
        return (0);

    d = depth(tree);
    return (is_perfect_recursive(tree, d, 0));
}
