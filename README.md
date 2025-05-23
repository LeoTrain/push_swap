# push_swap
Push Swap is an algorithmic sorting challenge, commonly part of the 42 School curriculum, where the goal is to sort a list of integers using two stacks (a and b) and a limited set of operations.

## Algorithm
---

### **Code**
```c
int position;
int size;

while (*tab_a)
{
    // 1. Get the position of the lowest value
    position = find_position_of_lowest(*tab_a);
    size = ft_lstsize(*tab_a);

    // 2. Rotate optimally to bring the lowest to the top
    if (position <= size / 2)
    {
        // Rotate upwards
        while (position-- > 0)
            rotate(tab_a, 1);  // or ra
    }
    else
    {
        // Rotate downwards
        position = size - position;
        while (position-- > 0)
            rotate_reverse(tab_a, 1);  // or rra
    }

    // 3. Push the lowest value to tab_b
    push(tab_a, tab_b, 1);  // or pb
}
```

---

### **Steps**:

1. **Find the lowest value** in `tab_a` and get its **position**.
2. Determine the **optimal direction** to rotate:
   * If it’s in the **first half** of the list → use `rotate()`.
   * If it’s in the **second half** → use `rotate_reverse()`.
4. **Push** the value to `tab_b`.
