# Formulation of the problem 
Only integers are input that are representable using the 64-bit integer signed data type. Due to the difficulty of the task, 
we assume that the largest prime number in the prime factorization is less than 106. To make your algorithm efficient for 
repeated calls, precompute the table of all prime numbers up to 106 with the Sieve of Eratosthenes algorithm. Subsequently, 
it is possible to try division only with found prime numbers and thus significantly speed up the calculation. Therefore, it 
is necessary to store the found prime numbers in a separate field, so that it is not necessary to always go through the entire Sieve of Eratosthenes.
