#
# 비 내림차순
# p[a] >= p[a-1]
#
# 먼저 숫자를 낮은 순서로부터 차례대로 나타냄
# ex) 11114133
#  -> 11111334
#  -> 1234'5''
#  -> 1234'567
#  -> 12348567
#

import sys
input = sys.stdin.readline

N = int(input())

li = list(map(int, input().split()))
sort_li = sorted(li,reverse=False)
#sort_li = 43311111

ans = [0]*N

for i in range(N):
    ans[i] = sort_li.index(li[i])
    sort_li[sort_li.index(li[i])] = -1

for i in range(N):
    print(sort_li.index(li[i]))
    
print(*ans)

