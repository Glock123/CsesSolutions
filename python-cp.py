from collections import defaultdict

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

inp = ReadLine(False)
t = integer(inp.read_line())

for _ in range(t):
    n, q = array(inp.read_line())
    x = array(inp.read_line())

    pre_sum = [0]*n
    pre_sum[0] = x[0]
    for i, num in enumerate(x[1:]):
        pre_sum[i+1] = pre_sum[i] + num
    # print(pre_sum)
    for _ in range(q):
        l, r, k = array(inp.read_line())
        sum = (0 if l==1 else pre_sum[l-2]) + (r-l+1)*k + (0 if r==n else pre_sum[n-1]-pre_sum[r-1])
        # print(sum, end=': ')
        if sum%2==0:
            print('NO')
        else:
            print('YES')

inp.destroy_file_obj()
