def modCal(seq):
  seq.sort()
  print(seq)
  _count = 0
  _max_n = 0
  _res = 0
  for i in range(0, len(seq) - 1):
    if seq[i] == seq[i + 1]:
      _count+=1
      print(_count, seq[i])

 
    if _max_n < _count:
      _res = seq[i]
      _max_n = _count
      _count = 0

  return _res


print( modCal([1,9,9,4,6,2,1,9]) )




