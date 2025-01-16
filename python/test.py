# N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
# 첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.
# 입력으로 주어진 숫자 N개의 합을 출력

import sys

input = sys.stdin.readline

# num = input()

# sum = 0
# for i in range(N):
#     sum += int(num[i])
# print(sum)

# # 입출럭 중급 2
# N = int(input())
# data = [[0] * N] * N
# for i in range(N):
#     data[i] = list(map(int, input().split()))
# print(data)

# # 입출력 중급 1
# N, M = map(int, input().split())
# arr = list(map(int, input().split()))
# for i in range(N):
#     if arr[i] < M:
#         print(arr[i], end=" ")

# # 입출력 상급 1
# N, M = map(int, input().split())
# result = []

# for i in range(N):
#     sum= 0
#     mul = 1
#     li = list(map(int, input().split()))
#     for j in range(M):
#         if i % 2 == 0:
#             sum += li[j]
#         else:
#             mul *= li[j]

#     if i % 2 == 0:
#         result.append(sum)
#     else:
#         result.append(mul)
# print(result)

# # 입출력 상급 2
# N, M = map(int, input().split())
# result = []

# for i in range(N):
#     li = list(map(int, input().split()))
#     for j in range(M):
#         if li[j] % 2 == 0:
#             print(li[j], end=" ")
#     print()
# # 방법 2
# N, M = map(int, input().split())
# result = [list(map(int, input().split())) for _ in range(N)]
# for i in range(N):
#     for j in range(M):
#         if result[i][j] % 2 == 0:
#             print(result[i][j], end=" ")
#     print()

# 입출력 상급 3

# n = int(input())
# arr = []
# for i in range(n):
#     li = list(map(int, input().split()))
#     arr.append(li)

# for i in range(n):
#     for j in range(n):
#         print(arr[n-j-1][i], end=" ")
#     print()

# # 상급4
n, m = map(int, input().split())
# li = [[0] for ] * m
for i in range(m):
    a, b = map(int, input().split())
    li_ = [b]
    li.append(li_)
    li_ = [a]
    li.append(li_)
print(li)