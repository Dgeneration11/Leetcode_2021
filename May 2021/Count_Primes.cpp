class Solution {
public:
    int countPrimes(int n) {
        if (n == 0)
            return 0;
        bool prime [n];
        memset (prime, true, sizeof (prime));
        for (int i = 2; i*i < n; i++) {
            if (prime [i] == true) { 
				// Update all multiples of i to false if i is prime
                for (int j = i * i; j < n; j += i)
                    prime [j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime [i])
                count++;
        }
        return count;
    }
};