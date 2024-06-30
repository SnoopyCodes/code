for _ in range(int(input())):
    n, k = map(int,input().split())
    a = list(map(int,input().split()))
    h = list(map(int,input().split()))
    ans = 0
 
    continuous = 1
    tot = a[0]
    l = 0
    i = 0
    while i < n:
        if (i+1 < n and h[i]%h[i+1] == 0):
            while (l <= i and tot + a[i+1] > k):
                tot -= a[l]
                continuous -= 1
                l += 1
            continuous += 1
            tot += a[i+1]
        else:
            ans = max(continuous if (tot <= k) else 0, ans)
            j = i+1
            while j < n and a[j] > k:
                j+=1
            if (j < n):
                tot = a[j]
                l = j
                continuous = 1
            else:
                continuous = 0
            i = j-1
        ans = max(continuous if (tot <= k) else 0, ans)
        i += 1
    print(ans)