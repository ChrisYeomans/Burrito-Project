#! usr/bin/env python3
import sys, os

def main():
	for i in range(100):
		os.system("echo "+str(i)+" > num.txt")
		os.system("cat num.txt cleaned_list.txt > comb.txt")
		os.system("./a.out < comb.txt > basic.txt")
		os.system("./calc < basic.txt > tmp.txt")
		os.system("cat tmp.txt max.txt > tmp2.txt")
		os.system("cat tmp2.txt > max.txt")

if __name__ == "__main__":
	main()