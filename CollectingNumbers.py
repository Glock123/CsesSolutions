from collections import defaultdict
import math

class ReadLine:
    def __init__(self, from_file):
        self.from_file = from_file

        if from_file:
            self.init_file_obj()

    def init_file_obj(self):
        if self.from_file:
            self.file_obj = open('inp.txt')
    
    def read_line(self):
        if self.from_file:
            return self.file_obj.readline()
        else:
            return input()
    
    def destroy_file_obj(self):
        if self.from_file:
            self.file_obj.close()


def array(s):
    return list(map(int, s.split()))

def integer(s):
    return int(s)

def float(s):
    return float(s)

def solve():
    global inp
    n = integer(inp.read_line())
    arr = array(inp.read_line())

    store = set()
    left = []
    for ele in arr:
        if ele != n: 
            if ele+1 in store:
                left.append(1)
            else:
                left.append(0)
        store.add(ele)
    print(sum(left)+1)
            
      
    pass

if __name__ == '__main__':
    global inp
    inp = ReadLine(False)
    solve()
    inp.destroy_file_obj()

