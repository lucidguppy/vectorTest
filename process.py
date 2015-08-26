#! /usr/bin/env python

import pandas as pd
import matplotlib.pyplot as plt
import matplotlib
import sys
matplotlib.style.use('ggplot')
df = pd.read_csv(sys.argv[1])

#df.hist(bins=30)
ax = df.plot(widths=0.8, notch=False, kind='box', sym='r+')

if sys.argv[2] == "save":
    fig = ax.get_figure()
    fig.savefig(sys.argv[3])
else:    
    plt.show()
