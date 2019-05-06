#! usr/bin/env python3
import sys, os

def main():
    for i in range(17670, 18000):
    	os.system("echo 0.9"+str(i)+" > num.txt")
    	os.system("cat num.txt cleaned_list.txt > tmp.txt")
    	os.system("./a.out < tmp.txt 2> rip.txt")

if __name__ == "__main__":
    main()