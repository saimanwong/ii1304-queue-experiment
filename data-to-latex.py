import numpy
import os
import re
import sys

directory = sys.argv[1]

_nsre = re.compile('([0-9]+)')
def natural_sort_key(s):
        return [int(text) if text.isdigit() else text.lower()
                            for text in re.split(_nsre, s)]

p = []

lst = []

best = []
avg = []
worst = []

counter = 0


for filename in os.listdir(directory):
    p.append(filename)

p.sort(key=natural_sort_key)

for filename in p:
    if filename.endswith(".dat"):
        path = os.path.join(directory, filename)
        path_array = path.replace(directory + "/","").replace(".dat","").split("_")

        with open (path) as f:
            for line in f:
                temp = line.split()
                if (counter % 3 == 0):
                    best.append(float(temp[1]))
                elif (counter % 3 == 1):
                    avg.append(float(temp[1]))
                else:
                    worst.append(float(temp[1]))
                counter += 1

        temp_path = "results/"
        name = ""

        for i in range(0, len(path_array)-1):
            name += path_array[i] + "_"

        name += path_array[len(path_array) - 1]
        temp_path += name + ".dat"

        print(temp_path)

        # temp_path = "results/" + path_array[0] + "_" + path_array[1] + ".dat"

        text0 = "best " + str(numpy.mean(best)) + " " + str(numpy.std(best)) + '\n'
        text1 = "average " + str(numpy.mean(avg)) + " " + str(numpy.std(avg)) + '\n'
        text2 = "worst " + str(numpy.mean(worst)) + " " + str(numpy.std(worst)) + '\n'
        f = open(temp_path, 'a')
        f.write(text0 + text1 + text2)
        f.close
        best = []
        avg = []
        worst = []
        continue
    else:
        continue
