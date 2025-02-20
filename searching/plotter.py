import pandas as pd
import matplotlib.pyplot as plt

binary_search_df = pd.read_csv("bs.csv")
linear_search_df = pd.read_csv("ls.csv")

plt.plot(binary_search_df['ip_size'], binary_search_df['time'], label='Binary Search')
plt.plot(linear_search_df['ip_size'], linear_search_df['time'], label='Linear Search')

average_time_ls = linear_search_df['time'].mean()
plt.axhline(y=average_time_ls, color='red', linestyle='--', label='Linear Search Average')


plt.xlabel('Input Size')
plt.ylabel('Time to Search')

plt.title('Just how much faster is binary search?')
plt.legend()

plt.savefig('plot.png')