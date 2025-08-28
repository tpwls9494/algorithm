import heapq
import sys
input = sys.stdin.readline
n = int(input())
num_list = []
for i in range(n):
    expression = int(input())
    if expression == 0:
            print(0)
            continue
        print(-heapq.heappop(num_list))
    else:
        heapq.heappush(num_list, -expression)