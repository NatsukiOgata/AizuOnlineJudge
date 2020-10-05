# VPC - RUPC  2937

h,w = map(int,input().split())
a,b = map(int,input().split())

if h < a or w < b:
    print(h * w)
else:
    ha = h % a
    wb = w % b
    ans = ha * w + wb * h - ha * wb
    print(ans)
