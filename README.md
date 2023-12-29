# Evaluation 1 – Data Structures Laboratory
## Computer Engineering / CEFET-MG
### Rhuan Lucas Barbosa Fernandes

This assessment focused on the size of squares as the primary attribute. In the ordered list, the square's size was used to place it in the appropriate location during insertion; during searches, the size was used to find the corresponding square.

### 1. Insertion
To insert 1000 squares in ascending (2), descending (4), and random (5) order into sequential, ordered, and linked lists, respectively, the following comparisons and assignments were recorded:

| Case | Sequential | Ordered | Linked |
|------|------------|---------|--------|
| 2-a  | 3,000      | 1,003,000 | 501,501 |
| 2-b  | 3,000      | 1,003,000 | 501,501 |
| 2-c  | 3,000      | 757,351 | 501,501 |

Comparisons and assignments were recorded for each insertion case.

### 2. Search
Repeated searches were performed for the same square in sequential, ordered, and linked lists. Comparisons and assignments for different side lengths were recorded.

#### Lists in Ascending Order:

| Side Length | Sequential | Ordered | Linked |
|-------------|------------|---------|--------|
| 1           | 404        | 4,646   | 303    |
| 1001        | 505        | 9,797   | 202,505 |
| 500         | 152,106    | 14,948  | 303,606 |
| 1000        | 455,207    | 19,594  | 505,707 |

#### Lists in Descending Order:

| Side Length | Sequential | Ordered | Linked |
|-------------|------------|---------|--------|
| 1           | 455,611    | 24,240  | 506,010 |
| 1001        | 455,712    | 29,391  | 708,212 |
| 500         | 607,313    | 34,542  | 809,313 |
| 1000        | 910,414    | 39,188  | 1,011,414 |

#### Lists in Random Order:

| Side Length | Sequential | Ordered | Linked |
|-------------|------------|---------|--------|
| 1           | 272,498    | 4,646   | 181,699 |
| 1001        | 272,599    | 9,797   | 202,505 |
| 500         | 370,266    | 14,948  | 449,046 |
| 1000        | 415,211    | 19,594  | 479,043 |

### Considerations
The insertion results indicate that the sequential list outperforms in terms of comparisons and assignments for all three sorting types. This is due to its capability to insert at the end of the list, checking only if the list is full before adding the square. Meanwhile, the ordered list inserts all squares in ascending order, and the linked list traverses the entire list to find the last element for insertion, resulting in higher computational cost.

Searches revealed a significant difference between the ordered list and the other two. Binary search in the ordered list reduces the search size by half with each iteration, resulting in O(log(n)) complexity in the worst-case scenario, while searches in the sequential and linked lists traverse the entire list, generating a much higher computational cost.

Regarding the suitability of lists in different scenarios, the sequential list is more efficient when elements sought are at the beginning of the list due to its advantageous insertion and low search cost in this context. The ordered list shines when the sought element is in the middle as its insertion is costly, but the search divides the list in half, resulting in a low cost to find the square.

The linked list does not exhibit superior performance to the other two for this specific case but is better for inserting and removing elements in the middle of the list since it's a dynamic structure, minimizing the cost of these operations.

These findings help identify the most suitable list type for different situations, considering their insertion and search characteristics.
