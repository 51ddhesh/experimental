import pandas as pd
import matplotlib.pyplot as plt

binary_search_df = pd.read_csv("bs.csv")
linear_search_df = pd.read_csv("ls.csv")
threaded_ls_df = pd.read_csv("threaded_ls.csv")

plt.plot(binary_search_df['ip_size'], binary_search_df['time'], label='Binary Search')
plt.plot(linear_search_df['ip_size'], linear_search_df['time'], label='Linear Search')
plt.plot(threaded_ls_df['ip_size'], threaded_ls_df['time'], label='Multithreaded Linear Search')

average_time_ls = linear_search_df['time'].mean()
plt.axhline(y=average_time_ls, color='red', linestyle='--', label='Linear Search Average')
average_time_ls_threaded = threaded_ls_df['time'].mean()
plt.axhline(y=average_time_ls_threaded, color='black', linestyle='--', label='Multithreaded Linear Search Average')

plt.xlabel('Input Size')
plt.ylabel('Time to Search')

plt.title('Just how much faster is binary search?')
plt.legend()

plt.savefig('plot.png')