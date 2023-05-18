""" Root module of pyfln"""
try:
    from ._pyfln import fastlinks
    from .pyfln import fastlinksArr
except ImportError:
    print("Fast methods unavailable.")