#! usr/bin/env python3
import sys

def main():
	out = []
	for i in sys.stdin:
		tmp = i.strip().split()
		out.append((tmp[-4], float(tmp[-2]), float(tmp[-1])))
	for i in out:
		print(i[1], i[2], i[0])

if __name__ == "__main__":
	main()