#! usr/bin/env python3
import sys
from haversine import haversine

def main():
	out = []
	for i in sys.stdin:
		tmp = i.strip().split()
		out.append((tmp[-4], float(tmp[-2]), float(tmp[-1])))
	for i in out:
		print(i[0], i[1], i[2], haversine((53.38195, -6.59192), (i[1], i[2])))

if __name__ == "__main__":
	main()