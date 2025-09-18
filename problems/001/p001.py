
def resolve(n1, n2, max):
  sum = 0
  for i in range(n1, max):
    if i % n1 == 0 or i % n2 == 0:
      sum += i
  return sum

def main():
  result = resolve(3, 5, 1000)
  print(f"Result={result}")

main()