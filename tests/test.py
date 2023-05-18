""" Test file """

import numpy as np
import pyfln # requires package to be built and installed

def test_links():
    s = np.linspace(0, 2*np.pi)
    a = np.array([np.cos(s), np.sin(s), np.zeros_like(s)]).T
    b = np.array([np.cos(s)+3./2., np.zeros_like(s), np.sin(s)]).T
    c = np.array([np.cos(s)-3./2., np.zeros_like(s), np.sin(s)]).T
    list_arr = [a, b,c]
    lnks = pyfln.fastlinksArr(list_arr, save_res=False, sparse=False)
    assert (lnks == np.array([[0,0,0],[-1,0,0],[1,0,0]])).all()
