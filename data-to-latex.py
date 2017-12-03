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

bestE = []
avgE = []
worstE = []

bestD = []
avgD = []
worstD = []

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
                if (counter % 6 == 0):
                    bestE.append(float(temp[6]))
                elif (counter % 6 == 1):
                    bestD.append(float(temp[6]))
                elif (counter % 6 == 2):
                    avgE.append(float(temp[6]))
                elif (counter % 6 == 3):
                    avgD.append(float(temp[6]))
                elif (counter % 6 == 4):
                    worstE.append(float(temp[6]))
                else:
                    worstD.append(float(temp[6]))
                counter += 1

        temp_path = "results/"
        tot_elements = path_array[len(path_array) - 1]
        name = ""
        be = "best_enqueue"
        bd = "best_dequeue"
        ae = "avg_enqueue"
        ad = "avg_dequeue"
        we = "worst_enqueue"
        wd = "worst_dequeue"

        for i in range(0, len(path_array)-1):
            name += path_array[i] + "_"

        write_array = []
        write_array.append(tot_elements + " " + str(numpy.mean(bestE)) + " " + str(numpy.std(bestE)) + '\n')
        write_array.append(tot_elements + " " + str(numpy.mean(bestD)) + " " + str(numpy.std(bestD)) + '\n')
        write_array.append(tot_elements + " " + str(numpy.mean(avgE)) + " " + str(numpy.std(avgE)) + '\n')
        write_array.append(tot_elements + " " + str(numpy.mean(avgD)) + " " + str(numpy.std(avgD)) + '\n')
        write_array.append(tot_elements + " " + str(numpy.mean(worstE)) + " " + str(numpy.std(worstE)) + '\n')
        write_array.append(tot_elements + " " + str(numpy.mean(worstD)) + " " + str(numpy.std(worstD)) + '\n')


        for i in range(0,6):
            x = temp_path + name
            if (i == 0):
                x += be + ".dat"
            elif (i == 1):
                x += bd + ".dat"
            elif (i == 2):
                x += ae + ".dat"
            elif (i == 3):
                x += ad + ".dat"
            elif (i == 4):
                x += we + ".dat"
            elif (i == 5):
                x += wd + ".dat"

            f = open(x, 'a')
            f.write(write_array[i])
            f.close

            x = ""

        write_array = []
        bestE = []
        bestD = []
        avgE = []
        avgD = []
        worstE = []
        worstD = []
        continue
    else:
        continue
