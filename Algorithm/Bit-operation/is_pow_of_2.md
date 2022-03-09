# is pow of two

```c++
bool isPowOfTwo(int n)
{
    return n & (n - 1) == 0;
}
```