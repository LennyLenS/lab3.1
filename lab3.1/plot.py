import matplotlib.pyplot as plt
from matplotlib.ticker import *

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
                d[i].append(float(li[k]))
                k += 1
x = d['size']
d.pop('size')

fig = plt.figure(figsize = (15, 15))
arr = list()
if len(d) == 1:
    arr.append(fig.subplots(len(d)))
else:
    arr = list(fig.subplots(len(d)))

j = 0
for srt, time in d.items():
    arr[j].plot(x, time)
    #arr[j].xaxis.set_major_locator(LinearLocator(5))
    #arr[j].yaxis.set_major_locator(LinearLocator(5))
    arr[j].set_ylabel('time - ms', fontsize = 14)
    arr[j].set_title(srt)
    j += 1


#ax.set_xticklabels([])
plt.xlabel("size", fontsize = 20)
#plt.legend(loc='upper left')
plt.savefig("result.png")


