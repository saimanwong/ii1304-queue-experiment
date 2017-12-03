from random import randint
import sys

def key(i):
    return i[1]

a = []
n = int(sys.argv[1])
filepath = sys.argv[2]
for i in range(0, n):
    a.append([i, randint(0,40)])

b = sorted(a, key=key)

fa = open(filepath + "/test_correctness.in","w") 
fb = open(filepath + "/test_correctness.out","w") 

for i in range(0, n):
    temp = str(a[i][0]) + " " + str(a[i][1])
    fa.write(temp + "\n") 
    temp = str(b[i][0]) + " " + str(b[i][1])
    fb.write(temp + "\n")

fa.close() 
fb.close() 
