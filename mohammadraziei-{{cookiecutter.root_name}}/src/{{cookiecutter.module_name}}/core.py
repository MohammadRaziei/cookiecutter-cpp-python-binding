#!/bin/python3
from __future__ import annotations

import warnings
from pathlib import Path


from ._core import __doc__, __version__

def warning_on_one_line(message, category, filename, lineno, file=None, line=None):
    return f'{filename}:{lineno}: {category.__name__}: {message}\n'


warnings.formatwarning = warning_on_one_line
