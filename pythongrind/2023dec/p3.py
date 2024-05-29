import sys

input = sys.stdin.readline
def solve():
    N = int(input())
    init = list(map(int, input().split()))
    speed = list(map(int, input().split()))
    order = list(map(int, input().split()))
    #i'm going to assume this is not even really painful simulation
    #for a single pair we can probably find when the intervals open and close
    #we should create a class and map each value to it
    #okay lets say we do that and we know what order each is supposed to be in
    #also this is not even sorting
    #we look at it from the point of growth rates
    #its not too hard to figure out when an interval works over another
    #okay so sort by growth rates
    #we can then determine when one plant is larger thna another and will always be
    #
T = int(input())
for _ in range(T):
    solve()