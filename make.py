import sys
from subprocess import Popen

cmd = f'gcc main2.c'
r = Popen(cmd, shell=True)
print(r.returncode)