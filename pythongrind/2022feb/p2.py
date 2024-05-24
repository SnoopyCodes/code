import sys

input = sys.stdin.readline

N = int(input())
now = list(map(int, input().split()))
prefs = list(map(int, input().split()))
#oh we can only move one direction
#okay
#uhhhhhhhh
#okay then
#we should just move those that need to be moved the furthest left first
#is it just those that need to move to the left?
#it shouldnt be because 
#1 2 3 4 5
#1 4 3 2 5
#here if we move 4 to 2 we end up
#1 4 2 3 5
#we can try building it from desired point of view isn't that a lot easier
#why'm i running around like a headless chicken
#good question good problem
#but then how do we consider swapping it and everything
#also this is basically sorting!
#rebind
#5 1 3 2 4
#4 5 2 1 3
#analogous to 
#1 3 4 2 0
#0 1 2 3 4
#is it clear from there how to do it?
#it's stupid that they allowed last 4 tc for N^2 bruh wtf
#actual brain damage
#wait so for this we can also then mark on each one how many are going to go across it
#okay but what about O(N)
#very simple observation im actualy brain damaged
for i in range(N):
    #help