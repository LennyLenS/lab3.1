import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

d: dict[str, list] = {}
sortes = list();
with open("result.csv", "r") as f:
    
    for line in f:
        if len(sortes) == 0:
            sortes = list(line[:-1].split(';'))
            for i in sortes:
                d[i] = list()
        else:
            # print(line)
            li = list(line[:-1].split(' '))
            k = 0
            for i in sortes:
                d[i].append(li[k])
                k += 1
x = d['size']
d.pop('size')
for srt, time in d.items():
    plt.plot(x, time, label=srt)

plt.xticks(np.arange(int(x[0]), int(x[-1]), 200), fontsize=14)
plt.xlabel('sequence size')
plt.ylabel('time - ms')
plt.legend(loc='upper left')
plt.savefig("result.png")


