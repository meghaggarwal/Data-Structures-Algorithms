def cuboid_volume(l):
  if type(l) not in [int, float]:
    raise TypeError('Enter valid integer')
  return (l * l * l)