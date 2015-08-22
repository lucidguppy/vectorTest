#! /usr/bin/env python

import pandas as pd
import matplotlib.pyplot as plt
import matplotlib
matplotlib.style.use('ggplot')
df = pd.read_csv('data.csv')

plt.figure()

#df.hist(bins=30)
df.plot(widths=0.8, notch=False, kind='box', sym='r+')

plt.show()

