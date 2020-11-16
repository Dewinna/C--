1. Instructions: 
	-After unzipping the file into a new folder, use the command prompt and change directory to the folders file path.
	-To compile the program into an executable, use the command: g++ -o program HW1.cpp
		>"program" can be named anything, but make sure it starts with a letter after 'H' to ensure the file order 
	-Once compiled, you can run the program using the command: .\program <algorithm_name> <space_separated_input>
		>where:
			algorithm_name can take one of the following values:
				- bfs : For running the Breadth-first search algorithm
				- ids : For running the Iterative deepening search algorithm
				- astar1 : For running the A* algorithm with heuristic 1.
				- astar2 : For running the A* algorithm with heuristic 2.
			space_separated_input is the input sequence for the 8-puzzle problem.
			Example: * 1 3 4 2 5 7 8 6

2.Sample input: .\program ids * 1 3 4 2 5 7 8 6
  Sample Output:* 1 3
		4 2 5
		7 8 6

		1 * 3
		4 2 5
		7 8 6

		1 2 3
		4 * 5
		7 8 6

		1 2 3
		4 5 *
		7 8 6

		1 2 3
		4 5 6
		7 8 *


		Moves: 4
		Enqueued: 692

('*' gets processed as the files in the folder you're running the .exe from, as long as the .exe is named something starting with a 
letter after 'H', the program should handle this. In case it doesn't, using '0' in place of '*' ought to work and run more quickly.)

3. Analysis: While I'm aware of the slides show that heuristic 2 dominates heuristic 1, all of the <10 move boards I thought 
to try performed equally. This is likely because I only thought of more simplistic paths where each finds the correct move first 
try. 
Example:
.\program astar1 * 1 2 5 6 3 4 7 8
and 
.\program astar2 * 1 2 5 6 3 4 7 8
Both output: 
* 1 2
5 6 3
4 7 8

1 * 2
5 6 3
4 7 8

1 2 *
5 6 3
4 7 8

1 2 3
5 6 *
4 7 8

1 2 3
5 * 6
4 7 8

1 2 3
* 5 6
4 7 8

1 2 3
4 5 6
* 7 8

1 2 3
4 5 6
7 * 8

1 2 3
4 5 6
7 8 *


Moves: 8
Enqueued: 23

NOTES:
1. I could not connect to the cs2 server to test this, but took great care in making sure that the program handles inputs correctly even in the raw console. 
	Used the VPN and tried to connect to giant, but it wasn't recognized as a host, also tried the public ssh host and succesfully connected, but couldn't get into cs2 once in the general SSH server (May have been DUO not returning my 2 factor authentication method in time)
2. My "queue" in IDS is the number of nodes traversed, for the rest it is the TOTAL number of nodes ENQUEUED, whether they're later visited or not. I suspect my values are slightly larger than in the examples because of this, 
	but the homework doesn't specify to measure performance in the same way and I find this to be a better measurement for the total cost of the algorithm finding the correct path.