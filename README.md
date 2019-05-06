# Burrito-Project

The final solution is:
64,38,67,42,48,21,3,92,80,93,28,88,99,17,44,36,75,33,45,47,82,89,24,11,20,30,35,78,9,61,53,74,37,62,19,52,27,12,81,51,1,54,16,49,34,85,23,26,31,86,68,94,55,69,63,2,39,91,76,0,72,5,40,83,43,98,60,65,18,66,10,87,14,96,50,29,25,41,7,90,59,22,15,70,6,77,84,56,73,8,58,32,97,57,46,71,79,4,95,13
With a score of 1405.46
This was achieved with search_nearest_smart.cpp which implements a basic greedy algorithm based on distance but is a bit smarter about it and tries to not go to nodes that havent expired yet, i.e. avoid nodes which are not generating score yet as to use your time more efficiently.
There is a multiplier in the if on line 38 which was obtained with the use of test.cpp which is a modified version of search_nearest_smart.cpp and run_test.py which just runs test.cpp with different values of that multiplier and then I inspected which was the best one and hard-coded it into search_nearest_smart.cpp.
When using just the greedy algorithm you get a very similar score of 1410 which is quite good and very easy to implement, this is contained in the file search_nearest.cpp.
One ideas that was surprisingly bad was the priority queue based on time which had a score of about 16000, it is in the file search_time_prior.cpp.
The header files burrito_extras.h and calc_score.h are essential to the running of the programmes.
Note: cleaned_list.txt needs to be piped into the c++ files for input, i.e. file_name.cpp < cleaned_list.txt