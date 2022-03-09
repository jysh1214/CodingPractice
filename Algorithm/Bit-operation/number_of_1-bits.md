# the number of 1-bits set in an int x

1. unsigned only
    ```c++
    int popcount(uint32_t n)
    {
        int ans = 0;
        while(n) {
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
    ```

2. 
    ```c++
    int popcount(int n)
    {
        int ans = 0;
        while(n) {
            n &= (n - 1);
            ++ans;
        }
        return ans;
    }
    ```

3. 
    ```c++
    int popcount(int n)
    {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
        n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
        n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
        return n;
    }
    ```