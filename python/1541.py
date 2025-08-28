# a = input()
# sum = 0
# num = 0
# is_negative = False
# for i in range(len(a)):
#     if a[i] == '-' or a[i] == '+':
#         if is_negative == True:
#             sum -= num
#         else:
#             sum += num
#         num = 0
#     else:
#         num = int(a[i]) + num * 10
#     if a[i] == '-':
#         is_negative = True

# if is_negative == True:
#     print(sum - num)
# else:
#     print(sum + num)

# expression = input()
# parts = expression.split('-')
# result = sum(int(x) for x in parts[0].split('+'))
# for i in range(1, len(parts)):
#     result -= sum(int(x) for x in parts[i].split('+'))
# print(result)

import re
expression = input()
minus = expression.find('-')
if minus == -1:
    result = sum(int(x) for x in re.findall(r'\d+', expression))
else:
    first = expression[:minus]
    second = expression[minus + 1:]

    result = sum(int(x) for x in re.findall(r'\d+', first))
    result -= sum(int(x) for x in re.findall(r'\d+', second))
print(result)