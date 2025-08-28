import heapq
a, b = map(int, input().split())
num_list = []
for i in range(a):
    heapq.heappush(num_list, -int(input()))

for i in range(b-a):
    n = heapq.heappop(num_list)
    n //= 2
    heapq.heappush(num_list, n)
    heapq.heappush(num_list, n)
    print(num_list)
print(-num_list[b-1])