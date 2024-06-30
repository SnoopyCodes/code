for _ in range(int(input())):
    n, x = map(int,input().split())
    a = list(map(int, input().split()))
 #i dont want this on my incomplete list
    def val(h):
        ret = 0 
        for i in range(n):
            ret += max(h-a[i],0)
        return ret
    
    lo, hi = 1, 2e9
    ans = 0
    while (lo <= hi):
        mid = (lo + hi)//2
        if (val(mid) > x):
            hi = mid-1
        else:
            lo = mid+1
            ans = mid
    print(int(ans))
 