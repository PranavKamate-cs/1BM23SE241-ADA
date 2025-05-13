import random

# Generate 1000 unique integers between 1 and 10000
nums = random.sample(range(1, 1001), 250)

# Print all on one line
print(" ".join(map(str, nums)))