#include <iostream>

/*

The main idea here is to find actual unique binary tree from the given PREORDER, INORDER and POSTORDER

Why One Traversal Alone is Not Enough?

*) Preorder: [A, B, D, E, C, F]

This only tells us:
- Root: A
- Then B, D, E, C, F in preorder fashion

But structure is ambiguous.
Possible Trees:
1)
    A
   / \
  B   C
 / \   \
D   E   F

2)
    A
   /
  B
   \
    C
   / \
  D   E
      \
       F

Both have same preorder, but are structurally different.
So, we can't uniquely build the tree.

*) Inorder: [D, B, E, A, F, C]

This only tells us:
- Left-to-right sequence of nodes
- We don’t know which one is root!

Many tree structures can give this inorder traversal.

So, not enough.

*) Postorder: [D, E, B, F, C, A]

Last node is root: A
But again, rest is ambiguous.

Many trees have the same postorder, so:
Not enough info to reconstruct the structure

*************************** SOLUTION FOR THAT CASE ***************************

    1) INORDER + PREORDER

Inorder:   [D, B, E, A, F, C]
Preorder:  [A, B, D, E, C, F]

Step 1:
- Preorder tells us: Root = A
- Find A in inorder → index 3

Split inorder:
- Left Subtree Inorder: [D, B, E]
- Right Subtree Inorder: [F, C]

Now continue on each subtree...

---

LEFT SUBTREE:
Preorder: [B, D, E]
Inorder:  [D, B, E]

→ Root = B (from preorder)
→ Find B in inorder → index 1

Split:
- Left: [D]
- Right: [E]

Subtrees:
- Left Preorder: [D]
- Right Preorder: [E]

B’s children:
    B
   / \
  D   E

---

RIGHT SUBTREE:
Preorder: [C, F]
Inorder:  [F, C]

→ Root = C
→ Find C in inorder → index 1

Split:
- Left: [F]
- Right: []

C’s children:
- Left Preorder: [F]
- Right Preorder: []

    C
   /
  F

---

Final Tree Structure from Inorder + Preorder:

        A
       / \
      B   C
     / \  /
    D  E F

    2) INORDER + POSTORDER

Inorder:   [D, B, E, A, F, C]
Postorder: [D, E, B, F, C, A]

Step 1:
- Postorder: Last = A → root
- Find A in inorder → index 3

Split inorder:
- Left: [D, B, E]
- Right: [F, C]

Split postorder:
- Left Subtree Postorder: [D, E, B]
- Right Subtree Postorder: [F, C]

---

LEFT SUBTREE:
Postorder: [D, E, B]
Inorder:   [D, B, E]

→ Last in postorder: B → root
→ Find B in inorder → index 1

Split:
- Left: [D] → Postorder: [D]
- Right: [E] → Postorder: [E]

B’s children:
    B
   / \
  D   E

---

RIGHT SUBTREE:
Postorder: [F, C]
Inorder:   [F, C]

→ Last in postorder: C → root
→ Find C in inorder → index 1

Split:
- Left: [F] → Postorder: [F]
- Right: [] → Postorder: []

C’s children:
    C
   /
  F

---

Final Tree Structure from Inorder + Postorder:

        A
       / \
      B   C
     / \  /
    D  E F
*/




int main()
{
    return 0;
}