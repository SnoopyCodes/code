import sys
zz, zzi = [], -1
def istr():
    global zzi, zz
    zzi += 1
    if zzi == len(zz): zz, zzi = sys.stdin.readline().split(), 0
    return zz[zzi]
def iint(): return int(istr())