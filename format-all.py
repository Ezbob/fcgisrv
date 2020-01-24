import pathlib
import os
from itertools import chain
from subprocess import call

root = pathlib.Path(__file__).absolute().parent

def get_files(files_dir):

    def file_constraints_holds(f):
        return f.endswith(".hpp") or f.endswith(".cpp") or f.endswith(".h")

    for prefix, _, files in os.walk(files_dir):
        p = pathlib.Path(prefix)
        for f in (f for f in files if file_constraints_holds(f)):
            yield str(p / f)

clanformat = [ 'clang-format', '-i' ]

for p in chain(get_files(root / "src"), get_files(root / "include")):
    clanformat.append(p)

call(clanformat)