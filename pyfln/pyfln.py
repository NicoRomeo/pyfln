import os
import numpy as np
from . import bccutils as bcc
from ._pyfln import fastlinks

def fastlinksArr(arr_list, filename="templinks.bcc", save_res=True, sparse=True):
    cert_name = filename + "_cert.txt"
    if filename[-4:] != ".bcc":
        filename += ".bcc"
    bcc.export_closed_BCC(filename, arr_list)
    fastlinks(filename, cert_name)
    links = bcc.readtxt_certificate(cert_name, sparse=sparse)
    if not save_res:
        os.remove(filename)
        os.remove(cert_name)
    return links