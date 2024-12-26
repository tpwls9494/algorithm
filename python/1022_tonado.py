import sys

# -3, -3, 2, 0
# 최초 시작 (0,0) 우측 시작
# 공백으로 구분
# -5000 <= r1,c1,r2,c2 <= 5000
# 0 <= r2 - r1 <= 49
# 0 <= c2 - c1 <= 4
tx = [1, 0 ,-1, 0]
ty = [0, -1, 0, 1]

input = sys.stdin.readline


map = [[]]
mx, my = 0, 0
cnt = 1
change = 0
change_cnt = 1
turn = 0
while 10000 * 10000:
    map[mx][my] = cnt
    cnt += 1
    mx = tx[change]
    my = ty[change]
    change += change_cnt
    if change == 4:
        change = 0
    if cnt % 2 == 1 & cnt > 1:
        change_cnt += 1